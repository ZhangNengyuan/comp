#pragma once

#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <deque>

#define IMM 0
#define REG 1
#define PAR 4
#define CONDOM 2
#define VAR 3
#define GLB 5
#define CONSTMAT 6
#define MAT 7
#define IFTYPE 0
#define WHILETYPE 1
#define NONETYPE 2
#define VOIDTYPE 0
#define INTTYPE 1
#define PARMAT 8

using namespace std;

extern string mode;

static int currnum = 0;

class Result{
    public:
     int type = IMM;
     int value;
     friend ostream& operator<<(ostream& os, const Result& result) {
         if(result.type == IMM) {
             os << result.value;
         } else {
             os << "%" << result.value;
         }
         return os;
     }
        Result(int type=VAR, int value=0) : type(type), value(value) {}

        int cmp(Result res){
            if(type == IMM && res.type == IMM && value == res.value){
                return 1;
            }return 0;
        }

};

class MatrixTable {
    public:
        int layer = 0;
        int type = 0;
        std::vector<int> paramv;
        std::vector<int> totnum;
        std::vector<int> temp;
        std::vector<Result> totw;
        int minl;
    
        MatrixTable() = default;
    
        void push(int num) {
            paramv.push_back(num);
            layer++;
        }
    
        void init() {
            temp.assign(layer, 0);
            totnum = paramv;
            totnum.push_back(1);
            for (int i = layer - 1; i >= 0; --i) {
                totnum[i] = totnum[i + 1] * paramv[i];
            }
            totw.assign(totnum[0], Result(IMM, 0));
            minl = layer - 1;
        }
    
        int currpos() const {
            int pos = 0;
            for (int i = layer - 1; i >= 0; --i) {
                pos += temp[i] * totnum[i + 1];
            }
            assert(pos >= 0 && pos < static_cast<int>(totw.size()));
            return pos;
        }
    
        void addnum(const Result& res) {
            totw[currpos()] = res;

            for (int i = layer - 1; i >= 0; --i) {
                temp[i]++;
                minl = std::min(minl, i);
                if (temp[i] >= paramv[i]) {
                    temp[i] = 0;
                } else {
                    break;
                }
            }
        }
    
        void closure_1() {
            int ck = 0;
            minl = min(minl, layer - 2);
            for (int i = layer - 1; i > minl; --i) {
                if (temp[i] != 0) {
                    ck=1;
                    temp[i] = 0;
                }
            }
            while (ck >= 0) {
                for (int i = minl; i >= 0; --i) {
                    temp[i]++;
                    if (temp[i] >= paramv[i]) temp[i] = 0;
                    else {
                        break;
                    }
                    minl = std::min(minl, i);
                }ck--;
            }
           
        }
    
        void closure() {
            int ck = 0;
            for (int i = layer - 1; i > minl; --i) {
                if (temp[i] != 0) {
                    ck = 1;
                    temp[i] = 0;
                }
            }
            if (ck > 0) {
                for (int i = minl; i >= 0; --i) {
                    temp[i]++;
                    if (temp[i] >= paramv[i]) temp[i] = 0;
                    else {
                        break;
                    }
                    minl = std::min(minl, i);
                }
            }
        }
    
    
        void printt() const {
            for (int i = 0; i < layer; ++i) std::cout << "[";
            std::cout << "i32";
            for (int i = layer - 1; i >= 0; --i) {
                std::cout << ", " << paramv[i] << "]";
            }
        }
    
        void printc(int kcp) {
            printt();
            
            std::cout << ", ";
            // 保存并重置 temp
            std::vector<int> backup = temp;
            std::fill(temp.begin(), temp.end(), 0);
            for(int i = 0; i<totw.size();i++){
                if(totw[i].type == IMM && totw[i].value == 0){
                   if(i == totw.size()-1){
                        std::cout << "zeroinit"<<endl;
                        return;
                    }
                }else break;
            }
            printcRec(0);
            std::cout << std::endl;
            temp = backup;
        }
    
        void printcRec(int dim) {
            if (dim == layer) {
                if (totw[currpos()].type == IMM) std::cout << totw[currpos()];
                else std::cout << 0;
                return;
            }
            std::cout << "{";
            for (int i = 0; i < paramv[dim]; ++i) {
                temp[dim] = i;
                printcRec(dim + 1);
                if (i + 1 < paramv[dim]) std::cout << ", ";
            }
            std::cout << "}";
        }
    
        void printv(const std::string& name) {
            printt();
            std::cout << std::endl;
            std::vector<int> backup = temp;
            std::fill(temp.begin(), temp.end(), 0);
            printcRDon(0, name);
            std::cout << std::endl;
            temp = backup;
        }
    
        void printcRDon(int dim, const std::string& name) {
            if (dim == layer) {
                const Result& r = totw[currpos()];
                // 一律打印 getelemptr 和 store

                Result tempreg = Result(REG, currnum++);
                std::cout << "\t" << tempreg << " = getelemptr @" << name << ", " << temp[0] << std::endl;
                for (int i = 1; i < layer; ++i) {
                    Result tempo = tempreg;
                    tempreg = Result(REG, currnum++);
                    std::cout << "\t" << tempreg << " = getelemptr " << tempo << ", " << temp[i] << std::endl;
                }
                std::cout << "\tstore " << r << ", " << tempreg << std::endl;
                return;
            }
            for (int i = 0; i < paramv[dim]; ++i) {
                temp[dim] = i;
                printcRDon(dim + 1, name);
            }
        }
    };
    
  

