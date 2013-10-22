/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 11 "parser.y"


/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine



/* Line 268 of yacc.c  */
#line 88 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Void = 258,
     T_Bool = 259,
     T_Int = 260,
     T_Double = 261,
     T_String = 262,
     T_Class = 263,
     T_Dims = 264,
     T_Null = 265,
     T_Extends = 266,
     T_This = 267,
     T_Interface = 268,
     T_Implements = 269,
     T_While = 270,
     T_For = 271,
     T_If = 272,
     T_Else = 273,
     T_Return = 274,
     T_Break = 275,
     T_Switch = 276,
     T_Default = 277,
     T_Case = 278,
     T_New = 279,
     T_NewArray = 280,
     T_Print = 281,
     T_ReadInteger = 282,
     T_ReadLine = 283,
     T_Incr = 284,
     T_Decr = 285,
     T_Identifier = 286,
     T_StringConstant = 287,
     T_IntConstant = 288,
     T_DoubleConstant = 289,
     T_BoolConstant = 290,
     T_Or = 291,
     T_And = 292,
     T_NotEqual = 293,
     T_Equal = 294,
     T_GreaterEqual = 295,
     T_LessEqual = 296,
     UMINUS = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 41 "parser.y"

    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    const char *op1; 
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    VarDecl *var;
    FnDecl *fDecl;
    ClassDecl *cDecl;
    InterfaceDecl *iDecl;
    Type *type;
    Stmt *stmt;
    IfStmt *ifStmt;
  
    
    WhileStmt *whileStmt;
    ForStmt *forStmt;
    BreakStmt *breakStmt;
    ReturnStmt *returnStmt;
    PrintStmt *printStmt;
    Expr *expr;
    CompoundExpr *cexpr;
    Operator *op; 
    
    NamedType *nt; 
    SwitchStmt *st; 
    DefaultStmt *ds;
    CaseStmt *cs; 
    StmtBlock *sb; 
    List<Stmt*> *stmtList;
    List<VarDecl*> *varList;
    List<Decl*> *declList;
    List<FnDecl*> *fnList; 
    List<Expr*> *exprList;	
    List<NamedType*> *namedType;
    List<CaseStmt*> *csList;



