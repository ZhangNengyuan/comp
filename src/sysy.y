%code requires {
  #include "ast.hpp"
  #include <memory>
  #include <string>
}

%{
#include "ast.hpp"
#include <iostream>
#include <memory>
#include <string>

// 声明 lexer 函数和错误处理函数
int yylex();
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s);

using namespace std;

%}

// 定义 parser 函数和错误处理函数的附加参数
// 我们需要返回一个字符串作为 AST, 所以我们把附加参数定义成字符串的智能指针
// 解析完成后, 我们要手动修改这个参数, 把它设置成解析得到的字符串
%parse-param { std::unique_ptr<BaseAST> &ast }

// yylval 的定义, 我们把它定义成了一个联合体 (union)
// 因为 token 的值有的是字符串指针, 有的是整数
// 之前我们在 lexer 中用到的 str_val 和 int_val 就是在这里被定义的
// 至于为什么要用字符串指针而不直接用 string 或者 unique_ptr<string>?
// 请自行 STFW 在 union 里写一个带析构函数的类会出现什么情况
%union {
  std::string *str_val;
  int int_val;
  BaseAST *ast_val;
}

// lexer 返回的所有 token 种类的声明
// 注意 IDENT 和 INT_CONST 会返回 token 的值, 分别对应 str_val 和 int_val
%token INT RETURN CONST IF ELSE WHILE BREAK CONTINUE VOID
%token <str_val> IDENT EQOP RELOP
%token <int_val> INT_CONST

// 非终结符的类型定义
%type <ast_val> FuncDef Block Stmt UnaryExp Exp PrimaryExp MulExp AddExp RelExp EqExp LAndExp LOrExp MultiProDef
%type <ast_val> Decl ConstDecl ConstDef  VarDecl VarDef MultiVarDef InitVal BlockItem LVal LLVal MultiConstDef MultiBlockItem
%type <ast_val> RStmt OStmt MStmt  GlbDecl
%type <ast_val> FuncFParams FuncFParam FuncRParams
%type <ast_val> MatrixParams MulInitVal LMatrixParams MLLVal

%type <int_val> Number

%%

// 开始符, CompUnit ::= FuncDef, 大括号后声明了解析完成后 parser 要做的事情
// 之前我们定义了 FuncDef 会返回一个 str_val, 也就是字符串指针
// 而 parser 一旦解析完 CompUnit, 就说明所有的 token 都被解析了, 即解析结束了
// 此时我们应该把 FuncDef 返回的结果收集起来, 作为 AST 传给调用 parser 的函数
// $1 指代规则里第一个符号的返回值, 也就是 FuncDef 的返回值




CompUnit
  : MultiProDef {
    auto comp_unit = make_unique<CompUnitAST>();
    comp_unit->func_def = unique_ptr<BaseAST>($1);
    ast = move(comp_unit);
  }
  ;

MultiProDef
  : FuncDef MultiProDef{
    auto ast = new MDefAST();
    ast->mdef = unique_ptr<BaseAST>($2);
    ast->def = unique_ptr<BaseAST>($1);
    ast ->keep =1;
    ast -> func=1;
    $$ = ast;
  }
  |FuncDef{
    auto ast = new MDefAST();
    
    ast->def = unique_ptr<BaseAST>($1);
    ast ->keep =0;
    ast -> func=1;
    $$ = ast;
  }|GlbDecl MultiProDef{
    auto ast = new MDefAST();
    ast->mdef = unique_ptr<BaseAST>($2);
    ast->def = unique_ptr<BaseAST>($1);
    ast ->keep =1;
    ast -> func=1;
    $$ = ast;
  }|GlbDecl{
    auto ast = new MDefAST();
    ast->def = unique_ptr<BaseAST>($1);
    ast ->keep =0;
    ast -> func=1;
    $$ = ast;
  }
  ;

FuncDef
  :  INT IDENT '(' ')' Block {
    auto ast = new FuncDefAST();
    ast-> havp =0;

    ast->ident = *unique_ptr<string>($2);
    ast->isint = 1;
    ast->block = unique_ptr<BaseAST>($5);
    $$ = ast;
  }
  | INT IDENT '(' FuncFParams ')' Block {
    auto ast = new FuncDefAST();
    ast-> havp =1;
    ast->isint = 1;
    ast->ident = *unique_ptr<string>($2);
    ast->fps = unique_ptr<BaseAST>($4);
    ast->block = unique_ptr<BaseAST>($6);
    $$ = ast;
  }| VOID IDENT '(' ')' Block {
    auto ast = new FuncDefAST();
    ast-> havp =0;

    ast->ident = *unique_ptr<string>($2);
    ast->block = unique_ptr<BaseAST>($5);
    $$ = ast;
  }
  | VOID IDENT '(' FuncFParams ')' Block {
    auto ast = new FuncDefAST();
    ast-> havp =1;

    ast->ident = *unique_ptr<string>($2);
    ast->fps = unique_ptr<BaseAST>($4);
    ast->block = unique_ptr<BaseAST>($6);
    $$ = ast;
  }
  ;