class Symbol{
    public:
     std::string name;
     int type = VAR;
     int value;
     MatrixTable mat;
     Symbol() = default; 
     Symbol(std::string name, int type, int value) : name(name), type(type), value(value), mat(MatrixTable()) {}
     Symbol(std::string name, int type) : name(name), type(type), value(0), mat(MatrixTable()) {}
     Symbol(std::string name, MatrixTable mat, int type = MAT): name(name), type(type), value(0), mat(mat) {}
}
;

class SymbolTable{
    public:
     std::unordered_map<std::string, Symbol> symbols;
     int blocknum;
     void insert(std::string name, int type, int value) {
        symbols[name] = Symbol(name, type, value);
     }
     void insert(std::string name, int type, MatrixTable value) {
        symbols[name] = Symbol(name, value,type);
     }
     void insert(std::string name, int type) {
        symbols[name] = Symbol(name, type);
     }
     bool exists(std::string name) {
        return symbols.find(name) != symbols.end();
     }
     Symbol get(std::string name) {
        return symbols[name];
     }
}
;

class Func_Table{
    public:
      std::unordered_map<std::string, int> func_table;
      std::unordered_map<std::string, int> func_types;
      int glbdef=0;
      SymbolTable glb;
      std::string currname;
      void push(int num) {
        func_table[currname] = num;
      }
      void push(string name, int num,int type) {
        func_table[name] = num;
        func_types[name] = type;
      }
      void pushtype( int type) {
        func_types[currname] = type;
      }
      int size(string name) {
        return func_table[name];
      }
        int type(string name) {
            return func_types[name];
        }
        void push_glb(string name, int type, int value) {
            glb.insert(name, type, value);
        }
      
};

static Func_Table func_table;
static MatrixTable mat_table;
static std::vector<Result> parav;




class BlockTable{
    public:
      std::vector<SymbolTable> block_tables;
      std::vector<Symbol> param_symbols;
      int blocklayer = 0;
      int blocknum =0;
      void pushparam(std::string name) {
        param_symbols.push_back(Symbol(name,PAR,0));
      }
      void pushparammatrix(std::string name,MatrixTable mat) {
        param_symbols.push_back(Symbol(name,mat,PARMAT));
      }
      void push() {
        block_tables.push_back(SymbolTable());
        block_tables[blocklayer].blocknum = blocknum;
        blocknum++;
        blocklayer++;
      }
      void push(SymbolTable& table) {
        block_tables.push_back(table);
        block_tables[blocklayer].blocknum = blocknum;
        blocknum++;
        blocklayer++;
      } 
      void pop() {
        block_tables.pop_back();
        blocklayer--;
      }
      SymbolTable& top() {
        return block_tables.back();
      }

      int getlayer(std::string name) {
        for(int i = blocklayer-1; i >= 0; i--) {
            if(block_tables[i].exists(name)) {
                return block_tables[i].blocknum;
            }
        }
        return -1;
      }

      Symbol get(std::string name) {
        for(int i = blocklayer-1; i >= 0; i--) {
            if(block_tables[i].exists(name)) {
                return block_tables[i].get(name);
            }
        }
        return Symbol();
      }

      void insert(std::string name, int type, int value) {
        if(block_tables[blocklayer-1].exists(name)) {
            std::cout << "Error: " << name << " already defined" << endl;
        } else {
            block_tables[blocklayer-1].insert(name, type, value);
        }
      }
      void insert(std::string name, int type, MatrixTable mat) {
        if(block_tables[blocklayer-1].exists(name)) {
            std::cout << "Error: " << name << " already defined" << endl;
        } else {
            block_tables[blocklayer-1].insert(name, type, mat);
        }
      }

};



class Kop_Table{
    public:
      int ifnum=0;
      int retyet=0;
      int havelse=0;
      int cur=0;
      int cnt=0;
      int whilelayer=0;
      int whilenum=0;
      int expnum=0;
      int type=NONETYPE;
      int ornum=0;
      int andnum=0;
      int inor=0;
      int inand=0;
      int orlayer=0;
      int andlayer=0;
      int curror = 0;
      int currand = 0;
      int currol = 0;
      int curral = 0;
      std::unordered_map<std::string, int> ver_table;

      void initk(){
       inor=0;
       inand=0;
      orlayer=0;
       andlayer=0;
      curror = 0;
      currand = 0;
   currol = 0;
   curral = 0;

      }

      void reco(int num, int layer){
        inor = 1;
        currol = layer;
        orlayer = layer;
        curror = num;
      }

      void reca(int num, int layer){
        inand = 1;
        curral = layer;
        andlayer = layer;
        currand = num;
      }


      

        std::string printotrue()
        {
            return "%"+func_table.currname+"_otrue_" + std::to_string(curror) + "_" + std::to_string(currol);
        }
        std::string printofalse()
        {
            return "%"+func_table.currname+"_ofalse_" + std::to_string(curror) + "_" + std::to_string(currol);
        }
        std::string printoend(){
            return "%"+func_table.currname+"_oend_" + std::to_string(curror) + "_" + std::to_string(currol);
        }
        std::string printopos(){
            string name = func_table.currname+"_opos_" + std::to_string(curror);
            if(ver_table.find(name) == ver_table.end()){
                ver_table[name] = 1;
                std::cout << "\t@"<<name<<" = alloc i32" << endl;
                
            }
            return "@"+name;
        }
        std::string printandtrue()
        {
            return "%"+func_table.currname+"_andtrue_" + std::to_string(currand) + "_" + std::to_string(curral);
        }
        std::string printandfalse()
        {
            return "%"+func_table.currname+"_andfalse_" + std::to_string(currand) + "_" + std::to_string(curral);
        }
        std::string printandend(){
            return "%"+func_table.currname+"_andend_"  + std::to_string(currand) + "_"+ std::to_string(curral);
        }
        std::string printandpos(){
            string name = func_table.currname+"_andpos_" + std::to_string(currand);
            if(ver_table.find(name) == ver_table.end()){
                ver_table[name] = 1;
                std::cout << "\t@"<<name<<" = alloc i32" << endl;
                
            }
            return "@"+name;
        }
        


};