/* Line 293 of yacc.c  */
#line 208 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 233 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   487

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  215

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,    49,     2,     2,
      53,    54,    47,    45,    61,    46,    52,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    58,
      40,    36,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    37,    38,    41,    42,    43,    44,    51,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      21,    24,    26,    28,    30,    32,    34,    37,    40,    46,
      52,    58,    61,    62,    66,    68,    76,    79,    80,    83,
      84,    88,    90,    92,    93,    96,    98,   100,   102,   104,
     105,   109,   111,   116,   119,   120,   122,   123,   126,   128,
     131,   133,   135,   137,   139,   141,   143,   145,   147,   149,
     150,   156,   164,   174,   180,   184,   187,   193,   197,   199,
     207,   210,   214,   215,   218,   220,   225,   229,   233,   237,
     241,   245,   249,   253,   257,   261,   265,   269,   273,   277,
     280,   283,   285,   290,   295,   300,   307,   311,   313,   315,
     317,   321,   322,   329,   334,   336,   337,   341,   346,   348,
     351,   354,   356,   358,   360,   362
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    -1,    65,    66,    -1,    66,    -1,
      67,    -1,    70,    -1,    72,    -1,    75,    -1,    68,    58,
      -1,    69,    31,    -1,     5,    -1,     4,    -1,     7,    -1,
       6,    -1,    31,    -1,    69,     9,    -1,    71,    84,    -1,
      69,    31,    53,    82,    54,    -1,     3,    31,    53,    82,
      54,    -1,    13,    31,    59,    73,    60,    -1,    74,    58,
      -1,    -1,    74,    58,    71,    -1,    71,    -1,     8,    31,
      76,    77,    59,    79,    60,    -1,    11,    31,    -1,    -1,
      14,    78,    -1,    -1,    78,    61,    31,    -1,    31,    -1,
      80,    -1,    -1,    80,    81,    -1,    81,    -1,    67,    -1,
      70,    -1,    83,    -1,    -1,    83,    61,    68,    -1,    68,
      -1,    59,    85,    86,    60,    -1,    85,    67,    -1,    -1,
      87,    -1,    -1,    87,    88,    -1,    88,    -1,    89,    58,
      -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,    84,
      -1,    94,    -1,    95,    -1,    97,    -1,   102,    -1,    -1,
      17,    53,   102,    54,    88,    -1,    17,    53,   102,    54,
      88,    18,    88,    -1,    16,    53,    89,    58,   102,    58,
      89,    54,    88,    -1,    15,    53,   102,    54,    88,    -1,
      19,    89,    58,    -1,    20,    58,    -1,    26,    53,    96,
      54,    58,    -1,    96,    61,   102,    -1,   102,    -1,    21,
      53,   102,    54,    59,    98,    60,    -1,   100,    99,    -1,
      22,    62,    86,    -1,    -1,   100,   101,    -1,   101,    -1,
      23,    33,    62,    86,    -1,   102,    45,   102,    -1,   102,
      46,   102,    -1,   102,    47,   102,    -1,   102,    48,   102,
      -1,   102,    49,   102,    -1,   102,    44,   102,    -1,   102,
      43,   102,    -1,   102,    42,   102,    -1,   102,    41,   102,
      -1,   102,    38,   102,    -1,   102,    37,   102,    -1,   102,
      40,   102,    -1,   102,    39,   102,    -1,    46,   102,    -1,
      50,   102,    -1,    12,    -1,    27,    53,   103,    54,    -1,
      28,    53,   103,    54,    -1,    24,    53,    31,    54,    -1,
      25,    53,   102,    61,    69,    54,    -1,    53,   102,    54,
      -1,   107,    -1,   104,    -1,   106,    -1,   106,    36,   102,
      -1,    -1,   102,    52,    31,    53,   105,    54,    -1,    31,
      53,   105,    54,    -1,    96,    -1,    -1,   102,    52,    31,
      -1,   102,    55,   102,    56,    -1,    31,    -1,   102,    29,
      -1,   102,    30,    -1,    33,    -1,    34,    -1,    35,    -1,
      32,    -1,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   159,   159,   171,   172,   174,   175,   176,   177,   180,
     183,   186,   187,   188,   189,   190,   191,   194,   199,   201,
     206,   209,   210,   213,   214,   220,   222,   223,   226,   227,
     230,   231,   234,   235,   238,   239,   242,   243,   246,   247,
     250,   252,   255,   260,   261,   264,   265,   269,   270,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   287,   288,
     291,   292,   296,   299,   301,   303,   305,   306,   307,   310,
     313,   315,   316,   318,   319,   322,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   355,   357,   358,   361,   362,   364,   365,   366,   367,
     368,   372,   373,   374,   375,   376
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Double",
  "T_String", "T_Class", "T_Dims", "T_Null", "T_Extends", "T_This",
  "T_Interface", "T_Implements", "T_While", "T_For", "T_If", "T_Else",
  "T_Return", "T_Break", "T_Switch", "T_Default", "T_Case", "T_New",
  "T_NewArray", "T_Print", "T_ReadInteger", "T_ReadLine", "T_Incr",
  "T_Decr", "T_Identifier", "T_StringConstant", "T_IntConstant",
  "T_DoubleConstant", "T_BoolConstant", "'='", "T_Or", "T_And", "'>'",
  "'<'", "T_NotEqual", "T_Equal", "T_GreaterEqual", "T_LessEqual", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "'.'", "'('", "')'", "'['",
  "']'", "\"then\"", "';'", "'{'", "'}'", "','", "':'", "$accept",
  "Program", "DeclList", "Decl", "VarDecl", "Variable", "Type", "FnDecl",
  "FnHeader", "IntfDecl", "PrototypeList", "Prototype", "ClDecl", "exopt",
  "intfoptlist", "intflist", "FieldList", "FieldList1", "Field", "Formals",
  "FormalList", "StmtBlock", "VarDecls", "StmtList1", "StmtList", "Stmt",
  "ExprOpt", "IfStmt", "ForStmt", "WhileStmt", "ReturnStmt", "BreakStmt",
  "PrintStmt", "ExprList", "SwitchStmt", "switchbody", "optDefault",
  "caselist", "case", "Expr", "temp", "Call", "Actuals", "LValue",
  "Constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    61,   291,   292,    62,
      60,   293,   294,   295,   296,    43,    45,    42,    47,    37,
      33,   297,    46,    40,    41,    91,    93,   298,    59,   123,
     125,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    66,    67,
      68,    69,    69,    69,    69,    69,    69,    70,    71,    71,
      72,    73,    73,    74,    74,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    91,    92,    93,    94,    95,    96,    96,    97,
      98,    99,    99,   100,   100,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   104,   104,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   107,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     5,     5,
       5,     2,     0,     3,     1,     7,     2,     0,     2,     0,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     0,
       3,     1,     4,     2,     0,     1,     0,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     7,     9,     5,     3,     2,     5,     3,     1,     7,
       2,     3,     0,     2,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     4,     4,     4,     6,     3,     1,     1,     1,
       3,     0,     6,     4,     1,     0,     3,     4,     1,     2,
       2,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,    11,    14,    13,     0,     0,    15,     0,
       2,     4,     5,     0,     0,     6,     0,     7,     8,     0,
      27,     0,     1,     3,     9,    16,    10,    44,    17,    39,
       0,    29,    22,    39,    46,    41,     0,     0,    38,    26,
       0,     0,     0,    24,     0,     0,     0,   115,    91,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
     108,   114,   111,   112,   113,     0,     0,     0,    43,    54,
       0,    45,    48,     0,    50,    51,    52,    53,    55,    56,
      57,    58,    98,    99,    97,    10,    19,     0,    31,    28,
      33,     0,    20,    21,    18,     0,    59,     0,   108,     0,
      65,     0,     0,     0,     0,   101,   101,   105,    89,    90,
       0,    42,    47,    49,   109,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,     0,    36,    37,     0,    32,    35,    23,
       0,     0,     0,    64,     0,     0,     0,     0,    68,     0,
       0,   104,     0,    96,    86,    85,    88,    87,    84,    83,
      82,    81,    76,    77,    78,    79,    80,   106,     0,   100,
      30,    25,    34,    59,     0,    59,     0,    94,     0,     0,
       0,    92,    93,   103,   105,   107,    63,     0,    60,     0,
       0,    66,    67,     0,    59,    59,     0,     0,    72,    74,
      95,   102,     0,    61,     0,    69,     0,    70,    73,    59,
      46,    46,    62,    75,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      44,    45,    18,    31,    41,    89,   136,   137,   138,    37,
      38,    69,    34,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,   151,    80,   197,   207,   198,   199,    81,
     149,    82,   152,    83,    84
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -119
static const yytype_int16 yypact[] =
{
      20,   -20,  -119,  -119,  -119,  -119,   -16,   -14,  -119,    29,
      20,  -119,  -119,   -26,    21,  -119,   -13,  -119,  -119,   -19,
      38,    27,  -119,  -119,  -119,  -119,     6,  -119,  -119,    36,
      57,    80,    32,    36,   140,  -119,    56,    41,    39,  -119,
      66,    40,    76,  -119,    42,    43,    49,  -119,  -119,    52,
      55,    59,    86,    58,    62,    69,    70,    71,    72,    75,
       0,  -119,  -119,  -119,  -119,    86,    86,    86,  -119,  -119,
      74,   185,  -119,    73,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,   411,  -119,    93,  -119,  -119,  -119,    36,  -119,    77,
      32,     6,  -119,    32,  -119,    86,    86,    86,    82,    83,
    -119,    86,    99,    86,    86,  -119,  -119,    86,   -39,   -39,
     327,  -119,  -119,  -119,  -119,  -119,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,   111,
      86,    86,  -119,   117,  -119,  -119,    91,    32,  -119,  -119,
     348,    95,   369,  -119,   390,   100,   255,    28,   411,   104,
     115,   109,   122,  -119,   432,   432,   133,   133,   133,   133,
     133,   133,   178,   178,    -8,    -8,    -8,   124,   306,   411,
    -119,  -119,  -119,   230,    86,   230,   125,  -119,    36,   129,
      86,  -119,  -119,  -119,    86,  -119,  -119,   282,   165,   166,
       1,  -119,   411,   137,    86,   230,   159,   134,    68,  -119,
    -119,  -119,   142,  -119,   141,  -119,   152,  -119,  -119,   230,
     185,   185,  -119,  -119,  -119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,   205,   -28,   -21,   -29,   -76,   -25,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    84,   189,
    -119,   207,  -119,  -118,  -119,   -69,   -51,  -119,  -119,  -119,
    -119,  -119,  -119,   120,  -119,  -119,  -119,  -119,    30,   -47,
     123,  -119,    48,  -119,  -119
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -60
static const yytype_int16 yytable[] =
{
      36,    99,   112,    42,    36,    36,    68,    43,    35,   -15,
      25,    19,    35,   129,   135,    20,   130,    21,   108,   109,
     110,   114,   115,     1,     2,     3,     4,     5,     6,    22,
      25,   -15,    24,     7,    29,     1,     2,     3,     4,     5,
       2,     3,     4,     5,   129,   141,    27,   130,   140,    30,
     142,     8,    26,   107,   144,   200,   146,   148,    36,    33,
     148,   135,   134,     8,    42,    25,   132,     8,   139,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   179,   168,   169,    25,    32,    85,    39,   180,
     206,   196,   213,   214,    40,    86,    47,    88,    48,    90,
      87,    93,    92,    94,   186,    95,   188,    91,    96,   134,
      55,    56,    97,    58,    59,   101,   100,    98,    61,    62,
      63,    64,   102,   103,   104,   105,   203,   187,   106,   131,
     145,   113,    65,   192,   111,   107,    66,   148,   133,    67,
     212,   143,   167,   202,     2,     3,     4,     5,   170,   190,
      47,   171,    48,   174,   177,    49,    50,    51,   181,    52,
      53,    54,   114,   115,    55,    56,    57,    58,    59,   182,
     180,    60,    61,    62,    63,    64,   183,   184,   124,   125,
     126,   127,   128,   195,   189,   129,    65,   191,   130,   196,
      66,   201,   204,    67,   205,    47,   209,    48,   -59,    27,
      49,    50,    51,   210,    52,    53,    54,   114,   115,    55,
      56,    57,    58,    59,   211,    23,    98,    61,    62,    63,
      64,   172,    46,    28,   147,   126,   127,   128,   208,   150,
     129,    65,   193,   130,     0,    66,     0,     0,    67,     0,
      47,     0,    48,   -59,    27,    49,    50,    51,     0,    52,
      53,    54,     0,     0,    55,    56,    57,    58,    59,     0,
       0,    98,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
      66,     0,     0,    67,   114,   115,     0,     0,     0,    27,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,     0,     0,   129,     0,     0,
     130,   114,   115,     0,     0,     0,   178,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,     0,     0,   129,   114,   115,   130,     0,     0,
     194,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   114,   115,   129,     0,
       0,   130,   185,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   114,   115,   129,
       0,   153,   130,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   114,   115,
     129,     0,   173,   130,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   114,
     115,   129,     0,   175,   130,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     114,   115,   129,     0,   176,   130,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   114,   115,   129,     0,     0,   130,     0,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,     0,     0,   129,     0,     0,   130
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-119))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      29,    52,    71,    32,    33,    34,    34,    32,    29,     9,
       9,    31,    33,    52,    90,    31,    55,    31,    65,    66,
      67,    29,    30,     3,     4,     5,     6,     7,     8,     0,
       9,    31,    58,    13,    53,     3,     4,     5,     6,     7,
       4,     5,     6,     7,    52,    96,    59,    55,    95,    11,
      97,    31,    31,    53,   101,    54,   103,   104,    87,    53,
     107,   137,    90,    31,    93,     9,    87,    31,    93,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    54,   130,   131,     9,    59,    31,    31,    61,
      22,    23,   210,   211,    14,    54,    10,    31,    12,    59,
      61,    58,    60,    54,   173,    53,   175,    31,    53,   137,
      24,    25,    53,    27,    28,    53,    58,    31,    32,    33,
      34,    35,    53,    53,    53,    53,   195,   174,    53,    36,
      31,    58,    46,   180,    60,    53,    50,   184,    61,    53,
     209,    58,    31,   194,     4,     5,     6,     7,    31,   178,
      10,    60,    12,    58,    54,    15,    16,    17,    54,    19,
      20,    21,    29,    30,    24,    25,    26,    27,    28,    54,
      61,    31,    32,    33,    34,    35,    54,    53,    45,    46,
      47,    48,    49,    18,    59,    52,    46,    58,    55,    23,
      50,    54,    33,    53,    60,    10,    54,    12,    58,    59,
      15,    16,    17,    62,    19,    20,    21,    29,    30,    24,
      25,    26,    27,    28,    62,    10,    31,    32,    33,    34,
      35,   137,    33,    16,   104,    47,    48,    49,   198,   106,
      52,    46,   184,    55,    -1,    50,    -1,    -1,    53,    -1,
      10,    -1,    12,    58,    59,    15,    16,    17,    -1,    19,
      20,    21,    -1,    -1,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      50,    -1,    -1,    53,    29,    30,    -1,    -1,    -1,    59,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    52,    -1,    -1,
      55,    29,    30,    -1,    -1,    -1,    61,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    52,    29,    30,    55,    -1,    -1,
      58,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    29,    30,    52,    -1,
      -1,    55,    56,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    29,    30,    52,
      -1,    54,    55,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    29,    30,
      52,    -1,    54,    55,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    29,
      30,    52,    -1,    54,    55,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      29,    30,    52,    -1,    54,    55,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    29,    30,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    52,    -1,    -1,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    13,    31,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    75,    31,
      31,    31,     0,    66,    58,     9,    31,    59,    84,    53,
      11,    76,    59,    53,    85,    68,    69,    82,    83,    31,
      14,    77,    69,    71,    73,    74,    82,    10,    12,    15,
      16,    17,    19,    20,    21,    24,    25,    26,    27,    28,
      31,    32,    33,    34,    35,    46,    50,    53,    67,    84,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      97,   102,   104,   106,   107,    31,    54,    61,    31,    78,
      59,    31,    60,    58,    54,    53,    53,    53,    31,    89,
      58,    53,    53,    53,    53,    53,    53,    53,   102,   102,
     102,    60,    88,    58,    29,    30,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    52,
      55,    36,    68,    61,    67,    70,    79,    80,    81,    71,
     102,    89,   102,    58,   102,    31,   102,    96,   102,   103,
     103,    96,   105,    54,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,    31,   102,   102,
      31,    60,    81,    54,    58,    54,    54,    54,    61,    54,
      61,    54,    54,    54,    53,    56,    88,   102,    88,    59,
      69,    58,   102,   105,    58,    18,    23,    98,   100,   101,
      54,    54,    89,    88,    33,    60,    22,    99,   101,    54,
      62,    62,    88,    86,    86
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = YYLEX;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 159 "parser.y"
    { 
                                      (yylsp[(1) - (1)]); 
                                      /* pp2: The @1 is needed to convince 
                                       * yacc to set up yylloc. You can remove 
                                       * it once you have other uses of @n*/
                                      Program *program = new Program((yyvsp[(1) - (1)].declList));
                                      // if no errors, advance to next phase
                                      if (ReportError::NumErrors() == 0) 
                                          program->Print(0);
                                    }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 171 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 172 "parser.y"
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl)); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 174 "parser.y"
    { (yyval.decl)=(yyvsp[(1) - (1)].var); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 175 "parser.y"
    { (yyval.decl)=(yyvsp[(1) - (1)].fDecl); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 176 "parser.y"
    {  (yyval.decl)=(yyvsp[(1) - (1)].iDecl);}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 177 "parser.y"
    {(yyval.decl) =(yyvsp[(1) - (1)].cDecl);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 180 "parser.y"
    { (yyval.var)=(yyvsp[(1) - (2)].var); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 183 "parser.y"
    { (yyval.var) = new VarDecl(new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier)), (yyvsp[(1) - (2)].type)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 186 "parser.y"
    { (yyval.type) = Type::intType; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 187 "parser.y"
    { (yyval.type) = Type::boolType; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 188 "parser.y"
    { (yyval.type) = Type::stringType; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 189 "parser.y"
    { (yyval.type) = Type::doubleType; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 190 "parser.y"
    { (yyval.type) = new NamedType(new Identifier((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].identifier))); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 191 "parser.y"
    { (yyval.type) = new ArrayType(Join((yylsp[(1) - (2)]), (yylsp[(2) - (2)])), (yyvsp[(1) - (2)].type)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 194 "parser.y"
    { ((yyval.fDecl)=(yyvsp[(1) - (2)].fDecl))->SetFunctionBody((yyvsp[(2) - (2)].sb)); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 200 "parser.y"
    { (yyval.fDecl) = new FnDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), (yyvsp[(1) - (5)].type), (yyvsp[(4) - (5)].varList)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 202 "parser.y"
    { (yyval.fDecl) = new FnDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), Type::voidType, (yyvsp[(4) - (5)].varList)); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 206 "parser.y"
    {(yyval.iDecl) = new InterfaceDecl(new Identifier((yylsp[(2) - (5)]),(yyvsp[(2) - (5)].identifier)),(yyvsp[(4) - (5)].declList));}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 209 "parser.y"
    {(yyval.declList)=(yyvsp[(1) - (2)].declList);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 210 "parser.y"
    { (yyval.declList) = new List<Decl*>;}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 213 "parser.y"
    {((yyval.declList)=(yyvsp[(1) - (3)].declList))->Append((yyvsp[(3) - (3)].fDecl));}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 214 "parser.y"
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].fDecl));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 220 "parser.y"
    { (yyval.cDecl) = new ClassDecl(new Identifier((yylsp[(2) - (7)]),(yyvsp[(2) - (7)].identifier)),(yyvsp[(3) - (7)].nt),(yyvsp[(4) - (7)].namedType),(yyvsp[(6) - (7)].declList)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 222 "parser.y"
    { (yyval.nt) = new NamedType(new Identifier((yylsp[(2) - (2)]),(yyvsp[(2) - (2)].identifier)));}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 223 "parser.y"
    {(yyval.nt) = NULL; }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 226 "parser.y"
    { (yyval.namedType) = (yyvsp[(2) - (2)].namedType);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 227 "parser.y"
    {(yyval.namedType) = new List<NamedType*>;}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 230 "parser.y"
    {((yyval.namedType)=(yyvsp[(1) - (3)].namedType))->Append(new NamedType(new Identifier((yylsp[(3) - (3)]),(yyvsp[(3) - (3)].identifier))));}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 231 "parser.y"
    { ((yyval.namedType) = new List<NamedType*>)->Append(new NamedType(new Identifier((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].identifier)))); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 234 "parser.y"
    {(yyval.declList)=(yyvsp[(1) - (1)].declList);}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 235 "parser.y"
    {(yyval.declList) = new List<Decl*>;}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 238 "parser.y"
    { ((yyval.declList) = (yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 239 "parser.y"
    {( (yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl));}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 242 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].var); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 243 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].fDecl);}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 246 "parser.y"
    { (yyval.varList) = (yyvsp[(1) - (1)].varList); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 247 "parser.y"
    { (yyval.varList) = new List<VarDecl*>; }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 251 "parser.y"
    { ((yyval.varList)=(yyvsp[(1) - (3)].varList))->Append((yyvsp[(3) - (3)].var)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 252 "parser.y"
    { ((yyval.varList) = new List<VarDecl*>)->Append((yyvsp[(1) - (1)].var)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 256 "parser.y"
    { (yyval.sb) = new StmtBlock((yyvsp[(2) - (4)].varList), (yyvsp[(3) - (4)].stmtList)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 260 "parser.y"
    { ((yyval.varList)=(yyvsp[(1) - (2)].varList))->Append((yyvsp[(2) - (2)].var)); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 261 "parser.y"
    { (yyval.varList) = new List<VarDecl*>; }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 264 "parser.y"
    {(yyval.stmtList) = (yyvsp[(1) - (1)].stmtList);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 265 "parser.y"
    {(yyval.stmtList) = new List<Stmt*>;}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 269 "parser.y"
    { ((yyval.stmtList) = (yyvsp[(1) - (2)].stmtList))->Append((yyvsp[(2) - (2)].stmt)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 270 "parser.y"
    {((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[(1) - (1)].stmt));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 274 "parser.y"
    { (yyval.stmt)=(yyvsp[(1) - (2)].expr);}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 275 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].ifStmt);}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 276 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].forStmt);}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 277 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].whileStmt);}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 278 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].returnStmt);}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 279 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].sb);}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 280 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].breakStmt);}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 281 "parser.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].printStmt);}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 282 "parser.y"
    {}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 287 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 288 "parser.y"
    {(yyval.expr) = new EmptyExpr();}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 291 "parser.y"
    {(yyval.ifStmt) = new IfStmt((yyvsp[(3) - (5)].expr),(yyvsp[(5) - (5)].stmt),NULL);}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 292 "parser.y"
    {(yyval.ifStmt) = new IfStmt((yyvsp[(3) - (7)].expr),(yyvsp[(5) - (7)].stmt),(yyvsp[(7) - (7)].stmt));}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 296 "parser.y"
    {(yyval.forStmt) = new ForStmt((yyvsp[(3) - (9)].expr),(yyvsp[(5) - (9)].expr),(yyvsp[(7) - (9)].expr),(yyvsp[(9) - (9)].stmt));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 299 "parser.y"
    {(yyval.whileStmt) = new WhileStmt((yyvsp[(3) - (5)].expr),(yyvsp[(5) - (5)].stmt));}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 301 "parser.y"
    {(yyval.returnStmt) = new ReturnStmt((yylsp[(1) - (3)]),(yyvsp[(2) - (3)].expr));}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 303 "parser.y"
    { (yyval.breakStmt) = new BreakStmt((yylsp[(1) - (2)]));}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 305 "parser.y"
    {(yyval.printStmt) = new PrintStmt((yyvsp[(3) - (5)].exprList));}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 306 "parser.y"
    {((yyval.exprList)=(yyvsp[(1) - (3)].exprList))->Append((yyvsp[(3) - (3)].expr));}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 307 "parser.y"
    {((yyval.exprList) = new List<Expr*>)->Append((yyvsp[(1) - (1)].expr));}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 310 "parser.y"
    {(yyval.st) = new SwitchStmt((yyvsp[(3) - (7)].expr),(yyvsp[(6) - (7)].stmtList)) ;}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 313 "parser.y"
    { ((yyval.stmtList) = (yyvsp[(1) - (2)].stmtList))->Append((yyvsp[(2) - (2)].ds));}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 315 "parser.y"
    {(yyval.ds) = new DefaultStmt(NULL,(yyvsp[(3) - (3)].stmtList));}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 316 "parser.y"
    {}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 318 "parser.y"
    { ((yyval.stmtList)=(yyvsp[(1) - (2)].stmtList))->Append((yyvsp[(2) - (2)].cs));}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 319 "parser.y"
    { ((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[(1) - (1)].cs));}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 322 "parser.y"
    {(yyval.cs) = new CaseStmt(new IntConstant((yylsp[(2) - (4)]),(yyvsp[(2) - (4)].integerConstant)),(yyvsp[(4) - (4)].stmtList));}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 328 "parser.y"
    {(yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"+"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 329 "parser.y"
    {(yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"-"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 330 "parser.y"
    {(yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"*"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 331 "parser.y"
    {(yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"/"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 332 "parser.y"
    {(yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"%"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 333 "parser.y"
    {(yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"<="),(yyvsp[(3) - (3)].expr)); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 334 "parser.y"
    {(yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),">="),(yyvsp[(3) - (3)].expr)); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 335 "parser.y"
    {(yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"=="),(yyvsp[(3) - (3)].expr)); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 336 "parser.y"
    {(yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"!="),(yyvsp[(3) - (3)].expr)); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 337 "parser.y"
    {(yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"&&"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 338 "parser.y"
    {(yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"||"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 339 "parser.y"
    {(yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"<"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 340 "parser.y"
    {(yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),">"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 341 "parser.y"
    {(yyval.expr) = new ArithmeticExpr(new Operator((yylsp[(1) - (2)]),"-"),(yyvsp[(2) - (2)].expr)); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 342 "parser.y"
    {(yyval.expr) = new LogicalExpr(new Operator((yylsp[(1) - (2)]),"!"),(yyvsp[(2) - (2)].expr)); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 343 "parser.y"
    {(yyval.expr) = new This((yylsp[(1) - (1)])); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 344 "parser.y"
    {(yyval.expr) = new ReadIntegerExpr((yylsp[(1) - (4)]));}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 345 "parser.y"
    {(yyval.expr) = new ReadLineExpr((yylsp[(1) - (4)]));}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 346 "parser.y"
    { (yyval.expr) = new NewExpr((yylsp[(1) - (4)]),new NamedType(new Identifier((yylsp[(3) - (4)]),(yyvsp[(3) - (4)].identifier))));}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 347 "parser.y"
    {(yyval.expr) = new NewArrayExpr((yylsp[(1) - (6)]),(yyvsp[(3) - (6)].expr),(yyvsp[(5) - (6)].type));}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 348 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr);}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 349 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 350 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 351 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 352 "parser.y"
    {(yyval.expr) = new AssignExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"="),(yyvsp[(3) - (3)].expr)); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 357 "parser.y"
    {(yyval.expr) = new Call ((yylsp[(1) - (6)]),(yyvsp[(1) - (6)].expr),new Identifier((yylsp[(3) - (6)]),(yyvsp[(3) - (6)].identifier)),(yyvsp[(5) - (6)].exprList));}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 358 "parser.y"
    {(yyval.expr) = new Call((yylsp[(1) - (4)]),NULL,new Identifier((yylsp[(1) - (4)]),(yyvsp[(1) - (4)].identifier)),(yyvsp[(3) - (4)].exprList));}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 361 "parser.y"
    {(yyval.exprList)=(yyvsp[(1) - (1)].exprList);}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 362 "parser.y"
    {(yyval.exprList) = new List<Expr*>;}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 364 "parser.y"
    {(yyval.expr) = new FieldAccess((yyvsp[(1) - (3)].expr),new Identifier((yylsp[(3) - (3)]),(yyvsp[(3) - (3)].identifier)));}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 365 "parser.y"
    {(yyval.expr) = new ArrayAccess((yylsp[(1) - (4)]),(yyvsp[(1) - (4)].expr),(yyvsp[(3) - (4)].expr));}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 366 "parser.y"
    {(yyval.expr) = new FieldAccess(NULL, new Identifier((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].identifier)));}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 367 "parser.y"
    {(yyval.expr) = new PostfixExpr((yyvsp[(1) - (2)].expr), new Operator((yylsp[(2) - (2)]),"++"));}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 368 "parser.y"
    {(yyval.expr) = new PostfixExpr((yyvsp[(1) - (2)].expr),new Operator((yylsp[(2) - (2)]),"--"));}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 372 "parser.y"
    {(yyval.expr) = new IntConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].integerConstant));}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 373 "parser.y"
    {(yyval.expr) = new DoubleConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].doubleConstant));}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 374 "parser.y"
    {(yyval.expr) = new BoolConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].boolConstant));}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 375 "parser.y"
    {(yyval.expr) = new StringConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].stringConstant));}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 376 "parser.y"
    {(yyval.expr) = new NullConstant((yylsp[(1) - (1)]));}
    break;



/* Line 1806 of yacc.c  */
#line 2561 "parser.tab.c"
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
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 378 "parser.y"


/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;

}

