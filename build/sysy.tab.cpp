/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "/root/compiler/sysy-make-template/src/sysy.y"

#include "ast.hpp"
#include <iostream>
#include <memory>
#include <string>

// 声明 lexer 函数和错误处理函数
int yylex();
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s);

using namespace std;


#line 84 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ROOT_COMPILER_SYSY_MAKE_TEMPLATE_BUILD_SYSY_TAB_HPP_INCLUDED
# define YY_YY_ROOT_COMPILER_SYSY_MAKE_TEMPLATE_BUILD_SYSY_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "/root/compiler/sysy-make-template/src/sysy.y"

  #include "ast.hpp"
  #include <memory>
  #include <string>

#line 133 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    RETURN = 259,
    CONST = 260,
    IF = 261,
    ELSE = 262,
    WHILE = 263,
    BREAK = 264,
    CONTINUE = 265,
    VOID = 266,
    IDENT = 267,
    EQOP = 268,
    RELOP = 269,
    INT_CONST = 270
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "/root/compiler/sysy-make-template/src/sysy.y"

  std::string *str_val;
  int int_val;
  BaseAST *ast_val;

#line 166 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::unique_ptr<BaseAST> &ast);

#endif /* !YY_YY_ROOT_COMPILER_SYSY_MAKE_TEMPLATE_BUILD_SYSY_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

#define YYUNDEFTOK  2
#define YYMAXUTOK   270


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,     2,     2,    28,    31,     2,
      16,    17,    29,    25,    18,    26,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,     2,    20,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,    32,    22,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    72,    80,    87,    94,   104,   113,   121,
     129,   143,   150,   159,   163,   168,   177,   184,   195,   200,
     208,   214,   224,   230,   239,   242,   248,   251,   258,   263,
     270,   278,   290,   296,   302,   309,   315,   320,   326,   331,
     342,   348,   358,   364,   374,   382,   389,   398,   403,   414,
     422,   429,   438,   444,   449,   457,   468,   472,   477,   485,
     490,   501,   508,   516,   522,   528,   538,   544,   550,   556,
     562,   567,   577,   584,   591,   598,   609,   615,   622,   633,
     639,   651,   657,   669,   675,   688,   694,   707,   711,   720,
     727,   735,   741,   750,   756
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "RETURN", "CONST", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "VOID", "IDENT", "EQOP", "RELOP",
  "INT_CONST", "'('", "')'", "','", "'['", "']'", "'{'", "'}'", "';'",
  "'='", "'+'", "'-'", "'!'", "'%'", "'*'", "'/'", "'&'", "'|'", "$accept",
  "CompUnit", "MultiProDef", "FuncDef", "FuncFParams", "FuncFParam",
  "FuncRParams", "Block", "MultiBlockItem", "BlockItem", "Stmt", "MStmt",
  "OStmt", "RStmt", "Decl", "GlbDecl", "ConstDecl", "MultiConstDef",
  "ConstDef", "VarDecl", "MultiVarDef", "VarDef", "InitVal", "MulInitVal",
  "Number", "Exp", "PrimaryExp", "UnaryExp", "MulExp", "AddExp", "RelExp",
  "EqExp", "LAndExp", "LOrExp", "LVal", "LLVal", "MLLVal", "MatrixParams",
  "LMatrixParams", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    40,    41,    44,    91,
      93,   123,   125,    59,    61,    43,    45,    33,    37,    42,
      47,    38,   124
};
# endif