FuncFParams
  : FuncFParam ',' FuncFParams {
    auto ast = new FuncFParamsAST();
    ast->keep =1;
    ast->fp = unique_ptr<BaseAST>($1);
    ast -> fps =unique_ptr<BaseAST>($3);
    $$ = ast;
  }
  | FuncFParam {
    auto ast = new FuncFParamsAST();
    ast->keep =0;
    ast->fp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  ;

FuncFParam
  : INT IDENT {
    auto ast = new FuncFParamAST();
    ast->ident = *unique_ptr<string>($2);
    $$ = ast;
  }|INT IDENT'['']' {
    auto ast = new FuncFParamMAST();
    ast->ident = *unique_ptr<string>($2);
    ast ->uno=1;
    $$ = ast;}
    |INT IDENT'['']'MatrixParams {
    auto ast = new FuncFParamMAST();
    ast->ident = *unique_ptr<string>($2);
    ast->pr = unique_ptr<BaseAST>($5);
    ast ->uno=0;
    $$ = ast;}
  ;

FuncRParams
  : Exp ',' FuncRParams {
    auto ast = new FuncRParamsAST();
    ast->keep =1;
    ast->fps = unique_ptr<BaseAST>($3);
    ast -> fp =unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  |Exp{
    auto ast = new FuncRParamsAST();
    ast->keep =0;
    ast->fp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  ;



Block
  : '{' MultiBlockItem '}' {
    auto ast = new BlockAST();
    ast->multiblockitem = unique_ptr<BaseAST>($2);
    $$ = ast;
  }
  |'{''}'{
    auto ast = new BlockAST();
    ast->empty=1;
    $$ = ast;
  }
  ;

MultiBlockItem
  : BlockItem{
    auto ast = new MultiBlockItemAST();
    ast->blockitem = unique_ptr<BaseAST>($1);
    ast->keep = 0;
    $$ = ast;
  }
  | BlockItem MultiBlockItem{
    auto ast = new MultiBlockItemAST();
    ast->blockitem = unique_ptr<BaseAST>($1);
    ast->multiblockitem = unique_ptr<BaseAST>($2);
    ast->keep = 1;
    $$ = ast;
  }
  ;

BlockItem
 : Stmt{
  auto ast = new BlockItemAST();
  ast -> stmt = unique_ptr<BaseAST>($1);
  ast -> isstmt = 1;
  $$ = ast;
 }
 |Decl{
  auto ast = new BlockItemAST();
  ast -> decl = unique_ptr<BaseAST>($1);
  ast -> isstmt = 0;
  $$ = ast;
 }
 ;

 Stmt
   :OStmt{
    $$=$1;
   }
   |MStmt{
    $$=$1;
   }
   ;

  MStmt
   :RStmt{
    $$=$1;
   }
   |IF '('Exp')'MStmt ELSE MStmt{
    auto ast = new IfStmtAST();
    ast->ifelse=1;
    ast->exp = unique_ptr<BaseAST>($3);
    ast->tstmt = unique_ptr<BaseAST>($5);
    ast->estmt = unique_ptr<BaseAST>($7);
    $$ = ast;
   }|BREAK ';'{
    auto ast = new BrCoAST();
    ast->isbreak=1;
    $$ = ast;
   }
   |CONTINUE ';'{
    auto ast = new BrCoAST();
    ast->isbreak=0;
    $$ = ast;
   }
   ;
   OStmt
   :IF '('Exp')'MStmt ELSE OStmt{
    auto ast = new IfStmtAST();
    ast->ifelse=1;
    ast->exp = unique_ptr<BaseAST>($3);
    ast->tstmt = unique_ptr<BaseAST>($5);
    ast->estmt = unique_ptr<BaseAST>($7);
    $$ = ast;
   }
   |IF '('Exp')'Stmt{
    auto ast = new IfStmtAST();
    ast->exp = unique_ptr<BaseAST>($3);
    ast->tstmt = unique_ptr<BaseAST>($5);
    $$ = ast;
   }
   
   ;



RStmt
  : RETURN Exp ';' {
    auto ast = new StmtAST();
    ast->exp = unique_ptr<BaseAST>($2);
    ast->ret =1;
    $$ = ast;
  }
  |RETURN ';'{
    auto ast = new StmtAST();
    ast->ret =1;
    ast->empty = 1;
    $$ = ast;
  }
  |LLVal '=' Exp ';'{
    auto ast = new StmtAST();
    ast -> lval = unique_ptr<BaseAST>($1);
    ast->exp = unique_ptr<BaseAST>($3);
    ast->ret =0;
    $$ = ast;
  }
  |Exp ';'{
    auto ast = new StmtAST();
    ast->exp = unique_ptr<BaseAST>($1);
    ast->empty = 2;
    $$ = ast;
  }
  |';'{
    auto ast = new StmtAST();
    ast->empty = 1;
    $$ = ast;
  }
  |Block{
    auto ast = new StmtAST();
    ast->isblock=1;
    ast->exp=unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  |WHILE'('Exp')'Stmt{
    auto ast = new WhileStmtAST();
    ast->exp=unique_ptr<BaseAST>($3);
    ast->stmt=unique_ptr<BaseAST>($5);
    $$ = ast;
  }|MLLVal '=' Exp ';'{
    auto ast = new StmtAST();
    ast -> lval = unique_ptr<BaseAST>($1);
    ast->exp = unique_ptr<BaseAST>($3);
    ast->ret =0;
    ast->ismat=1;
    $$ = ast;
  }
  ;

Decl
  : ConstDecl{
    auto ast = new DeclAST();
    ast-> type = 0;
    ast ->constdecl = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  |VarDecl{
    auto ast = new DeclAST();
    ast-> type = 1;
    ast ->vardecl = unique_ptr<BaseAST>($1);
    $$ = ast;

  }
  ;

  GlbDecl
  : ConstDecl{
    auto ast = new GlbDeclAST();
    ast-> type = 0;
    ast ->constdecl = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  |VarDecl{
    auto ast = new GlbDeclAST();
    ast-> type = 1;
    ast ->vardecl = unique_ptr<BaseAST>($1);
    $$ = ast;

  }
  ;

ConstDecl
  : CONST INT MultiConstDef ';' {
    auto ast = new ConstDeclAST();
    ast->multiconstdef = unique_ptr<BaseAST>($3);
    $$ = ast;
  }
  ;

MultiConstDef
  : ConstDef ',' MultiConstDef {
  auto ast = new MultiConstDefAST();
  ast -> keep = 1;
  ast -> constdef = unique_ptr<BaseAST>($1);
  ast -> multiconstdef = unique_ptr<BaseAST>($3);
  $$ = ast;
}
| ConstDef{
  auto ast = new MultiConstDefAST();
  ast -> keep = 0;
  ast -> constdef = unique_ptr<BaseAST>($1);
  $$ = ast;
}
;

ConstDef
  : IDENT '=' InitVal {
    auto ast = new ConstDefAST();
    ast->ident = *unique_ptr<string>($1);
    ast->constinitval = unique_ptr<BaseAST>($3);
    $$ = ast;
  }|IDENT MatrixParams '=' InitVal {
    auto ast = new ConstDefAST();
    ast->ident = *unique_ptr<string>($1);
    ast -> matp = unique_ptr<BaseAST>($2);
    ast -> defm = 1;
    ast->constinitval = unique_ptr<BaseAST>($4);
    $$ = ast;
  }
  ;

VarDecl
  :INT MultiVarDef ';'{
    auto ast = new VarDeclAST();
    ast->multivardef = unique_ptr<BaseAST>($2);
    $$ = ast;
  }
  ;

MultiVarDef
  : VarDef ',' MultiVarDef {
  auto ast = new MultiVarDefAST();
  ast -> keep = 1;
  ast -> vardef = unique_ptr<BaseAST>($1);
  ast -> multivardef = unique_ptr<BaseAST>($3);
  $$ = ast;
}
| VarDef{
  auto ast = new MultiVarDefAST();
  ast -> keep = 0;
  ast -> vardef = unique_ptr<BaseAST>($1);
  $$ = ast;
}
;

VarDef
  : IDENT '=' InitVal {
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>($1);
    ast->initval = unique_ptr<BaseAST>($3);
    $$ = ast;
  }
  |IDENT{
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>($1);
    ast->num =0;
    $$ = ast;
  }|IDENT MatrixParams'=' InitVal {
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>($1);
    ast -> matp = unique_ptr<BaseAST>($2);
    ast->initval = unique_ptr<BaseAST>($4);
    ast -> defm =1;
    $$ = ast;
  }
  |IDENT MatrixParams{
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>($1);
    ast -> matp = unique_ptr<BaseAST>($2);
    ast -> defm =1;
    ast->num =0;
    $$ = ast;
  }
  ;

InitVal
  :Exp{
    auto ast = new InitValAST();
    ast->exp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }|'{'MulInitVal'}'{
    auto ast = new InitValAST();
    ast->exp = unique_ptr<BaseAST>($2);
    ast -> keep = 1;
    $$ = ast;
  }|'{''}'{
    auto ast = new InitValAST();
    ast -> keep = 2;
    $$ = ast;
  }
  ;

MulInitVal
  : InitVal{
    auto ast = new MulInitValAST();
    ast->exp = unique_ptr<BaseAST>($1);
    ast -> keep = 0;
    $$ = ast;
  }|InitVal','MulInitVal{
    auto ast = new MulInitValAST();
    ast->exp = unique_ptr<BaseAST>($1);
    ast->kexp = unique_ptr<BaseAST>($3);
    ast -> keep = 1;
    $$ = ast;
  }
  ;


Number
  : INT_CONST {
    $$ = $1;
  }
  ;


Exp
  : LOrExp {
    auto ast = new ExpAST();
    ast->lorexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  ;

PrimaryExp
  : '(' Exp ')'{
    auto ast = new PrimaryExpAST();
    ast -> isnumber = 0;
    ast->exp = unique_ptr<BaseAST>($2);
    $$ = ast;
  }
  |Number{
    auto ast = new PrimaryExpAST();
    ast -> isnumber = 1;
    ast->number = std::make_unique<NumberAST>($1);
    $$ = ast;
  }
  |LVal{
    auto ast = new PrimaryExpAST();
    ast -> isnumber = 2;
    ast->lval = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  ;


UnaryExp
  : PrimaryExp{
    auto ast = new UnaryExpAST();
    ast -> isprimary = 1;
    ast->primaryexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  |'+' UnaryExp{
    auto ast = new UnaryExpAST();
    ast -> isprimary = 0;
    ast -> op = '+';
    ast -> unaryexp = unique_ptr<BaseAST>($2);
    $$ = ast;
  }|'-' UnaryExp{
    auto ast = new UnaryExpAST();
    ast -> isprimary = 0;
    ast -> op = '-';
    ast -> unaryexp = unique_ptr<BaseAST>($2);
    $$ = ast;
  }|'!' UnaryExp{
    auto ast = new UnaryExpAST();
    ast -> isprimary = 0;
    ast -> op = '!';
    ast -> unaryexp = unique_ptr<BaseAST>($2);
    $$ = ast;
  }|IDENT '('')'{
    auto ast = new DoncicExpAST();
    ast->ident = *unique_ptr<string>($1);
    ast->havp = 0;
    $$ = ast;
  }|IDENT '(' FuncRParams ')'{
    auto ast = new DoncicExpAST();
    ast->ident = *unique_ptr<string>($1);
    ast -> hps = unique_ptr<BaseAST>($3);
    ast->havp = 1;
    $$ = ast;
  }
  ;

MulExp
  : UnaryExp{
    auto ast = new MulExpAST();
    ast -> only = 1;
    ast -> unaryexp = unique_ptr<BaseAST>($1);
    $$ = ast;

  }
  |MulExp '%' UnaryExp{
    auto ast = new MulExpAST();
    ast -> only = 0;
    ast -> mulexp = unique_ptr<BaseAST>($1);
    ast -> op = '%';
    ast -> unaryexp = unique_ptr<BaseAST>($3);
    $$ = ast;
  }|MulExp '*' UnaryExp{
    auto ast = new MulExpAST();
    ast -> only = 0;
    ast -> mulexp = unique_ptr<BaseAST>($1);
    ast -> op = '*';
    ast -> unaryexp = unique_ptr<BaseAST>($3);
    $$ = ast;
  }|MulExp '/'UnaryExp{
    auto ast = new MulExpAST();
    ast -> only = 0;
    ast -> mulexp = unique_ptr<BaseAST>($1);
    ast -> op = '/';
    ast -> unaryexp = unique_ptr<BaseAST>($3);
    $$ = ast;
  }
  ;

AddExp
  : MulExp{
    auto ast = new AddExpAST();
    ast -> only = 1;
    ast -> mulexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  |AddExp '-' MulExp{
    auto ast = new AddExpAST();
    ast -> only = 0;
    ast -> addexp = unique_ptr<BaseAST>($1);
    ast -> op = '-';
    ast -> mulexp = unique_ptr<BaseAST>($3);
    $$ = ast;
  }|AddExp '+' MulExp{
    auto ast = new AddExpAST();
    ast -> only = 0;
    ast -> addexp = unique_ptr<BaseAST>($1);
    ast -> op = '+';
    ast -> mulexp = unique_ptr<BaseAST>($3);
    $$ = ast;
  }
  ;

RelExp
  : AddExp{
    auto ast = new RelExpAST();
    ast -> only =1;
    ast -> addexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  |RelExp RELOP AddExp{
    auto ast = new RelExpAST();
    ast -> only =0;
    ast -> relexp = unique_ptr<BaseAST>($1);
    ast->op = *($2);
    ast -> addexp = unique_ptr<BaseAST>($3);
    $$ = ast;
    
  }
  ;

EqExp
  : RelExp{
    auto ast = new EqExpAST();
    ast -> only =1;
    ast -> relexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  |EqExp EQOP RelExp{
    auto ast = new EqExpAST();
    ast -> only =0;
    ast -> eqexp = unique_ptr<BaseAST>($1);
    ast->op = *($2);
    ast -> relexp = unique_ptr<BaseAST>($3);
    $$ = ast;
    
  }
  ;

LAndExp
  : EqExp{
    auto ast = new LAndExpAST();
    ast -> only =1;
    ast -> eqexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  |LAndExp '&''&' EqExp{
    auto ast = new LAndExpAST();
    ast -> only =0;
    ast -> landexp = unique_ptr<BaseAST>($1);
    ast -> eqexp = unique_ptr<BaseAST>($4);
    $$ = ast;
    
  }
  ;



LOrExp
  : LAndExp{
    auto ast = new LOrExpAST();
    ast -> only =1;
    ast -> landexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  |LOrExp '|''|' LAndExp{
    auto ast = new LOrExpAST();
    ast -> only =0;
    ast -> lorexp = unique_ptr<BaseAST>($1);
    ast -> landexp = unique_ptr<BaseAST>($4);
    $$ = ast;
    
  }
  ;



LVal
  :IDENT{
    auto ast = new LValAST();
    ast->ident = *unique_ptr<string>($1);
    $$ = ast;
  }|IDENT LMatrixParams{
    auto ast = new LValAST();
    ast->ident = *unique_ptr<string>($1);
    ast->matp = unique_ptr<BaseAST>($2);
    ast->defm = 1;
    $$ = ast;
  };

LLVal
  :IDENT{
    auto ast = new LLValAST();
    ast->ident = *unique_ptr<string>($1);
    $$ = ast;
  };
  
MLLVal
    :IDENT LMatrixParams{
    auto ast = new MLLValAST();
    ast->ident = *unique_ptr<string>($1);
    ast->matp = unique_ptr<BaseAST>($2);
    $$ = ast;
  };

  MatrixParams
  :'['Exp']'{
    auto ast = new MatrixParamsAST();
    ast -> keep =0;
    ast-> exp = unique_ptr<BaseAST>($2);
    $$ = ast;
  }
  |'['Exp']'MatrixParams{
    auto ast = new MatrixParamsAST();
    ast -> keep = 1;
    ast-> exp = unique_ptr<BaseAST>($2);
    ast-> mparams = unique_ptr<BaseAST>($4);
    $$ = ast;
  };

  LMatrixParams
  :'['Exp']'{
    auto ast = new LMatrixParamsAST();
    ast -> keep =0;
    ast-> exp = unique_ptr<BaseAST>($2);
    $$ = ast;
  }
  |'['Exp']'LMatrixParams{
    auto ast = new LMatrixParamsAST();
    ast -> keep = 1;
    ast-> exp = unique_ptr<BaseAST>($2);
    ast-> mparams = unique_ptr<BaseAST>($4);
    $$ = ast;
  };



%%

// 定义错误处理函数, 其中第二个参数是错误信息
// parser 如果发生错误 (例如输入的程序出现了语法错误), 就会调用这个函数
void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  cerr << "error: " << s << endl;
}
