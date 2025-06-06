#pragma once
#include "koopa.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int  getsize(const koopa_raw_type_t ty);


class RegOrStack {
  public:
    std::string name;
    int isreg = 1;
    int offset = 0;
    int isg = 0;
    RegOrStack(std::string n, int r=1, int o=0, int g = 0) : name(n), isreg(r), offset(o), isg(g) {}

    RegOrStack() : name(""), isreg(1), offset(0), isg(0) {}
    
    friend ostream& operator<<(ostream& os, const RegOrStack& reg){
      os << reg.name;
      return os;
    }
};


class Regmanager {
  public:
    int regnum = 0;
    int stacknum = 0;
    int stack_size = 0;
    int a = 0;
    int s = 0;
    int begin = 0;
    unordered_map<koopa_raw_value_t, RegOrStack> regmap;
    unordered_map<koopa_raw_value_t, RegOrStack> gregmap;

    void init(){
      regnum = 0;
      stacknum = 0;
      stack_size = 0;
      a=0;
      s=0;
      begin = 0;
      regmap.clear();
      regmap.insert(gregmap.begin(), gregmap.end());
    }

    RegOrStack PrintOffset(RegOrStack reg, std::string regname){
      if(reg.isreg == 0){
        if(reg.isg == 1){
          std::cout<<"\tla "<<regname<<", "<<reg.name<<std::endl;
          reg.name = "0("+regname+")";
          return reg;
        }
        if(reg.offset <= 2047){
          reg.name = std::to_string(reg.offset) + "(sp)";
          return reg;
        }
        std::cout<<"\tli "<<regname<<", "<<reg.offset<<std::endl;
        std::cout<<"\tadd "<<regname<<", sp, "<<regname<<std::endl;
        reg.name = "0("+regname+")";
      }
      return reg;
    }

    RegOrStack LoadToReg(const koopa_raw_value_t& value, const std::string& regname){
      RegOrStack tempreg;
      if(value->kind.tag == KOOPA_RVT_INTEGER){
        
          std::cout<<"\tli "<<regname<<", "<<value->kind.data.integer.value<<std::endl;
          tempreg = RegOrStack(regname);
        
      }else{
        if(regmap.find(value) == regmap.end()){
          tempreg = currreg();
          regmap[value] = tempreg;
        }
        else{
          tempreg = regmap[value];
        }
        if(tempreg.isreg == 0){
          tempreg=PrintOffset(tempreg, regname);
          std::cout<<"\tlw "<<regname<<", "<<tempreg<<std::endl;
          tempreg.name = regname;
        }
      }
      return tempreg;
    }

    void StoreToReg(const koopa_raw_value_t& value, RegOrStack reg, const std::string& regname){
      RegOrStack tempreg;
      if(regmap.find(value) != regmap.end()){
        tempreg = regmap[value];
      }
      else{
        tempreg = currreg();
        regmap[value] = tempreg;
      }
      if(tempreg.isreg == 0){
        tempreg=PrintOffset(tempreg, regname);
        std::cout<<"\tsw "<<reg<<", "<<tempreg<<std::endl;
      }
      else{
        std::cout<<"\tmv "<<tempreg<<", "<<reg<<std::endl;
      }
      
    }

    RegOrStack currreg(){
      RegOrStack ret;
      ret.offset=4*(s+stacknum);
      ret.name = std::to_string(4*(s+stacknum))+"(sp)";
      ret.isreg = 0;
      stacknum++;
      
      regnum++;
      return ret;
    }