static BlockTable block_table;
//static int kop_table.ifnum = 0;
//static int kop_table.retyet = 0;
static Kop_Table kop_table;




static std::vector<Result>tempo;


// 所有 AST 的基类
class BaseAST {
    public:
    virtual ~BaseAST() = default;
   
    virtual Result Dump() const = 0;
};

class CompUnitAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> func_def;
   
     Result Dump() const override {
        std::cout << "decl @getint(): i32"    << std::endl;
    std::cout << "decl @getch(): i32"     << std::endl;
    std::cout << "decl @getarray(*i32): i32" << std::endl;
    std::cout << "decl @putint(i32)"      << std::endl;
    std::cout << "decl @putch(i32)"       << std::endl;
    std::cout << "decl @putarray(i32, *i32)" << std::endl;
    std::cout << "decl @starttime()"      << std::endl;
    std::cout << "decl @stoptime()"       << std::endl;
    func_table.push("getint", 0, INTTYPE);
    func_table.push("getch", 0, INTTYPE);
    func_table.push("getarray", 1, INTTYPE);
    func_table.push("putint", 1, VOIDTYPE);
    func_table.push("putch", 1, VOIDTYPE);
    func_table.push("putarray", 2, VOIDTYPE);
    func_table.push("starttime", 0, VOIDTYPE);
    func_table.push("stoptime", 0, VOIDTYPE);
        return func_def->Dump();
     }
};

class MDefAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> def;
     std::unique_ptr<BaseAST> mdef;
     int keep = 0;
     int func = 0;
   
     Result Dump() const override {

        def->Dump();
        
        if(keep)mdef->Dump();
        return Result(IMM, 0);
     }
};

class MatrixParamsAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> mparams;
     std::unique_ptr<BaseAST> exp;
     int keep = 0;
   
     Result Dump() const override {
        Result res = exp->Dump();
        mat_table.push(res.value);
        if(keep){mparams->Dump();
        }
        
        return Result(IMM, 0);
     }
};
class LMatrixParamsAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> mparams;
     std::unique_ptr<BaseAST> exp;
     int keep = 0;
   
     Result Dump() const override {
        std::vector<Result> tparamv;
        tparamv = parav;
        Result res = exp->Dump();
        tparamv.push_back(res);
        parav = tparamv;
        if(keep)mparams->Dump();
        
        return Result(IMM, 0);
     }
};
class FuncDefAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> func_type;
     std::string ident;
     std::unique_ptr<BaseAST> block;
     std::unique_ptr<BaseAST> fps;
     int havp = 0;
     int isint = 0;
   
     Result Dump() const override {
        kop_table=Kop_Table();
        block_table=BlockTable();
        block_table.push(func_table.glb);
        func_table.currname = ident;
        kop_table.retyet = 0;
        std::cout << "fun @" << ident << "(";
        func_table.pushtype(isint);
        if(havp) {
            //std::cout<<block_table.param_symbols.size()<<std::endl;
            fps->Dump();
            
        }
        std::cout << ") ";

        if(isint) std::cout << ": i32"<<std::endl;
        
        func_table.push(block_table.param_symbols.size());
        std::cout << "{"<<endl;
        std::cout << "%"<<func_table.currname<<"_entry:" << endl;
        if(havp)
        {for(int i = 0; i < block_table.param_symbols.size(); i++) {
            if(block_table.param_symbols[i].type == PAR) {
                std::cout <<"\t%"<<block_table.param_symbols[i].name<<"= alloc i32" << endl;
            std::cout << "\tstore @" << block_table.param_symbols[i].name << ", %"<<block_table.param_symbols[i].name<<endl;
        }else{
            std::cout <<"\t%"<<block_table.param_symbols[i].name<<"= alloc *";
            block_table.param_symbols[i].mat.printt();
            std::cout << endl;
            std::cout << "\tstore @" << block_table.param_symbols[i].name << ", %"<<block_table.param_symbols[i].name<<endl;
        }

    
    }
            }
            
        block->Dump();
        if(func_table.type(ident)==VOIDTYPE){
            std::cout << "\tret"<< endl;
        }
        std::cout << "}" << endl;
        return Result(IMM, 0);
     }
};



class FuncFParamsAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> fps;
     std::unique_ptr<BaseAST> fp;
     int keep = 0;
   
     Result Dump() const override {
        fp->Dump();
        if(keep){
            std::cout << ", ";
            
            fps->Dump();}
        return Result(IMM, 0);
     }
};

class FuncFParamAST : public BaseAST {
    public:
     std::string ident;
   
     Result Dump() const override {
        block_table.pushparam(ident);
        std::cout<<"@"<<ident<<": i32";
        return Result(IMM, 0);
     }
};

class FuncFParamMAST : public BaseAST {
    public:
     std::string ident;
     int uno=1;
     std::unique_ptr<BaseAST> pr;
   
     Result Dump() const override {
        mat_table=MatrixTable();
        mat_table.type = 1;

        
        if(uno){std::cout<<"@"<<ident<<": *i32";
        block_table.pushparammatrix(ident,mat_table);
        return Result(IMM, 0);}
        pr->Dump();
        std::cout<<"@"<<ident<<": *";
        mat_table.printt();
        block_table.pushparammatrix(ident,mat_table);
        return Result(IMM, 0);

     }
};