#define YYPACT_NINF (-159)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-91)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,    -4,    11,    33,    21,  -159,    49,    49,  -159,  -159,
      16,    30,    37,    67,    72,  -159,  -159,  -159,     7,   176,
      84,    73,  -159,    80,    12,    75,    83,     8,    90,    93,
      87,    94,    23,  -159,   176,   176,   176,   176,  -159,    95,
    -159,  -159,    38,     4,   105,   109,    92,    98,  -159,     1,
    -159,  -159,    84,    22,  -159,    84,   100,  -159,    67,    93,
     108,   107,    68,  -159,    93,   124,    91,   176,  -159,   115,
    -159,  -159,  -159,   114,   176,   176,   176,   176,   176,   176,
     176,   111,   106,  -159,   130,   127,  -159,  -159,    84,  -159,
    -159,    93,   133,    80,   171,   134,   139,   137,   143,    45,
    -159,  -159,  -159,   140,   131,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,   145,   148,   149,  -159,  -159,  -159,   152,   156,
     157,  -159,  -159,  -159,  -159,  -159,    38,    38,     4,   105,
     176,   176,    84,  -159,  -159,  -159,   114,  -159,   161,   176,
     176,  -159,  -159,   151,  -159,  -159,  -159,   176,   176,  -159,
     176,   160,   109,    92,  -159,  -159,  -159,   168,   172,   167,
     170,  -159,  -159,   155,   155,  -159,  -159,  -159,   188,  -159,
     155,  -159,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,    42,    43,
      53,     0,    51,     0,     0,     1,     3,     5,     0,     0,
       0,    55,    49,     0,     0,     0,    46,     0,     0,     0,
       0,    12,    87,    61,     0,     0,     0,     0,    64,     0,
      66,    72,    76,    79,    81,    83,    85,    62,    65,     0,
      52,    56,     0,    53,    50,     0,     0,    44,     0,     0,
       0,    13,     0,     7,     0,     0,     0,     0,    88,     0,
      67,    68,    69,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,     0,    54,    47,     0,    45,
       9,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      19,    36,    37,     0,    20,    22,    25,    24,    26,    23,
      40,    41,     0,     0,     0,     8,    11,    70,     0,    17,
       0,    63,    92,    73,    74,    75,    78,    77,    80,    82,
       0,     0,     0,    57,    48,    10,    14,    33,     0,     0,
       0,    28,    29,    88,    18,    21,    35,     0,     0,    71,
       0,    93,    84,    86,    60,    15,    32,     0,     0,     0,
       0,    16,    94,     0,     0,    34,    39,    31,    25,    38,
       0,    27,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,    56,  -159,   -21,  -159,    50,   -26,   101,  -159,
     -82,  -158,    29,  -159,  -159,  -159,   -55,   146,  -159,   -53,
     183,  -159,   -18,    76,  -159,   -19,  -159,   -17,     9,   128,
     129,    81,    79,  -159,  -159,  -159,  -159,   -23,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    30,    31,   118,   102,   103,   104,
     105,   106,   107,   108,   109,     7,     8,    25,    26,     9,
      11,    12,    84,    85,    38,    51,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   113,   114,    21,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    56,    50,    63,   143,   168,    60,   110,    10,   111,
      28,    28,   171,    32,    13,    69,    33,    34,    70,    71,
      72,    15,    49,    83,    29,    59,    35,    36,    37,    77,
      78,    19,    18,    90,    86,    19,    55,    87,   115,    66,
      20,    19,    67,   112,   116,    14,    20,   119,   120,   110,
     122,   111,     1,    22,     2,    23,   162,   123,   124,   125,
       3,    66,    16,    17,    67,   135,    74,    75,    76,   -89,
     134,    93,    94,     2,    95,   138,    96,    97,    98,    24,
      99,   167,   169,    33,    34,   112,   126,   127,    27,    62,
     100,   101,    53,    35,    36,    37,    32,    52,    57,    33,
      34,    58,    61,    32,    64,    49,    33,    34,   117,    35,
      36,    37,    65,   155,    62,    73,    35,    36,    37,    79,
     157,   158,    80,    81,    88,    91,    92,    28,   159,   160,
      82,   119,   121,    19,    93,    94,     2,    95,   131,    96,
      97,    98,   130,    99,   112,   112,    33,    34,   132,   133,
     139,   112,    62,   136,   101,   140,    35,    36,    37,    94,
     141,    95,   144,    96,    97,    98,   142,    99,   146,   149,
      33,    34,   147,   148,   150,   -90,    62,   151,   101,    67,
      35,    36,    37,    32,   156,   163,    33,    34,    32,   164,
     165,    33,    34,   166,   137,   170,    35,    36,    37,   172,
     161,    35,    36,    37,    89,   145,    54,   128,   154,   129,
     153,   152
};