    void DumpBinary(const koopa_raw_binary_t& binary, const koopa_raw_value_t& value){
      RegOrStack reg1;
      RegOrStack reg2;
      RegOrStack reg3;
      RegOrStack tempreg;
      koopa_raw_value_t lhs = binary.lhs;
      koopa_raw_value_t rhs = binary.rhs;
      reg1 = LoadToReg(lhs, "t0");
      reg2 = LoadToReg(rhs, "t1");
      
      reg3.name = "t2";
      
      switch(binary.op){
        case KOOPA_RBO_ADD:
          std::cout<<"\tadd "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          break;
        case KOOPA_RBO_SUB:
          std::cout<<"\tsub "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          break;
        case KOOPA_RBO_MUL:
          std::cout<<"\tmul "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          break;
        case KOOPA_RBO_DIV:
          std::cout<<"\tdiv "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          break;
        case KOOPA_RBO_MOD:
          std::cout<<"\trem "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          break;
        case KOOPA_RBO_EQ:
          std::cout<<"\txor "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          std::cout<<"\tseqz "<<reg3<<", "<<reg3<<std::endl;
          break;
        case KOOPA_RBO_NOT_EQ:
          std::cout<<"\txor "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          std::cout<<"\tsnez "<<reg3<<", "<<reg3<<std::endl;
          break;
        case KOOPA_RBO_LT:
          std::cout<<"\tslt "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          break;
        case KOOPA_RBO_LE:
          std::cout<<"\tsgt "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          std::cout<<"\tseqz "<<reg3<<", "<<reg3<<std::endl;
          break;
        case KOOPA_RBO_GT:
          std::cout<<"\tsgt "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          break;
        case KOOPA_RBO_GE:
          std::cout<<"\tslt "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          std::cout<<"\tseqz "<<reg3<<", "<<reg3<<std::endl;
          break;
        case KOOPA_RBO_AND:
          std::cout<<"\tand "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          break;
        case KOOPA_RBO_OR:
          std::cout<<"\tor "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          break;
        case KOOPA_RBO_XOR:
          std::cout<<"\txor "<<reg3<<", "<<reg1<<", "<<reg2<<std::endl;
          break;
        default:
          std::cout<<"Unknown operator"<<std::endl;
          break;
      }
      StoreToReg(value, reg3, "t0");
    }

    void DumpReturn(const koopa_raw_return_t& ret){
      if (ret.value)
      {
         LoadToReg(ret.value, "a0");}
      if(a)
    {
      std::cout << "\tli   t0, " << stack_size-4 << std::endl;
      std::cout << "\tadd  t0, sp, t0" << std::endl;
      std::cout << "\tlw ra, 0(t0)" << std::endl;

    }
      std::cout << "\tli t0, " << stack_size << std::endl;
      std::cout << "\tadd sp, sp, t0" << std::endl;
      std::cout << "\tret" << std::endl;
    }



    void DumpStore(const koopa_raw_store_t& store){
      RegOrStack tempreg;
      RegOrStack temporeg;
      if(store.value -> kind.tag == KOOPA_RVT_INTEGER){
        std::cout<<"\tli t0, "<<store.value->kind.data.integer.value<<std::endl;
      }
      else if(regmap[store.value].isreg == 0){
        temporeg=PrintOffset(regmap[store.value], "t0");
        std::cout<<"\tlw t0, "<<temporeg<<std::endl;      
      }
      
      else{
        std::cout<<"\tmv t0, "<<regmap[store.value]<<std::endl;
      }
      if(regmap.find(store.dest) == regmap.end()){
        tempreg = currreg();
        regmap[store.dest] = tempreg;}
      else{
        tempreg = regmap[store.dest];
      }
        if(tempreg.isreg == 0){
          tempreg=PrintOffset(tempreg, "t1");
        }
        if(store.dest->kind.tag == KOOPA_RVT_GET_ELEM_PTR|| store.dest->kind.tag == KOOPA_RVT_GET_PTR){
          std::cout<<"\tlw t1, "<<tempreg<<std::endl;
          tempreg.name = "0(t1)";
          tempreg.isreg = 0;
        }
      
      
      if(tempreg.isreg == 0){
        std::cout<<"\tsw t0, "<<tempreg<<std::endl;
      }
      else{
        std::cout<<"\tmv "<<tempreg<<", t0"<<std::endl;
      }
    }