class DoncicExpAST : public BaseAST {
    public:
     std::string ident;
     std::unique_ptr<BaseAST> hps;
     int havp = 0;
   
     Result Dump() const override {
        Result res= Result(IMM, 0);
        std::vector<Result> temps;
        if(havp) {
            hps->Dump();
        }
        for(int i = 0; i < func_table.size(ident); i++) {
            temps.push_back(tempo.back());
            tempo.pop_back();
        }
        
        if(func_table.type(ident)==INTTYPE){
            res = Result(REG, currnum++);
            std::cout << "\t" << res << " = call @" << ident << "(";

        }
        else{std::cout << "\tcall @" << ident << "(";}
        for(int i = 0; i < func_table.size(ident); i++) {
            std::cout << temps.back();
            temps.pop_back();
            if(i != func_table.size(ident) - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << endl;

        return res;
     }
};

class FuncRParamsAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> fps;
     std::unique_ptr<BaseAST> fp;
     int keep = 0;
   
     Result Dump() const override {
        tempo.push_back(fp->Dump());
        if(keep){            
            fps->Dump();}
        return Result(IMM, 0);
     }
};





class BlockAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> multiblockitem;
     int empty = 0;
   
     Result Dump() const override {
        if(empty) {
            return Result(IMM, 0);
        }
        block_table.push();
        if(block_table.param_symbols.size()!=0 && !block_table.block_tables[1].exists(block_table.param_symbols[0].name)){
            for(int i = 0; i<block_table.param_symbols.size();i++){
                block_table.block_tables[1].symbols[block_table.param_symbols[i].name] = block_table.param_symbols[i];
            }
        }
        multiblockitem->Dump();
        block_table.pop();
        return Result(IMM, 0);
     }
};

class MultiBlockItemAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> blockitem;
     std::unique_ptr<BaseAST> multiblockitem;
     bool keep = false;
   
     Result Dump() const override {
        blockitem->Dump();
        if(keep)multiblockitem->Dump();
        return Result(IMM, 0);
     }
};

class BlockItemAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> stmt;
     std::unique_ptr<BaseAST> decl;
     bool isstmt = false;
   
     Result Dump() const override {
        if(isstmt) {
            stmt->Dump();
        } else {
            decl->Dump();
        }
        return Result(IMM, 0);
     }
};

class IfStmtAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> exp;
     std::unique_ptr<BaseAST> tstmt;
     std::unique_ptr<BaseAST> estmt;
     int ifelse = 0;
     
     Result Dump() const override {
        int temp;
        int ak;
        if(kop_table.retyet){
            return Result(IMM, 0);
        }
        kop_table.havelse=ifelse;
        kop_table.type=IFTYPE;
        Result res = exp->Dump();
            temp=kop_table.ifnum;
            kop_table.ifnum++;
            if(!ifelse){
                std::cout << "\tbr "<<res<<", %"<<func_table.currname<<"_then_"<<temp<<", %"<<func_table.currname
                <<"_end_"<<temp<<endl;
                std::cout << "%"<<func_table.currname<<"_then_"<<temp<<":"<<endl;
                tstmt->Dump();
                
                if(!kop_table.retyet){
                    std::cout <<"\tjump %"<<func_table.currname<<"_end_"<<temp<<endl;
                }
                kop_table.retyet=0;
                std::cout << "%"<<func_table.currname<<"_end_"<<temp<<":"<<endl;
                return Result(IMM, 0);

            }
            std::cout << "\tbr "<<res<<", %"<<func_table.currname<<"_then_"<<
            temp<<", %"<<func_table.currname<<"_else_"<<temp<<endl;
            std::cout << "%"<<func_table.currname<<"_then_"<<temp<<":"<<endl;          
            tstmt->Dump();
            ak = kop_table.retyet;
            if(!kop_table.retyet){
                std::cout <<"\tjump %"<<func_table.currname<<"_end_"<<temp<<endl;
            }
            kop_table.retyet=0;
            std::cout << "%"<<func_table.currname<<"_else_"<<temp<<":"<<endl;
            estmt->Dump();
            ak = kop_table.retyet&&ak;
            if(!kop_table.retyet){
                std::cout <<"\tjump %"<<func_table.currname<<"_end_"<<temp<<endl;
            }
            kop_table.retyet=ak;
            if(!ak)std::cout << "%"<<func_table.currname<<"_end_"<<temp<<":"<<endl;

            return Result(IMM, 0);
     }
   
     
};

class WhileStmtAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> exp;
     std::unique_ptr<BaseAST> stmt;
   
     Result Dump() const override {
        if(kop_table.retyet){
            return Result(IMM, 0);
        }
        int temp = kop_table.whilenum;
        int temp_1 = kop_table.whilelayer;
        kop_table.whilelayer = temp;
        
        std::cout <<"\tjump %"<<func_table.currname<<"_wentry_"<<temp<<endl;
        
        std::cout << "%"<<func_table.currname<<"_wentry_"<<temp<<":"<<endl;
        kop_table.type=WHILETYPE;
        Result res = exp->Dump();
       
        kop_table.whilenum++;
        std::cout << "\tbr "<<res<<", %"<<func_table.currname<<"_wbody_"<<temp<<", %"<<
        func_table.currname<<"_wend_"<<temp<<endl;
        std::cout << "%"<<func_table.currname<<"_wbody_"<<temp<<":"<<endl;
        stmt->Dump();
        kop_table.whilelayer=temp_1;
        if(!kop_table.retyet){
            std::cout <<"\tjump %"<<func_table.currname<<"_wentry_"<<temp<<endl;
        }
        kop_table.retyet=0;
        std::cout << "%"<<func_table.currname<<"_wend_"<<temp<<":"<<endl;
        return Result(IMM, 0);
     }
};

class StmtAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> lval;
     std::unique_ptr<BaseAST> exp;
     int ret = 0;
     int empty = 0;
     int isblock = 0;
     int ismat = 0;
   
     Result Dump() const override {
        if(kop_table.retyet){
            return Result(IMM, 0);
        }
        if(isblock){
            exp->Dump();
            return Result(IMM, 0);
        }
        if(empty) {
            if(ret) {
                if(func_table.type(func_table.currname)==VOIDTYPE)
                {
                    std::cout << "\tret" << endl;
                }
                else{
                    std::cout << "\tret 0" << endl;
                }

                kop_table.retyet=1;
                return Result(IMM, 0);
            }
            if(empty==2)exp->Dump();
            return Result(IMM, 0);
        }
        if(ret)
       { Result res = exp->Dump();
       std::cout << "\tret " << res <<endl;
    kop_table.retyet=1;}
       else{
        Result res = exp->Dump();
        if(ismat){
           Result res1 = lval->Dump();
           std::cout << "\tstore " << res << ", " << res1<<endl;
        }
        else{std::cout << "\tstore " << res << ", ";
        lval->Dump();}
       }
        return Result(IMM, 0);
     }
};

class BrCoAST : public BaseAST {
    public:
     int isbreak = 0;
   
     Result Dump() const override {
        if(kop_table.retyet){
            return Result(IMM, 0);
        }
        kop_table.retyet=1;
        if(isbreak) {
            std::cout << "\tjump %"<<func_table.currname<<"_wend_"<<kop_table.whilelayer<<endl;
        } else {
            std::cout << "\tjump %"<<func_table.currname<<"_wentry_"<<kop_table.whilelayer<<endl;
        }
        return Result(IMM, 0);
     }
};

class GlbDeclAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> constdecl;
     std::unique_ptr<BaseAST> vardecl;
     int type;
   
     Result Dump() const override {
        
        func_table.glbdef=1;
        block_table=BlockTable();
        //std::cout << "doncic" << endl;
        block_table.push(func_table.glb);

        if(!type) {
            constdecl->Dump();
        } else {
            vardecl->Dump();
        }
        func_table.glbdef=0;
        
        return Result(IMM, 0);
     }
};


class DeclAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> constdecl;
     std::unique_ptr<BaseAST> vardecl;
     int type;
   
     Result Dump() const override {
        if(!type) {
            constdecl->Dump();
        } else {
            vardecl->Dump();
        }
        return Result(IMM, 0);
     }
};


class ConstDeclAST : public BaseAST {
    public:
     std::string ident;
     std::unique_ptr<BaseAST> multiconstdef;
   
     Result Dump() const override {
        multiconstdef->Dump();
        return Result(IMM, 0);
     }
};

class MultiConstDefAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> constdef;
     std::unique_ptr<BaseAST> multiconstdef;
     bool keep = false;
   
     Result Dump() const override {
        Result res = constdef->Dump();
        if(keep)multiconstdef->Dump();
        return res;
     }
};




class VarDeclAST : public BaseAST {
    public:
     std::string ident;
     std::unique_ptr<BaseAST> multivardef;
   
     Result Dump() const override {
        multivardef->Dump();
        return Result(IMM, 0);
     }
};

class MultiVarDefAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> vardef;
     std::unique_ptr<BaseAST> multivardef;
     bool keep = false;
   
     Result Dump() const override {
        vardef->Dump();
        if(keep)multivardef->Dump();
        return Result(IMM, 0);
     }
};
class VarDefAST : public BaseAST {
    public:
     std::string ident;
     std::unique_ptr<BaseAST> initval;
     std::unique_ptr<BaseAST> matp;
     int defm = 0;
     int num = 1;
   
     Result Dump() const override {
        mat_table.type = defm;

        if(defm){
            string name;
            mat_table=MatrixTable();
            mat_table.type = 1;
            matp->Dump();
            
            mat_table.init();
            if(num){
                initval->Dump();
                
            }
            block_table.insert(ident, MAT, mat_table);
            if(func_table.glbdef){
                func_table.glb.insert(ident, MAT, mat_table);
                name = ident+"_0";
                std::cout<<"global @"<<ident<<"_0 = alloc";
                mat_table.printc(func_table.glbdef);
                return Result(IMM, 0);
            }else{
                name = ident+"_"+std::to_string(block_table.getlayer(ident));
                std::cout << "\t@" << ident<<"_"<<block_table.getlayer(ident) << " = alloc" ;
            }
            mat_table.printv(name);
            return Result(IMM, 0);

        }

        block_table.insert(ident, VAR, 0);
        if(func_table.glbdef){
            func_table.glb.insert(ident, VAR, 0);
            Result res= Result(IMM, 0);
            if(num){
                res = initval->Dump();
            }
            std::cout<<"global @"<<ident<<"_0"<<" = alloc i32, "<<res<<endl;
            
            return res;
        }
        std::cout << "\t@" << ident<<"_"<<block_table.getlayer(ident) << " = alloc i32" << endl;
        
        if(num)
        {Result res = initval->Dump();
        std::cout << "\tstore " << res << ", @" << ident<<"_"<<block_table.getlayer(ident) << endl;
        }
        return Result(IMM, 0);
     }
};