static const yytype_uint8 yycheck[] =
{
      19,    24,    20,    29,    99,   163,    27,    62,    12,    62,
       3,     3,   170,    12,     3,    34,    15,    16,    35,    36,
      37,     0,    21,    22,    17,    17,    25,    26,    27,    25,
      26,    19,    16,    59,    52,    19,    24,    55,    64,    16,
      24,    19,    19,    62,    65,    12,    24,    66,    67,   104,
      73,   104,     3,    23,     5,    18,   151,    74,    75,    76,
      11,    16,     6,     7,    19,    91,    28,    29,    30,    24,
      88,     3,     4,     5,     6,    94,     8,     9,    10,    12,
      12,   163,   164,    15,    16,   104,    77,    78,    16,    21,
      22,    23,    12,    25,    26,    27,    12,    24,    23,    15,
      16,    18,    12,    12,    17,    21,    15,    16,    17,    25,
      26,    27,    18,   136,    21,    20,    25,    26,    27,    14,
     139,   140,    13,    31,    24,    17,    19,     3,   147,   148,
      32,   150,    17,    19,     3,     4,     5,     6,    32,     8,
       9,    10,    31,    12,   163,   164,    15,    16,    18,    22,
      16,   170,    21,    20,    23,    16,    25,    26,    27,     4,
      23,     6,    22,     8,     9,    10,    23,    12,    23,    17,
      15,    16,    24,    24,    18,    24,    21,    20,    23,    19,
      25,    26,    27,    12,    23,    17,    15,    16,    12,    17,
      23,    15,    16,    23,    23,     7,    25,    26,    27,   170,
     150,    25,    26,    27,    58,   104,    23,    79,   132,    80,
     131,   130
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    11,    34,    35,    36,    48,    49,    52,
      12,    53,    54,     3,    12,     0,    35,    35,    16,    19,
      24,    70,    23,    18,    12,    50,    51,    16,     3,    17,
      37,    38,    12,    15,    16,    25,    26,    27,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    21,
      55,    58,    24,    12,    53,    24,    70,    23,    18,    17,
      37,    12,    21,    40,    17,    18,    16,    19,    71,    58,
      60,    60,    60,    20,    28,    29,    30,    25,    26,    14,
      13,    31,    32,    22,    55,    56,    55,    55,    24,    50,
      40,    17,    19,     3,     4,     6,     8,     9,    10,    12,
      22,    23,    40,    41,    42,    43,    44,    45,    46,    47,
      49,    52,    58,    68,    69,    40,    37,    17,    39,    58,
      58,    17,    70,    60,    60,    60,    61,    61,    62,    63,
      31,    32,    18,    22,    55,    40,    20,    23,    58,    16,
      16,    23,    23,    71,    22,    41,    23,    24,    24,    17,
      18,    20,    64,    65,    56,    70,    23,    58,    58,    58,
      58,    39,    71,    17,    17,    23,    23,    43,    44,    43,
       7,    44,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    35,    35,    36,    36,    36,
      36,    37,    37,    38,    38,    38,    39,    39,    40,    40,
      41,    41,    42,    42,    43,    43,    44,    44,    44,    44,
      45,    45,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    48,    48,    49,    50,    50,    51,    51,    52,
      53,    53,    54,    54,    54,    54,    55,    55,    55,    56,
      56,    57,    58,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    61,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      69,    70,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     5,     6,     5,
       6,     3,     1,     2,     4,     5,     3,     1,     3,     2,
       1,     2,     1,     1,     1,     1,     1,     7,     2,     2,
       7,     5,     3,     2,     4,     2,     1,     1,     5,     4,
       1,     1,     1,     1,     4,     3,     1,     3,     4,     3,
       3,     1,     3,     1,     4,     2,     1,     3,     2,     1,
       3,     1,     1,     3,     1,     1,     1,     2,     2,     2,
       3,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     4,     1,     4,     1,     2,     1,
       2,     3,     4,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (ast, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, ast); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (ast);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, ast);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, std::unique_ptr<BaseAST> &ast)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , ast);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  YYUSE (yyvaluep);
  YYUSE (ast);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::unique_ptr<BaseAST> &ast)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 64 "/root/compiler/sysy-make-template/src/sysy.y"
                {
    auto comp_unit = make_unique<CompUnitAST>();
    comp_unit->func_def = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast = move(comp_unit);
  }
#line 1474 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 3:
#line 72 "/root/compiler/sysy-make-template/src/sysy.y"
                       {
    auto ast = new MDefAST();
    ast->mdef = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast->def = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    ast ->keep =1;
    ast -> func=1;
    (yyval.ast_val) = ast;
  }
