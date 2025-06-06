#include "koopatoriscv.hpp"

int  getsize(const koopa_raw_type_t ty)
{
  switch (ty->tag) {
   
    case KOOPA_RTT_INT32:
      return 4;

    case KOOPA_RTT_UNIT:
      return 0;
    case KOOPA_RTT_POINTER:
      return 4;
    case KOOPA_RTT_ARRAY:
      return getsize(ty->data.array.base) * ty->data.array.len;
    default:
      
      assert(false);
  }
}

static Regmanager regmanager;

void koopa_dump(const char* str) {
  // 解析字符串 str, 得到 Koopa IR 程序
  koopa_program_t program;
  koopa_error_code_t ret = koopa_parse_from_string(str, &program);
  // 确保解析时没有出错
  assert(ret == KOOPA_EC_SUCCESS);
  // 创建一个 raw program builder, 用来构建 raw program
  koopa_raw_program_builder_t builder = koopa_new_raw_program_builder();
  // 将 Koopa IR 程序转换为 raw program
  koopa_raw_program_t raw = koopa_build_raw_program(builder, program);
  // 释放 Koopa IR 程序占用的内存
  koopa_delete_program(program);

  // 处理 raw program
  Visit(raw);

  // 处理完成, 释放 raw program builder 占用的内存
  // 注意, raw program 中所有的指针指向的内存均为 raw program builder 的内存
  // 所以不要在 raw program 处理完毕之前释放 builder
  koopa_delete_raw_program_builder(builder);
}

// 函数声明略
// ...

// 访问 raw program
void Visit(const koopa_raw_program_t &program) {
    // 执行一些其他的必要操作
    // ...
    // 访问所有全局变量
    std::cout<<"\t.data\n";
    Visit(program.values);
    // 访问所有函数
    std::cout<<"\t.text\n";
    Visit(program.funcs);
  }
  
  // 访问 raw slice
  void Visit(const koopa_raw_slice_t &slice) {
    for (size_t i = 0; i < slice.len; ++i) {
      auto ptr = slice.buffer[i];
      // 根据 slice 的 kind 决定将 ptr 视作何种元素
      switch (slice.kind) {
        case KOOPA_RSIK_FUNCTION:
          // 访问函数
          Visit(reinterpret_cast<koopa_raw_function_t>(ptr));
          break;
        case KOOPA_RSIK_BASIC_BLOCK:
          // 访问基本块
          Visit(reinterpret_cast<koopa_raw_basic_block_t>(ptr));
          break;
        case KOOPA_RSIK_VALUE:
          // 访问指令
          Visit(reinterpret_cast<koopa_raw_value_t>(ptr));
          break;
        default:
          // 我们暂时不会遇到其他内容, 于是不对其做任何处理
          std::cerr << "Unknown slice kind " << std::endl;
          assert(false);
      }
    }
  }
  
  // 访问函数
  void Visit(const koopa_raw_function_t &func) {
    // 执行一些其他的必要操作
    // ...
    // 访问所有基本块
    regmanager.init();

    if (func->bbs.len == 0) {
      return;
    }

    std::string func_name(func->name);
        func_name = func_name.substr(1);
    
    std::cout << "\t.globl " << func_name << "\n" << func_name << ":\n";
    int cnt = 0;
    int call_cnt = 0;
    int a = 0;
    for (size_t i = 0; i < func->bbs.len; ++i) {
      auto bb = reinterpret_cast<koopa_raw_basic_block_t>(func->bbs.buffer[i]);
      for (size_t j = 0; j < bb->insts.len; ++j) {
          auto inst = reinterpret_cast<koopa_raw_value_t>(bb->insts.buffer[j]);
          if (inst->ty->tag != KOOPA_RTT_UNIT) {
              ++cnt;
          }

          if(inst->kind.tag == KOOPA_RVT_CALL)
          {
            int numa =  inst->kind.data.call.args.len;
            call_cnt = max(call_cnt,numa-8);
            a=1;
          }
          if (inst->kind.tag == KOOPA_RVT_ALLOC) {
            int size = getsize(inst->ty->data.pointer.base);
            cnt += size/4;
          }
      }
    }
    cnt = (cnt+a+call_cnt) * 4;

    regmanager.stack_size = (cnt + 15) / 16 * 16;
    regmanager.a = a;
    regmanager.s = call_cnt;

    
    for (size_t i = 0; i < func->params.len; ++i) {
      auto param = reinterpret_cast<koopa_raw_value_t>(func->params.buffer[i]);
      RegOrStack tempreg;
      if(i < 8){
        regmanager.regmap[param] = RegOrStack("a"+std::to_string(i));
      }
      else{
        tempreg.isreg = 0;
        tempreg.offset = 4*(i-8)+regmanager.stack_size;
        tempreg.name = std::to_string(4*(i-8)+regmanager.stack_size)+"(sp)";
        regmanager.regmap[param] = tempreg;
      }
    }

    Visit(func->bbs);

  }
  
  // 访问基本块
  void Visit(const koopa_raw_basic_block_t &bb) {
    std::string label(bb->name);

      if (!label.empty() && label[0] == '%')
      label = label.substr(1);
      std::cout << label << ":\n";
    if(regmanager.begin == 0){
      std::cout << "\tli   t0, " << -regmanager.stack_size << std::endl;
    std::cout << "\tadd  sp, sp, t0" << std::endl;
    if(regmanager.a)
    {
      std::cout << "\tli   t0, " << regmanager.stack_size-4 << std::endl;
      std::cout << "\tadd  t0, sp, t0" << std::endl;
      std::cout << "\tsw ra, 0(t0)" << std::endl;

    }
      regmanager.begin = 1;
    }
    Visit(bb->insts);
  }
  
  // 访问指令
  void Visit(const koopa_raw_value_t &value) {
    // 根据指令类型判断后续需要如何访问
    const auto &kind = value->kind;
    switch (kind.tag) {
      case KOOPA_RVT_RETURN:
        regmanager.DumpReturn(kind.data.ret);
        break;
      case KOOPA_RVT_BINARY:
        regmanager.DumpBinary(kind.data.binary, value);
        break;
      case KOOPA_RVT_STORE:
        regmanager.DumpStore(kind.data.store);
        break;
      case KOOPA_RVT_LOAD:
        regmanager.DumpLoad(kind.data.load,value);
        break;
      case KOOPA_RVT_JUMP:
        regmanager.DumpJump(kind.data.jump);
        break;
      case KOOPA_RVT_BRANCH:
        regmanager.DumpBranch(kind.data.branch);
        break;
      case KOOPA_RVT_CALL:
        regmanager.DumpCall(kind.data.call,value);
        break;
      case KOOPA_RVT_ALLOC:
        regmanager.DumpAlloc(value);
        break;
      case KOOPA_RVT_GLOBAL_ALLOC:
        regmanager.DumpGlobalAlloc(kind.data.global_alloc, value);
        break;
      case KOOPA_RVT_AGGREGATE:
        regmanager.DumpAggregate(kind.data.aggregate);
        break;
      case KOOPA_RVT_GET_ELEM_PTR:
        regmanager.DumpGetElemPtr(kind.data.get_elem_ptr,value);
        break;
      case KOOPA_RVT_GET_PTR:
        regmanager.DumpGetPtr(kind.data.get_ptr,value);
        break;

      
      default:

        assert(false);
    }
  }
  