    void DumpLoad(const koopa_raw_load_t& load, const koopa_raw_value_t& value){
      
      RegOrStack temporeg;
      
      temporeg = LoadToReg(load.src, "t1");
      
        if(load.src->kind.tag == KOOPA_RVT_GET_ELEM_PTR|| load.src->kind.tag == KOOPA_RVT_GET_PTR){
          std::cout<<"\tlw t1, 0(t1)"<<std::endl;

        }
        StoreToReg(value, temporeg, "t0");
      
    }
    void DumpJump(const koopa_raw_jump_t& jump){
      std::string bb_name(jump.target->name);
      if (bb_name[0] == '%') {
        bb_name = bb_name.substr(1);
    }
      std::cout<<"\tj "<<bb_name<<std::endl;
    }

    void DumpBranch(const koopa_raw_branch_t &branch) {
      RegOrStack tempreg;
      tempreg = LoadToReg(branch.cond, "t0");
      
      std::string tlabel(branch.true_bb->name);
      if (!tlabel.empty() && tlabel[0] == '%')
        tlabel = tlabel.substr(1);
      std::cout << "\tbnez t0, " << tlabel << std::endl;
    
      std::string flabel(branch.false_bb->name);
      if (!flabel.empty() && flabel[0] == '%')
        flabel = flabel.substr(1);
      std::cout << "\tbeqz t0, " << flabel << std::endl;
    }

    void DumpCall(const koopa_raw_call_t &call, const koopa_raw_value_t &value) {
      int args = call.args.len;
      for(int i = 0; i < args; i++){
        auto arg = reinterpret_cast<koopa_raw_value_t>(call.args.buffer[i]);
        RegOrStack tempreg;
        RegOrStack tempreg2;
        tempreg = LoadToReg(arg, "t0");
        
        if(i < 8){
          tempreg2 = RegOrStack("a"+std::to_string(i));
          std::cout<<"\tmv "<<tempreg2<<", "<<tempreg<<std::endl;
        }
        else{
          tempreg2.isreg = 0;
          tempreg2.offset = 4*(i-8);
          tempreg2.name = std::to_string(4*(i-8))+"(sp)";
          tempreg2 = PrintOffset(tempreg2, "t1");
          std::cout<<"\tsw "<<tempreg<<", "<<tempreg2<<std::endl;
        }
      }
      RegOrStack tempreg;
      std::string func_name(call.callee->name+1);
      
      std::cout << "\tcall " << func_name << std::endl;
      if (value->ty->tag != KOOPA_RTT_UNIT){
        tempreg = currreg();
        regmap[value] = tempreg;
        tempreg = PrintOffset(tempreg, "t0");
        std::cout << "\tsw " << "a0, " << tempreg << std::endl;
      }
    }
    void DumpAlloc(const koopa_raw_value_t &value) {
      RegOrStack ret;
      int size = getsize(value->ty->data.pointer.base);
      ret.offset=4*(s+stacknum);
        ret.name = std::to_string(4*(s+stacknum))+"(sp)";
        ret.isreg = 0;
        stacknum+=size/4;
      regnum+=size/4;
      regmap[value] = ret;
      
    }



    void DumpGlobalAlloc(const koopa_raw_global_alloc_t &alloc, const koopa_raw_value_t &value) {
      std::string name(value->name+1);
      RegOrStack tempreg;
      tempreg.isreg = 0;
      tempreg.name = name;
      tempreg.offset = 0;
      tempreg.isg = 1;
      regmap[value] = tempreg;
      gregmap[value] = tempreg;
      std::cout<<"\t.global "<<name<<std::endl;
      std::cout<<name<<":"<<std::endl;
      if(alloc.init->kind.tag == KOOPA_RVT_INTEGER){
        std::cout<<"\t.word "<<alloc.init->kind.data.integer.value<<std::endl;
      }
      else if(alloc.init->kind.tag == KOOPA_RVT_AGGREGATE){
        DumpAggregate(alloc.init->kind.data.aggregate);
      }else{
        std::cout<<"\t.zero "<<getsize(alloc.init->ty)<<std::endl;
      }
    }