class ConstDefAST : public BaseAST {
    public:
     std::string ident;
     std::unique_ptr<BaseAST> matp;
     std::unique_ptr<BaseAST> constinitval;
     int defm = 0;
   
     Result Dump() const override {
        mat_table.type = defm;
        string name;
        if(defm){
            mat_table=MatrixTable();
            mat_table.type = 1;
            matp->Dump();
            mat_table.init();
            constinitval->Dump();
            block_table.insert(ident, CONSTMAT, mat_table);
            
            if(func_table.glbdef){
                func_table.glb.insert(ident, CONSTMAT, mat_table);
                std::cout<<"global @"<<ident<<"_0 = alloc";mat_table.printc(func_table.glbdef);
                return Result(IMM, 0);
            }
            else{
                name = ident+"_"+std::to_string(block_table.getlayer(ident));
                std::cout << "\t@" << ident<<"_"<<block_table.getlayer(ident) << " = alloc" ;}
            mat_table.printv(name);
            
            return Result(IMM, 0);
        }
        Result res = constinitval->Dump();
        block_table.insert(ident, CONDOM, res.value);
        if(func_table.glbdef){
            func_table.glb.insert(ident, CONDOM, res.value);
        }
        return Result(IMM, 0);
     }
};


class InitValAST : public BaseAST {
    public:
        std::unique_ptr<BaseAST> exp;
        int keep = 0;
    
        Result Dump() const override {
            if (!mat_table.type) return exp->Dump();
            if (keep == 2) {
                mat_table.closure_1();
            }else if (keep == 1) {
                exp->Dump();

                mat_table.closure();}
             else {
                Result res = exp->Dump();

                mat_table.addnum(res);

            }
            return Result(IMM, 0);
        }
    };
    
    // ---------- MulInitValAST ----------
class MulInitValAST : public BaseAST {
    public:
        std::unique_ptr<BaseAST> exp;
        int keep = 0;
        std::unique_ptr<BaseAST> kexp;
    
        Result Dump() const override {
            int saved_minl = mat_table.minl;
            exp->Dump();
            mat_table.minl = std::min(saved_minl, mat_table.minl);
            if (keep) kexp->Dump();
            return Result(IMM, 0);
        }
};
    
    

class ExpAST : public BaseAST {
    public:
    std::unique_ptr<BaseAST> lorexp;
   
    Result Dump() const override {
        Result res;

        kop_table.initk();
        res = lorexp->Dump();
        return res;
     }
};

class PrimaryExpAST : public BaseAST {
    public:
     int isnumber;
     std::unique_ptr<BaseAST> exp;
     std::unique_ptr<BaseAST> number;
     std::unique_ptr<BaseAST> lval;
   
     Result Dump() const override {
       if(isnumber==1) {
         return number->Dump();
       } else if(isnumber==0) {
         return exp->Dump();
       }else {
         return lval->Dump();
       }
     }
};

class NumberAST : public BaseAST {
    public:
     int value;
     explicit NumberAST(int v) : value(v) {}
     Result Dump() const override {
       Result res = Result(IMM, value);
        return res;
     }
};

class LValAST : public BaseAST {
    public:
     std::string ident;
     int defm = 0;
     std::unique_ptr<BaseAST> matp;
   
     Result Dump() const override {
        if (!defm){
            Symbol sym = block_table.get(ident);
        int layer = block_table.getlayer(ident);
        if(sym.type == VAR){
            Result res = Result(REG, currnum);
            currnum++;
            std::cout << "\t" << res << " = load @" << ident<<"_"<<layer<<endl;
            return res;
        }else if(sym.type == CONDOM){
            return Result(IMM, sym.value);
        }else if(sym.type==MAT||sym.type==CONSTMAT){
            Result res = Result(REG, currnum);
            currnum++;
            std::cout << "\t" << res << " = getelemptr @" << ident<<"_"<<layer<<","<<0<<endl;
            return res;
        }
        else if(sym.type==PARMAT){
            Result res = Result(REG, currnum);
            currnum++;
            std::cout << "\t" << res << " = load %" << ident<<endl;
            
            return res;}
            else{
            Result res = Result(REG, currnum++);
            std::cout << "\t" << res << " = load %" << ident<<endl;
            
            return res;
        }

        }
        
        else{
            Symbol sym = block_table.get(ident);
            int layer = block_table.getlayer(ident);
            parav.clear();
            matp->Dump();
            Result res = Result(REG, currnum++);
            Result res1;
            if(sym.type==PARMAT){
                std::cout<<"\t" << res << " = load %" << ident<<endl;
                res1=res;
                res=Result(REG, currnum++);
                std::cout << "\t" << res << " = getptr "<<res1<<","<<parav[0]<<endl;
            }
            else {std::cout << "\t" << res << " = getelemptr @" << ident<<"_"<<layer<<","<<parav[0]<<endl;}
            for(int i =1; i<parav.size();i++){
                res1 = Result(REG, currnum++);
                std::cout << "\t" << res1 << " = getelemptr "<<res<<","<<parav[i]<<endl;
                res=res1;
            }
            if((parav.size()<=sym.mat.layer&&sym.type==PARMAT)||parav.size()<sym.mat.layer){
                res1 = Result(REG, currnum++);
                std::cout << "\t" << res1 << " = getelemptr "<<res<<","<<0<<endl;
                return res1;
            }
            res1 = Result(REG, currnum++);
            std::cout << "\t" << res1 << " = load "<<res<<endl;
            return res1;

        }
        
        return Result(IMM, 0);
     }
};

class LLValAST : public BaseAST {
    public:
     std::string ident;
   