#line 1487 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 4:
#line 80 "/root/compiler/sysy-make-template/src/sysy.y"
          {
    auto ast = new MDefAST();
    
    ast->def = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast ->keep =0;
    ast -> func=1;
    (yyval.ast_val) = ast;
  }
#line 1500 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 5:
#line 87 "/root/compiler/sysy-make-template/src/sysy.y"
                       {
    auto ast = new MDefAST();
    ast->mdef = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast->def = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    ast ->keep =1;
    ast -> func=1;
    (yyval.ast_val) = ast;
  }
#line 1513 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 6:
#line 94 "/root/compiler/sysy-make-template/src/sysy.y"
           {
    auto ast = new MDefAST();
    ast->def = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast ->keep =0;
    ast -> func=1;
    (yyval.ast_val) = ast;
  }
#line 1525 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 7:
#line 104 "/root/compiler/sysy-make-template/src/sysy.y"
                             {
    auto ast = new FuncDefAST();
    ast-> havp =0;

    ast->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    ast->isint = 1;
    ast->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1539 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 8:
#line 113 "/root/compiler/sysy-make-template/src/sysy.y"
                                        {
    auto ast = new FuncDefAST();
    ast-> havp =1;
    ast->isint = 1;
    ast->ident = *unique_ptr<string>((yyvsp[-4].str_val));
    ast->fps = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1553 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 9:
#line 121 "/root/compiler/sysy-make-template/src/sysy.y"
                              {
    auto ast = new FuncDefAST();
    ast-> havp =0;

    ast->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    ast->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1566 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 10:
#line 129 "/root/compiler/sysy-make-template/src/sysy.y"
                                         {
    auto ast = new FuncDefAST();
    ast-> havp =1;

    ast->ident = *unique_ptr<string>((yyvsp[-4].str_val));
    ast->fps = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1580 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 11:
#line 143 "/root/compiler/sysy-make-template/src/sysy.y"
                               {
    auto ast = new FuncFParamsAST();
    ast->keep =1;
    ast->fp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast -> fps =unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1592 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 12:
#line 150 "/root/compiler/sysy-make-template/src/sysy.y"
               {
    auto ast = new FuncFParamsAST();
    ast->keep =0;
    ast->fp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1603 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 13:
#line 159 "/root/compiler/sysy-make-template/src/sysy.y"
              {
    auto ast = new FuncFParamAST();
    ast->ident = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = ast;
  }
#line 1613 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 14:
#line 163 "/root/compiler/sysy-make-template/src/sysy.y"
                    {
    auto ast = new FuncFParamMAST();
    ast->ident = *unique_ptr<string>((yyvsp[-2].str_val));
    ast ->uno=1;
    (yyval.ast_val) = ast;}
#line 1623 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 15:
#line 168 "/root/compiler/sysy-make-template/src/sysy.y"
                                 {
    auto ast = new FuncFParamMAST();
    ast->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    ast->pr = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast ->uno=0;
    (yyval.ast_val) = ast;}
#line 1634 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 16:
#line 177 "/root/compiler/sysy-make-template/src/sysy.y"
                        {
    auto ast = new FuncRParamsAST();
    ast->keep =1;
    ast->fps = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast -> fp =unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1646 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 17:
#line 184 "/root/compiler/sysy-make-template/src/sysy.y"
      {
    auto ast = new FuncRParamsAST();
    ast->keep =0;
    ast->fp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1657 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 18:
#line 195 "/root/compiler/sysy-make-template/src/sysy.y"
                           {
    auto ast = new BlockAST();
    ast->multiblockitem = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1667 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 19:
#line 200 "/root/compiler/sysy-make-template/src/sysy.y"
         {
    auto ast = new BlockAST();
    ast->empty=1;
    (yyval.ast_val) = ast;
  }
#line 1677 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 20:
#line 208 "/root/compiler/sysy-make-template/src/sysy.y"
             {
    auto ast = new MultiBlockItemAST();
    ast->blockitem = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast->keep = 0;
    (yyval.ast_val) = ast;
  }
#line 1688 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 21:
#line 214 "/root/compiler/sysy-make-template/src/sysy.y"
                            {
    auto ast = new MultiBlockItemAST();
    ast->blockitem = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    ast->multiblockitem = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast->keep = 1;
    (yyval.ast_val) = ast;
  }
#line 1700 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 22:
#line 224 "/root/compiler/sysy-make-template/src/sysy.y"
       {
  auto ast = new BlockItemAST();
  ast -> stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  ast -> isstmt = 1;
  (yyval.ast_val) = ast;
 }
#line 1711 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 23:
#line 230 "/root/compiler/sysy-make-template/src/sysy.y"
      {
  auto ast = new BlockItemAST();
  ast -> decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  ast -> isstmt = 0;
  (yyval.ast_val) = ast;
 }
#line 1722 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 24:
#line 239 "/root/compiler/sysy-make-template/src/sysy.y"
         {
    (yyval.ast_val)=(yyvsp[0].ast_val);
   }
#line 1730 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 25:
#line 242 "/root/compiler/sysy-make-template/src/sysy.y"
         {
    (yyval.ast_val)=(yyvsp[0].ast_val);
   }
#line 1738 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 26:
#line 248 "/root/compiler/sysy-make-template/src/sysy.y"
         {
    (yyval.ast_val)=(yyvsp[0].ast_val);
   }
#line 1746 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 27:
#line 251 "/root/compiler/sysy-make-template/src/sysy.y"
                                {
    auto ast = new IfStmtAST();
    ast->ifelse=1;
    ast->exp = unique_ptr<BaseAST>((yyvsp[-4].ast_val));
    ast->tstmt = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->estmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
   }
#line 1759 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 28:
#line 258 "/root/compiler/sysy-make-template/src/sysy.y"
              {
    auto ast = new BrCoAST();
    ast->isbreak=1;
    (yyval.ast_val) = ast;
   }
#line 1769 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 29:
#line 263 "/root/compiler/sysy-make-template/src/sysy.y"
                {
    auto ast = new BrCoAST();
    ast->isbreak=0;
    (yyval.ast_val) = ast;
   }
#line 1779 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 30:
#line 270 "/root/compiler/sysy-make-template/src/sysy.y"
                                {
    auto ast = new IfStmtAST();
    ast->ifelse=1;
    ast->exp = unique_ptr<BaseAST>((yyvsp[-4].ast_val));
    ast->tstmt = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->estmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
   }
#line 1792 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 31:
#line 278 "/root/compiler/sysy-make-template/src/sysy.y"
                    {
    auto ast = new IfStmtAST();
    ast->exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->tstmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
   }
#line 1803 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 32:
#line 290 "/root/compiler/sysy-make-template/src/sysy.y"
                   {
    auto ast = new StmtAST();
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    ast->ret =1;
    (yyval.ast_val) = ast;
  }
#line 1814 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 33:
#line 296 "/root/compiler/sysy-make-template/src/sysy.y"
             {
    auto ast = new StmtAST();
    ast->ret =1;
    ast->empty = 1;
    (yyval.ast_val) = ast;
  }
#line 1825 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 34:
#line 302 "/root/compiler/sysy-make-template/src/sysy.y"
                    {
    auto ast = new StmtAST();
    ast -> lval = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    ast->ret =0;
    (yyval.ast_val) = ast;
  }
#line 1837 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 35:
#line 309 "/root/compiler/sysy-make-template/src/sysy.y"
          {
    auto ast = new StmtAST();
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    ast->empty = 2;
    (yyval.ast_val) = ast;
  }
#line 1848 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 36:
#line 315 "/root/compiler/sysy-make-template/src/sysy.y"
      {
    auto ast = new StmtAST();
    ast->empty = 1;
    (yyval.ast_val) = ast;
  }
#line 1858 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 37:
#line 320 "/root/compiler/sysy-make-template/src/sysy.y"
        {
    auto ast = new StmtAST();
    ast->isblock=1;
    ast->exp=unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1869 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 38:
#line 326 "/root/compiler/sysy-make-template/src/sysy.y"
                     {
    auto ast = new WhileStmtAST();
    ast->exp=unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->stmt=unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1880 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 39:
#line 331 "/root/compiler/sysy-make-template/src/sysy.y"
                      {
    auto ast = new StmtAST();
    ast -> lval = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    ast->ret =0;
    ast->ismat=1;
    (yyval.ast_val) = ast;
  }
#line 1893 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 40:
#line 342 "/root/compiler/sysy-make-template/src/sysy.y"
             {
    auto ast = new DeclAST();
    ast-> type = 0;
    ast ->constdecl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1904 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 41:
#line 348 "/root/compiler/sysy-make-template/src/sysy.y"
          {
    auto ast = new DeclAST();
    ast-> type = 1;
    ast ->vardecl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;

  }
#line 1916 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 42:
#line 358 "/root/compiler/sysy-make-template/src/sysy.y"
             {
    auto ast = new GlbDeclAST();
    ast-> type = 0;
    ast ->constdecl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1927 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 43:
#line 364 "/root/compiler/sysy-make-template/src/sysy.y"
          {
    auto ast = new GlbDeclAST();
    ast-> type = 1;
    ast ->vardecl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;

  }
#line 1939 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 44:
#line 374 "/root/compiler/sysy-make-template/src/sysy.y"
                                {
    auto ast = new ConstDeclAST();
    ast->multiconstdef = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1949 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 45:
#line 382 "/root/compiler/sysy-make-template/src/sysy.y"
                               {
  auto ast = new MultiConstDefAST();
  ast -> keep = 1;
  ast -> constdef = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
  ast -> multiconstdef = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
}
#line 1961 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 46:
#line 389 "/root/compiler/sysy-make-template/src/sysy.y"
          {
  auto ast = new MultiConstDefAST();
  ast -> keep = 0;
  ast -> constdef = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
}
#line 1972 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 47:
#line 398 "/root/compiler/sysy-make-template/src/sysy.y"
                      {
    auto ast = new ConstDefAST();
    ast->ident = *unique_ptr<string>((yyvsp[-2].str_val));
    ast->constinitval = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1983 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 48:
#line 403 "/root/compiler/sysy-make-template/src/sysy.y"
                                   {
    auto ast = new ConstDefAST();
    ast->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    ast -> matp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast -> defm = 1;
    ast->constinitval = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1996 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 49:
#line 414 "/root/compiler/sysy-make-template/src/sysy.y"
                      {
    auto ast = new VarDeclAST();
    ast->multivardef = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2006 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 50:
#line 422 "/root/compiler/sysy-make-template/src/sysy.y"
                           {
  auto ast = new MultiVarDefAST();
  ast -> keep = 1;
  ast -> vardef = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
  ast -> multivardef = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
}
#line 2018 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 51:
#line 429 "/root/compiler/sysy-make-template/src/sysy.y"
        {
  auto ast = new MultiVarDefAST();
  ast -> keep = 0;
  ast -> vardef = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
}
#line 2029 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 52:
#line 438 "/root/compiler/sysy-make-template/src/sysy.y"
                      {
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>((yyvsp[-2].str_val));
    ast->initval = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2040 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 53:
#line 444 "/root/compiler/sysy-make-template/src/sysy.y"
        {
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>((yyvsp[0].str_val));
    ast->num =0;
    (yyval.ast_val) = ast;
  }
#line 2051 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 54:
#line 449 "/root/compiler/sysy-make-template/src/sysy.y"
                                  {
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    ast -> matp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->initval = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast -> defm =1;
    (yyval.ast_val) = ast;
  }
#line 2064 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 55:
#line 457 "/root/compiler/sysy-make-template/src/sysy.y"
                     {
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>((yyvsp[-1].str_val));
    ast -> matp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast -> defm =1;
    ast->num =0;
    (yyval.ast_val) = ast;
  }
#line 2077 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 56:
#line 468 "/root/compiler/sysy-make-template/src/sysy.y"
      {
    auto ast = new InitValAST();
    ast->exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2087 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 57:
#line 472 "/root/compiler/sysy-make-template/src/sysy.y"
                    {
    auto ast = new InitValAST();
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    ast -> keep = 1;
    (yyval.ast_val) = ast;
  }
#line 2098 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 58:
#line 477 "/root/compiler/sysy-make-template/src/sysy.y"
          {
    auto ast = new InitValAST();
    ast -> keep = 2;
    (yyval.ast_val) = ast;
  }
#line 2108 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 59:
#line 485 "/root/compiler/sysy-make-template/src/sysy.y"
           {
    auto ast = new MulInitValAST();
    ast->exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast -> keep = 0;
    (yyval.ast_val) = ast;
  }
#line 2119 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 60:
#line 490 "/root/compiler/sysy-make-template/src/sysy.y"
                        {
    auto ast = new MulInitValAST();
    ast->exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->kexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast -> keep = 1;
    (yyval.ast_val) = ast;
  }
#line 2131 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 61:
#line 501 "/root/compiler/sysy-make-template/src/sysy.y"
              {
    (yyval.int_val) = (yyvsp[0].int_val);
  }
#line 2139 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 62:
#line 508 "/root/compiler/sysy-make-template/src/sysy.y"
           {
    auto ast = new ExpAST();
    ast->lorexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2149 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 63:
#line 516 "/root/compiler/sysy-make-template/src/sysy.y"
               {
    auto ast = new PrimaryExpAST();
    ast -> isnumber = 0;
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2160 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 64:
#line 522 "/root/compiler/sysy-make-template/src/sysy.y"
         {
    auto ast = new PrimaryExpAST();
    ast -> isnumber = 1;
    ast->number = std::make_unique<NumberAST>((yyvsp[0].int_val));
    (yyval.ast_val) = ast;
  }
#line 2171 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 65:
#line 528 "/root/compiler/sysy-make-template/src/sysy.y"
       {
    auto ast = new PrimaryExpAST();
    ast -> isnumber = 2;
    ast->lval = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2182 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 66:
#line 538 "/root/compiler/sysy-make-template/src/sysy.y"
              {
    auto ast = new UnaryExpAST();
    ast -> isprimary = 1;
    ast->primaryexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2193 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 67:
#line 544 "/root/compiler/sysy-make-template/src/sysy.y"
               {
    auto ast = new UnaryExpAST();
    ast -> isprimary = 0;
    ast -> op = '+';
    ast -> unaryexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2205 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 68:
#line 550 "/root/compiler/sysy-make-template/src/sysy.y"
                {
    auto ast = new UnaryExpAST();
    ast -> isprimary = 0;
    ast -> op = '-';
    ast -> unaryexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2217 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 69:
#line 556 "/root/compiler/sysy-make-template/src/sysy.y"
                {
    auto ast = new UnaryExpAST();
    ast -> isprimary = 0;
    ast -> op = '!';
    ast -> unaryexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2229 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 70:
#line 562 "/root/compiler/sysy-make-template/src/sysy.y"
                {
    auto ast = new DoncicExpAST();
    ast->ident = *unique_ptr<string>((yyvsp[-2].str_val));
    ast->havp = 0;
    (yyval.ast_val) = ast;
  }
#line 2240 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 71:
#line 567 "/root/compiler/sysy-make-template/src/sysy.y"
                             {
    auto ast = new DoncicExpAST();
    ast->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    ast -> hps = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    ast->havp = 1;
    (yyval.ast_val) = ast;
  }
#line 2252 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 72:
#line 577 "/root/compiler/sysy-make-template/src/sysy.y"
            {
    auto ast = new MulExpAST();
    ast -> only = 1;
    ast -> unaryexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;

  }
#line 2264 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 73:
#line 584 "/root/compiler/sysy-make-template/src/sysy.y"
                      {
    auto ast = new MulExpAST();
    ast -> only = 0;
    ast -> mulexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast -> op = '%';
    ast -> unaryexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2277 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 74:
#line 591 "/root/compiler/sysy-make-template/src/sysy.y"
                       {
    auto ast = new MulExpAST();
    ast -> only = 0;
    ast -> mulexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast -> op = '*';
    ast -> unaryexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2290 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 75:
#line 598 "/root/compiler/sysy-make-template/src/sysy.y"
                      {
    auto ast = new MulExpAST();
    ast -> only = 0;
    ast -> mulexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast -> op = '/';
    ast -> unaryexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2303 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 76:
#line 609 "/root/compiler/sysy-make-template/src/sysy.y"
          {
    auto ast = new AddExpAST();
    ast -> only = 1;
    ast -> mulexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2314 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 77:
#line 615 "/root/compiler/sysy-make-template/src/sysy.y"
                    {
    auto ast = new AddExpAST();
    ast -> only = 0;
    ast -> addexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast -> op = '-';
    ast -> mulexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2327 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 78:
#line 622 "/root/compiler/sysy-make-template/src/sysy.y"
                     {
    auto ast = new AddExpAST();
    ast -> only = 0;
    ast -> addexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast -> op = '+';
    ast -> mulexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2340 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 79:
#line 633 "/root/compiler/sysy-make-template/src/sysy.y"
          {
    auto ast = new RelExpAST();
    ast -> only =1;
    ast -> addexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2351 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 80:
#line 639 "/root/compiler/sysy-make-template/src/sysy.y"
                      {
    auto ast = new RelExpAST();
    ast -> only =0;
    ast -> relexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->op = *((yyvsp[-1].str_val));
    ast -> addexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
    
  }
#line 2365 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 81:
#line 651 "/root/compiler/sysy-make-template/src/sysy.y"
          {
    auto ast = new EqExpAST();
    ast -> only =1;
    ast -> relexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2376 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 82:
#line 657 "/root/compiler/sysy-make-template/src/sysy.y"
                    {
    auto ast = new EqExpAST();
    ast -> only =0;
    ast -> eqexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->op = *((yyvsp[-1].str_val));
    ast -> relexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
    
  }
#line 2390 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 83:
#line 669 "/root/compiler/sysy-make-template/src/sysy.y"
         {
    auto ast = new LAndExpAST();
    ast -> only =1;
    ast -> eqexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2401 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 84:
#line 675 "/root/compiler/sysy-make-template/src/sysy.y"
                       {
    auto ast = new LAndExpAST();
    ast -> only =0;
    ast -> landexp = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
    ast -> eqexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
    
  }
#line 2414 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 85:
#line 688 "/root/compiler/sysy-make-template/src/sysy.y"
           {
    auto ast = new LOrExpAST();
    ast -> only =1;
    ast -> landexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2425 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 86:
#line 694 "/root/compiler/sysy-make-template/src/sysy.y"
                        {
    auto ast = new LOrExpAST();
    ast -> only =0;
    ast -> lorexp = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
    ast -> landexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
    
  }
#line 2438 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 87:
#line 707 "/root/compiler/sysy-make-template/src/sysy.y"
        {
    auto ast = new LValAST();
    ast->ident = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = ast;
  }
#line 2448 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 88:
#line 711 "/root/compiler/sysy-make-template/src/sysy.y"
                       {
    auto ast = new LValAST();
    ast->ident = *unique_ptr<string>((yyvsp[-1].str_val));
    ast->matp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast->defm = 1;
    (yyval.ast_val) = ast;
  }
#line 2460 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 89:
#line 720 "/root/compiler/sysy-make-template/src/sysy.y"
        {
    auto ast = new LLValAST();
    ast->ident = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = ast;
  }
#line 2470 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 90:
#line 727 "/root/compiler/sysy-make-template/src/sysy.y"
                        {
    auto ast = new MLLValAST();
    ast->ident = *unique_ptr<string>((yyvsp[-1].str_val));
    ast->matp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2481 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 91:
#line 735 "/root/compiler/sysy-make-template/src/sysy.y"
            {
    auto ast = new MatrixParamsAST();
    ast -> keep =0;
    ast-> exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2492 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 92:
#line 741 "/root/compiler/sysy-make-template/src/sysy.y"
                        {
    auto ast = new MatrixParamsAST();
    ast -> keep = 1;
    ast-> exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast-> mparams = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2504 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 93:
#line 750 "/root/compiler/sysy-make-template/src/sysy.y"
            {
    auto ast = new LMatrixParamsAST();
    ast -> keep =0;
    ast-> exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2515 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 94:
#line 756 "/root/compiler/sysy-make-template/src/sysy.y"
                         {
    auto ast = new LMatrixParamsAST();
    ast -> keep = 1;
    ast-> exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast-> mparams = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 2527 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"
    break;


#line 2531 "/root/compiler/sysy-make-template/build/sysy.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (ast, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (ast, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, ast);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, ast);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (ast, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ast);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, ast);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 766 "/root/compiler/sysy-make-template/src/sysy.y"


// 定义错误处理函数, 其中第二个参数是错误信息
// parser 如果发生错误 (例如输入的程序出现了语法错误), 就会调用这个函数
void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  cerr << "error: " << s << endl;
}