    void DumpGetElemPtr(const koopa_raw_get_elem_ptr_t &get_elem_ptr, const koopa_raw_value_t &value) {
      RegOrStack tempreg;
      RegOrStack reg1;
      RegOrStack reg2;
      reg1 = regmap[get_elem_ptr.src];
      if(reg1.isg){
        std::cout<<"\tla t0, "<<reg1.name<<std::endl;
        reg1.name = "t0";
      }
      else{
        std::cout<<"\tli t0, "<<reg1.offset<<std::endl;
        std::cout<<"\tadd t0, sp, t0"<<std::endl;
      }
      if(get_elem_ptr.src->kind.tag==KOOPA_RVT_GET_ELEM_PTR||get_elem_ptr.src->kind.tag==KOOPA_RVT_GET_PTR){
        std::cout<<"\tlw t0, 0(t0)"<<std::endl;
        reg1.name = "t0";}
      
      int size = getsize(get_elem_ptr.src->ty->data.pointer.base->data.array.base);
      reg2 = LoadToReg(get_elem_ptr.index, "t1");
      
      if(regmap.find(value) != regmap.end()){
        tempreg = regmap[value];
      }
      else{
        tempreg = currreg();
        regmap[value] = tempreg;
      }
      std::cout<<"\tli t2, "<<size<<std::endl;
      std::cout<<"\tmul t2, t1, t2"<<std::endl;
      std::cout<<"\tadd t1, t0, t2"<<std::endl;
      tempreg = PrintOffset(tempreg, "t0");
      std::cout<<"\tsw t1, "<<tempreg<<std::endl;

    }

    void DumpGetPtr(const koopa_raw_get_ptr_t &get_ptr, const koopa_raw_value_t &value) {
      RegOrStack tempreg;
      RegOrStack reg1;
      RegOrStack reg2;
      reg1 = regmap[get_ptr.src];
      if(reg1.isg){
        std::cout<<"\tla t0, "<<reg1.name<<std::endl;
        reg1.name = "t0";
      }
      else{
        std::cout<<"\tli t0, "<<reg1.offset<<std::endl;
        std::cout<<"\tadd t0, sp, t0"<<std::endl;
        std::cout<<"\tlw t0, 0(t0)"<<std::endl;
      }
      
      int size = getsize(get_ptr.src->ty->data.pointer.base);
      reg2 = LoadToReg(get_ptr.index, "t1");
      if(regmap.find(value) != regmap.end()){
        tempreg = regmap[value];
      }
      else{
        tempreg = currreg();
        regmap[value] = tempreg;
      }
      std::cout<<"\tli t2, "<<size<<std::endl;
      std::cout<<"\tmul t2, t1, t2"<<std::endl;
      std::cout<<"\tadd t1, t0, t2"<<std::endl;
      tempreg = PrintOffset(tempreg, "t0");
      std::cout<<"\tsw t1, "<<tempreg<<std::endl;

    }

    void DumpAggregate(const koopa_raw_aggregate_t &aggregate) {
      for (int i = 0; i < aggregate.elems.len; i++) {
        auto elem = reinterpret_cast<koopa_raw_value_t>(aggregate.elems.buffer[i]);

        if (elem->kind.tag == KOOPA_RVT_INTEGER) {
          std::cout << "\t.word " << elem->kind.data.integer.value << std::endl;
        }else DumpAggregate(elem->kind.data.aggregate);
      }
      }
      
};

void koopa_dump(const char* str);
void Visit(const koopa_raw_program_t &program);
void Visit(const koopa_raw_slice_t &slice);
void Visit(const koopa_raw_function_t &func);
void Visit(const koopa_raw_basic_block_t &bb);
void Visit(const koopa_raw_value_t &value);