     Result Dump() const override {
        Symbol sym = block_table.get(ident);
        int layer = block_table.getlayer(ident);
        if(sym.type == VAR){
            std::cout<<"@"<<ident<<"_"<<layer<<endl;
        }else if(sym.type == CONDOM){
            return Result(IMM, sym.value);
        }
        else{
            std::cout<<"%"<<ident<<endl;
        }
        return Result(IMM, 0);
     }
};

class MLLValAST : public BaseAST {
    public:
     std::string ident;
     std::unique_ptr<BaseAST> matp;
   
     Result Dump() const override {
        Symbol sym = block_table.get(ident);
        int layer = block_table.getlayer(ident);
        parav.clear();
        matp->Dump();
        Result res = Result(REG, currnum++);
        Result res1;
        if(sym.type==PARMAT){
            std::cout<<"\t" << res << " = load %" << ident<<endl;
            res1=res;
            res=Result(REG, currnum++);
            std::cout << "\t" << res << " = getptr "<<res1<<","<<parav[0]<<endl;
        }
        else{std::cout << "\t" << res << " = getelemptr @" << ident<<"_"<<layer<<","<<parav[0]<<endl;}
        for(int i =1; i<parav.size();i++){
            Result res1 = Result(REG, currnum++);
            std::cout << "\t" << res1 << " = getelemptr "<<res<<","<<parav[i]<<endl;
            res=res1;
        }
        return res;

     }
};

class UnaryExpAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> unaryexp;
     std::unique_ptr<BaseAST> primaryexp;
     char op = '+';
     bool isprimary;
   
     Result Dump() const override {
        if(isprimary) {
          return primaryexp->Dump();
        } else {
            Result temp_res = unaryexp->Dump();
            if(temp_res.type == IMM) {
                switch(op) {
                    case '+':
                        return Result(IMM, temp_res.value);
                        break;
                    case '-':
                        return Result(IMM, -temp_res.value);
                        break;
                    case '!':
                        return Result(IMM, !temp_res.value);
                        break;
                    default:
                        return Result(IMM, 0);
                        break;
                }
            }
            Result res = Result(REG, currnum);
            currnum++;
            switch(op) {
                case '+':
                    std::cout << "\t" << res << " = add 0, "<<temp_res<<endl;
                    break;
                case '-':
                    std::cout << "\t" << res << " = sub 0, "<<temp_res<<endl;
                    break;
                case '!':
                    std::cout << "\t" << res << " = eq 0, "<<temp_res<<endl;
                    break;
                default:
                    break;
            }
            return res;
        }
     }
    
};

class AddExpAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> mulexp;
     std::unique_ptr<BaseAST> addexp;
     char op = '+';
     bool only = false;
   
     Result Dump() const override {
        if(!only) {
            Result left_res = addexp->Dump();
            Result right_res = mulexp->Dump();
            if(left_res.type == IMM && right_res.type == IMM) {
                switch(op) {
                    case '+':
                        return Result(IMM, left_res.value + right_res.value);
                        break;
                    case '-':
                        return Result(IMM, left_res.value - right_res.value);
                        break;
                    default:
                        return Result(IMM, 0);
                        break;
                }
            }
            Result res = Result(REG, currnum);
            currnum++;
            
            switch(op) {
                case '+':
                    std::cout << "\t" << res << " = add "<<left_res<<", "<<right_res<<endl;
                    break;
                case '-':
                    std::cout << "\t" << res << " = sub "<<left_res<<", "<<right_res<<endl;
                    break;
                default:
                    break;
            }
            return res;
        } else {
            return mulexp->Dump();
        }
     }
};

class MulExpAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> unaryexp;
     std::unique_ptr<BaseAST> mulexp;
     char op = '*';
     bool only = false;
   
     Result Dump() const override {
        if(!only) {
            Result left_res = mulexp->Dump();
            Result right_res = unaryexp->Dump();
            if(left_res.type == IMM && right_res.type == IMM) {
                switch(op) {
                    case '*':
                        return Result(IMM, left_res.value * right_res.value);
                        break;
                    case '/':
                        return Result(IMM, left_res.value / right_res.value);
                        break;
                    case '%':
                        return Result(IMM, left_res.value % right_res.value);
                        break;
                    default:
                        return Result(IMM, 0);
                        break;
                }
            }
            Result res = Result(REG, currnum);
            currnum++;
            

            switch(op) {
                case '*':
                    std::cout << "\t" << res << " = mul "<<left_res<<", "<<right_res<<endl;
                    break;
                case '/':
                    std::cout << "\t" << res << " = div "<<left_res<<", "<<right_res<<endl;
                    break;
                case '%':
                    std::cout << "\t" << res << " = mod "<<left_res<<", "<<right_res<<endl;
                    break;
                default:
                    break;
            }
            return res;
        } else {
            return unaryexp->Dump();
        }
     }
};

class RelExpAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> addexp;
     std::unique_ptr<BaseAST> relexp;
     std::string op;
     bool only = false;
   
     Result Dump() const override {
        if(!only) {
            Result left_res = relexp->Dump();
            Result right_res = addexp->Dump();
            if(left_res.type == IMM && right_res.type == IMM) {
                if (op == "<") {
                    return Result(IMM, left_res.value < right_res.value);
                } else if (op == ">") {
                    return Result(IMM, left_res.value > right_res.value);
                } else if (op == "<=") {
                    return Result(IMM, left_res.value <= right_res.value);
                } else if (op == ">=") {
                    return Result(IMM, left_res.value >= right_res.value);
                }
            }
            Result res = Result(REG, currnum);
            currnum++;
            

            if (op == "<") {
                std::cout << "\t" << res << " = lt " << left_res << ", " << right_res << std::endl;
            } else if (op == ">") {
                std::cout << "\t" << res << " = gt " << left_res << ", " << right_res<< std::endl;
            } else if (op == "<=") {
                std::cout << "\t" << res << " = le " << left_res << ", " <<right_res<< std::endl;
            } else if (op == ">=") {
                std::cout << "\t" << res << " = ge " << left_res << ", " << right_res<< std::endl;
            }

            return res;
        } else {
            return addexp->Dump();
        }
     }
};

class EqExpAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> relexp;
     std::unique_ptr<BaseAST> eqexp;
     std::string op;
     bool only = false;
   
     Result Dump() const override {
        if(!only) {
            Result left_res = eqexp->Dump();
            Result right_res = relexp->Dump();
            if(left_res.type == IMM && right_res.type == IMM) {
                if (op == "==") {
                    return Result(IMM, left_res.value == right_res.value);
                } else if (op == "!=") {
                    return Result(IMM, left_res.value != right_res.value);
                }
            }
            Result res = Result(REG, currnum);
            currnum++;
            

             if (op == "==") {
            std::cout << "\t" << res << " = eq " << left_res<< ", " << right_res << std::endl;
        } else if (op == "!=") {
            std::cout << "\t" << res << " = ne " << left_res<< ", " << right_res << std::endl;
        }

            return res;
        } else {
            return relexp->Dump();
        }
     }
};

class LAndExpAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> eqexp;
     std::unique_ptr<BaseAST> landexp;
     bool only = false;
   
     Result Dump() const override {
        if(!only) {
            int temp = kop_table.inand;
            kop_table.inand=1;
            if(!temp)kop_table.currand = kop_table.andnum++;
            int currand = kop_table.currand;
            kop_table.andlayer++;
            int curral = kop_table.andlayer;
            kop_table.reca(currand,curral);
            Result left_res = landexp->Dump();
            kop_table.reca(currand,curral);
            if(left_res.type == IMM && left_res.value == 0) {
                return Result(IMM, 0);
            }
            Result res_1 = Result(REG, currnum++);
            kop_table.printandpos();
            
            kop_table.andlayer++;
            std::cout << "\t" << res_1<< " = ne " << left_res << ", 0" << std::endl;
            std::cout << "\tbr " << res_1<< "," << kop_table.printandtrue() << ", "
            <<kop_table.printandfalse()<< std::endl;
            std::cout << kop_table.printandtrue()<<":"<< std::endl;
            Result right_res = eqexp->Dump();
            kop_table.reca(currand,curral);
            Result res_2 = Result(REG, currnum++);
            std::cout << "\t" << res_2 << " = ne 0, "<<right_res<<endl;
            std::cout << "\tstore "<<res_2<<", "<<kop_table.printandpos()<<endl;
            std::cout << "\tjump "<<kop_table.printandend()<<endl;
            std::cout << kop_table.printandfalse()<<":"<< std::endl;
            std::cout << "\tstore 0, "<<kop_table.printandpos()<<endl;
            std::cout << "\tjump "<<kop_table.printandend()<<endl;
            std::cout << kop_table.printandend()<<":"<< std::endl;
            Result res = Result(REG, currnum++);
            std::cout << "\t" << res << " = load "<<kop_table.printandpos()<<endl;
            if(!temp){
                kop_table.inand=0;
                kop_table.andlayer=0;
            }
            return res;
        } else {
            return eqexp->Dump();
        }
     }
};  



class LOrExpAST : public BaseAST {
    public:
     std::unique_ptr<BaseAST> landexp;
     std::unique_ptr<BaseAST> lorexp;
     bool only = false;
   
     Result Dump() const override {
        if(!only) {
            
            int temp = kop_table.inor;
            kop_table.inor=1;
            if(!temp){kop_table.curror = kop_table.ornum++;}
            int curror = kop_table.curror;
            kop_table.orlayer++;
            int currol = kop_table.orlayer;
            kop_table.reco(curror,currol);
            Result left_res = lorexp->Dump();
            kop_table.reco(curror,currol);
            if(left_res.type == IMM && left_res.value != 0) {
                
                return Result(IMM, 1);
            }
            Result res_1 = Result(REG, currnum++);
            kop_table.printopos();
            
            std::cout << "\t" << res_1<< " = ne " << left_res << ", 0" << std::endl;
            std::cout << "\tbr " << res_1<< "," << kop_table.printotrue() << ", " 
            <<kop_table.printofalse()<< std::endl;
            std::cout << kop_table.printotrue()<<":"<< std::endl;
            std::cout << "\tstore 1, "<<kop_table.printopos()<<endl;
            std::cout << "\tjump "<<kop_table.printoend()<<endl;
            std::cout << kop_table.printofalse()<<":"<< std::endl;
            kop_table.initk();
            Result right_res = landexp->Dump();
            kop_table.reco(curror,currol);
            Result res_2 = Result(REG, currnum++);
            std::cout << "\t" << res_2 << " = ne 0, "<<right_res<<endl;
            std::cout << "\tstore "<<res_2<<", "<<kop_table.printopos()<<endl;
            std::cout << "\tjump "<<kop_table.printoend()<<endl;
            std::cout << kop_table.printoend()<<":"<< std::endl;
            Result res = Result(REG, currnum++);
            std::cout << "\t" << res << " = load "<<kop_table.printopos()<<endl;
            if(!temp){
                kop_table.inor=0;
                kop_table.orlayer=0;
            }
            return res;
        } else {
            kop_table.initk();
            return landexp->Dump();
        }
     }
};

