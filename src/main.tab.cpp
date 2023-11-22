/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/main.y" /* yacc.c:339  */

#include "common.h"
#define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror(char const*);
    void setType(TreeNode*);
    

#line 77 "src/main.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "main.tab.h".  */
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_CHAR = 258,
    T_BOOL = 259,
    T_INT = 260,
    IDENTIFIER = 261,
    INTEGER = 262,
    CHAR = 263,
    BOOL = 264,
    STRING = 265,
    IF = 266,
    ELSE = 267,
    LPAREN = 268,
    RPAREN = 269,
    LBRACE = 270,
    RBRACE = 271,
    LSQUBR = 272,
    RSQUBR = 273,
    SEMICOLON = 274,
    COMMA = 275,
    EQ = 276,
    NE = 277,
    GE = 278,
    LE = 279,
    GT = 280,
    LT = 281,
    ASSIGN = 282,
    PLUS = 283,
    SUB = 284,
    MUL = 285,
    DIV = 286,
    REM = 287,
    ADDADD = 288,
    SUBSUB = 289,
    ADDASS = 290,
    SUBASS = 291,
    MULASS = 292,
    DIVASS = 293,
    REMASS = 294,
    ANDASS = 295,
    ORASS = 296,
    WHILE = 297,
    FOR = 298,
    RETURN = 299,
    BREAK = 300,
    CASE = 301,
    CONST = 302,
    CONTINUE = 303,
    DEFAULT = 304,
    DELETE = 305,
    DO = 306,
    ENUM = 307,
    FALSE = 308,
    NEW = 309,
    NULLPTR = 310,
    STRUCT = 311,
    SWITCH = 312,
    TRUE = 313,
    UNION = 314,
    VOID = 315,
    PRINTF = 316,
    SCANF = 317,
    MAIN = 318,
    OR = 319,
    AND = 320,
    ADD = 321,
    NOT = 322,
    GETADD = 323
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 197 "src/main.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   667

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    55,    63,    64,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    83,   119,
     155,   194,   205,   206,   207,   211,   249,   250,   251,   252,
     261,   270,   279,   288,   297,   306,   315,   324,   333,   342,
     351,   360,   369,   378,   386,   394,   402,   410,   418,   429,
     463,   470,   478,   486,   494,   502,   510,   518,   526,   536,
     543,   553,   565,   574,   579,   587,   593,   602,   608,   617,
     623
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_CHAR", "T_BOOL", "T_INT",
  "IDENTIFIER", "INTEGER", "CHAR", "BOOL", "STRING", "IF", "ELSE",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LSQUBR", "RSQUBR", "SEMICOLON",
  "COMMA", "EQ", "NE", "GE", "LE", "GT", "LT", "ASSIGN", "PLUS", "SUB",
  "MUL", "DIV", "REM", "ADDADD", "SUBSUB", "ADDASS", "SUBASS", "MULASS",
  "DIVASS", "REMASS", "ANDASS", "ORASS", "WHILE", "FOR", "RETURN", "BREAK",
  "CASE", "CONST", "CONTINUE", "DEFAULT", "DELETE", "DO", "ENUM", "FALSE",
  "NEW", "NULLPTR", "STRUCT", "SWITCH", "TRUE", "UNION", "VOID", "PRINTF",
  "SCANF", "MAIN", "OR", "AND", "ADD", "NOT", "GETADD", "$accept",
  "program", "block", "statements", "statement", "idlist", "declaration",
  "T", "expr", "left_val", "assign_stmt", "if_stmt", "for_stmt",
  "while_stmt", "return_stmt", "printf_stmt", "scanf_stmt", "main_func", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -50

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     126,  -116,  -116,   -57,   -13,  -116,  -116,  -116,    -3,   126,
    -116,    98,     2,    16,    11,   -29,    23,    24,    98,    98,
      98,    38,  -116,   126,  -116,    20,    35,   291,   144,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,    29,    98,    82,
    -116,   127,    98,   126,  -116,   317,    36,    40,    52,   127,
      -1,    -1,  -116,  -116,  -116,    48,    56,  -116,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,  -116,
    -116,    98,    98,    98,   146,    98,    98,    98,    98,    98,
      98,    98,    67,   175,  -116,   196,   126,  -116,    68,   -12,
     -11,    98,    77,   555,    14,    14,    14,    14,    14,    14,
     127,    -1,    -1,    -1,   576,   601,   127,   339,  -116,   365,
     387,   413,   435,   461,   483,   509,    76,   126,   126,    98,
      76,    80,    98,    81,    98,   530,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,    84,  -116,   222,  -116,
    -116,   243,  -116,   269,   126,   126,    83,    88,  -116,  -116,
    -116,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    24,    22,    25,    26,    27,    28,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     2,     4,     0,     0,     0,     0,     8,
      10,    11,    12,    13,    14,    15,    17,     0,     0,     0,
      25,    44,     0,     0,    63,     0,     0,     0,     0,    45,
      43,    48,     1,     5,     7,    19,    21,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,    64,     0,     0,
       0,     0,     0,    42,    34,    35,    37,    36,    39,    38,
      30,    31,    32,    33,    41,    40,    29,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,    18,    50,    51,    52,
      53,    54,    55,    56,    57,    69,    59,    62,     0,    70,
      65,     0,    67,     0,     0,     0,     0,     0,    60,    61,
      66,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -116,  -116,  -115,    94,   -23,  -116,  -116,  -116,    -7,  -116,
      39,  -116,  -116,  -116,  -116,  -116,  -116,  -116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    21,    22,    23,    24,    56,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,   135,   121,   123,    41,   139,    37,    45,   122,   124,
      38,    49,    50,    51,   -49,    42,    53,    40,     5,     6,
      86,     7,   -49,   -49,   -49,   -49,   -49,   -49,   -49,    43,
      44,    83,    69,    70,    46,    85,    47,    48,    52,    54,
      11,    55,    82,    65,    66,    67,    68,    69,    70,    88,
      89,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    90,   119,   104,   105,   106,   107,   109,   110,
     111,   112,   113,   114,   115,    91,    92,    18,    19,    20,
      73,   116,   120,   126,   125,     1,     2,     3,     4,     5,
       6,     9,     7,     8,   136,   137,   144,     9,    84,   140,
     142,    10,   150,    39,    40,     5,     6,   151,     7,     0,
       0,    11,   138,   108,     0,   141,     0,   143,     0,     0,
       0,   148,   149,     0,    12,    13,    14,    11,     0,     1,
       2,     3,     4,     5,     6,     0,     7,     8,     0,     0,
       0,     9,    15,    16,    17,    10,     0,     0,    18,    19,
      20,     0,     4,     5,     6,    11,     7,    66,    67,    68,
      69,    70,     0,     0,    18,    19,    20,     0,    12,    13,
      14,    74,     0,     0,     0,    11,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    15,    16,    17,   117,
       0,     0,    18,    19,    20,    58,    59,    60,    61,    62,
      63,    64,     0,     0,    65,    66,    67,    68,    69,    70,
     118,     0,    18,    19,    20,     0,    58,    59,    60,    61,
      62,    63,    64,     0,     0,    65,    66,    67,    68,    69,
      70,     0,     0,     0,     0,     0,   145,     0,     0,    71,
      72,    73,    58,    59,    60,    61,    62,    63,    64,     0,
       0,    65,    66,    67,    68,    69,    70,   146,     0,     0,
      71,    72,    73,    58,    59,    60,    61,    62,    63,    64,
       0,     0,    65,    66,    67,    68,    69,    70,     0,     0,
       0,     0,     0,   147,     0,     0,    71,    72,    73,    58,
      59,    60,    61,    62,    63,    64,     0,     0,    65,    66,
      67,    68,    69,    70,     0,     0,     0,    71,    72,    73,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
      65,    66,    67,    68,    69,    70,     0,     0,     0,     0,
       0,     0,     0,    71,    72,    73,    87,    58,    59,    60,
      61,    62,    63,    64,     0,     0,    65,    66,    67,    68,
      69,    70,     0,     0,     0,    71,    72,    73,   127,    58,
      59,    60,    61,    62,    63,    64,     0,     0,    65,    66,
      67,    68,    69,    70,     0,     0,     0,     0,     0,     0,
       0,    71,    72,    73,   128,    58,    59,    60,    61,    62,
      63,    64,     0,     0,    65,    66,    67,    68,    69,    70,
       0,     0,     0,    71,    72,    73,   129,    58,    59,    60,
      61,    62,    63,    64,     0,     0,    65,    66,    67,    68,
      69,    70,     0,     0,     0,     0,     0,     0,     0,    71,
      72,    73,   130,    58,    59,    60,    61,    62,    63,    64,
       0,     0,    65,    66,    67,    68,    69,    70,     0,     0,
       0,    71,    72,    73,   131,    58,    59,    60,    61,    62,
      63,    64,     0,     0,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,     0,     0,     0,    71,    72,    73,
     132,    58,    59,    60,    61,    62,    63,    64,     0,     0,
      65,    66,    67,    68,    69,    70,     0,     0,     0,    71,
      72,    73,   133,    58,    59,    60,    61,    62,    63,    64,
       0,     0,    65,    66,    67,    68,    69,    70,     0,     0,
       0,     0,     0,     0,     0,    71,    72,    73,   134,    58,
      59,    60,    61,    62,    63,    64,     0,     0,    65,    66,
      67,    68,    69,    70,     0,     0,     0,    71,    72,    73,
      58,    59,    60,    61,    62,    63,    64,     0,     0,    65,
      66,    67,    68,    69,    70,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    72,    73,    59,    60,    61,    62,
      63,    64,     0,     0,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,    71,    72,    73,    59,    60,    61,
      62,    63,    64,     0,     0,    65,    66,    67,    68,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,    71,
      72,    73,    59,    60,    61,    62,    63,    64,     0,     0,
      65,    66,    67,    68,    69,    70,     0,     0,     0,     0,
       0,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73
};

static const yytype_int16 yycheck[] =
{
      23,   116,    14,    14,    11,   120,    63,    14,    20,    20,
      13,    18,    19,    20,    27,    13,    39,     6,     7,     8,
      43,    10,    35,    36,    37,    38,    39,    40,    41,    13,
      19,    38,    33,    34,    63,    42,    13,    13,     0,    19,
      29,     6,    13,    29,    30,    31,    32,    33,    34,    13,
      10,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    10,    86,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    27,    20,    66,    67,    68,
      66,    14,    14,     6,    91,     3,     4,     5,     6,     7,
       8,    15,    10,    11,   117,   118,    12,    15,    16,    19,
      19,    19,    19,     9,     6,     7,     8,    19,    10,    -1,
      -1,    29,   119,    74,    -1,   122,    -1,   124,    -1,    -1,
      -1,   144,   145,    -1,    42,    43,    44,    29,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    15,    60,    61,    62,    19,    -1,    -1,    66,    67,
      68,    -1,     6,     7,     8,    29,    10,    30,    31,    32,
      33,    34,    -1,    -1,    66,    67,    68,    -1,    42,    43,
      44,    27,    -1,    -1,    -1,    29,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    60,    61,    62,    14,
      -1,    -1,    66,    67,    68,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      14,    -1,    66,    67,    68,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    64,
      65,    66,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    14,    -1,    -1,
      64,    65,    66,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    64,    65,    66,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    64,    65,    66,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    64,    65,    66,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    64,    65,    66,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    64,    65,    66,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    64,
      65,    66,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    64,    65,    66,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    64,    65,    66,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    11,    15,
      19,    29,    42,    43,    44,    60,    61,    62,    66,    67,
      68,    70,    71,    72,    73,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    63,    13,    72,
       6,    77,    13,    13,    19,    77,    63,    13,    13,    77,
      77,    77,     0,    73,    19,     6,    74,    19,    20,    21,
      22,    23,    24,    25,    26,    29,    30,    31,    32,    33,
      34,    64,    65,    66,    27,    35,    36,    37,    38,    39,
      40,    41,    13,    77,    16,    77,    73,    19,    13,    10,
      10,    27,    20,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    79,    77,
      77,    77,    77,    77,    77,    77,    14,    14,    14,    73,
      14,    14,    20,    14,    20,    77,     6,    19,    19,    19,
      19,    19,    19,    19,    19,    71,    73,    73,    77,    71,
      19,    77,    19,    77,    12,    14,    14,    14,    73,    73,
      19,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    82,    83,    83,    84,    84,    85,    85,    86,
      86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     5,
       7,     7,     5,     2,     3,     5,     7,     5,     7,     5,
       5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 52 "src/main.y" /* yacc.c:1646  */
    { root = new TreeNode(0, NODE_PROG); root->addChild((yyvsp[0])); }
#line 1485 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "src/main.y" /* yacc.c:1646  */
    { 
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
    node->stype = STMT_BLOCK;
    node->addChild((yyvsp[-1]));
    (yyval) = node; 
}
#line 1496 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 63 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1502 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 64 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); (yyval)->addSibling((yyvsp[0])); }
#line 1508 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 68 "src/main.y" /* yacc.c:1646  */
    { (yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stype = STMT_SKIP; }
#line 1514 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 69 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1520 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 70 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1526 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 71 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1532 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 72 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1538 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 73 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1544 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 74 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1550 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 75 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1556 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 76 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1562 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 77 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1568 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 78 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1574 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 79 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1580 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 83 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
    map<pair<int, string>, id_info>::iterator iter_id;
    if (id_section.size() > 0)
    {
        iter_id = idlist.find(pair<int, string>(id_section.top(), (yyvsp[0])->var_name));
        if (iter_id == idlist.end())
        {
            pair<int, string> p(id_section.top(), (yyvsp[0])->var_name);
            id_info temp;
            temp.id = ids;
            temp.type = &(yyvsp[-2])->type;
            idlist.insert(pair<pair<int, string>, id_info>(p, temp));
            (yyvsp[0])->id_num = ids;
            ids++;
        }
        else
        {
            cout << "Variable " << (yyvsp[0])->var_name << " is redefined at line " << (yyvsp[0])->lineno << "." << endl;
        }
    }
    else
    {
        pair<int, string> p(0, (yyvsp[0])->var_name);
        id_info temp;
        temp.id = ids;
        temp.type = &(yyvsp[-2])->type;
        idlist.insert(pair<pair<int, string>, id_info>(p, temp));
        (yyvsp[0])->id_num = ids;
        ids++;
    }
}
#line 1621 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 119 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[0])->lineno, NODE_STMT);
    node->addChild((yyvsp[0]));
    (yyval) = node;
    map<pair<int, string>, id_info>::iterator iter_id;
    if (id_section.size() > 0)
    {
        iter_id = idlist.find(pair<int, string>(id_section.top(), (yyvsp[0])->var_name));
        if (iter_id == idlist.end())
        {
            pair<int, string> p(id_section.top(), (yyvsp[0])->var_name);
            id_info temp;
            temp.id = ids;
            temp.type = &(yyvsp[0])->type;
            idlist.insert(pair<pair<int, string>, id_info>(p, temp));
            (yyvsp[0])->id_num = ids;
            ids++;
        }
        else
        {
            cerr << "Variable " << (yyvsp[0])->var_name << " is redefined at line " << (yyvsp[0])->lineno << "." << endl;
        }
    }
    else
    {
        pair<int, string> p(0, (yyvsp[0])->var_name);
        id_info temp;
        temp.id = ids;
        temp.type = &(yyvsp[0])->type;
        idlist.insert(pair<pair<int, string>, id_info>(p, temp));
        (yyvsp[0])->id_num = ids;
        ids++;
    }
}
#line 1660 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 155 "src/main.y" /* yacc.c:1646  */
    {  // declare and init
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
    setType(node);
    map<pair<int, string>, id_info>::iterator iter_id;
    if (id_section.size() > 0)
    {
        iter_id = idlist.find(pair<int, string>(id_section.top(), (yyvsp[-2])->var_name));
        if (iter_id == idlist.end())
        {
            pair<int, string> p(id_section.top(), (yyvsp[-2])->var_name);
            id_info temp;
            temp.id = ids;
            temp.type = &(yyvsp[-3])->type;
            idlist.insert(pair<pair<int, string>, id_info>(p, temp));
            (yyvsp[-2])->id_num = ids;
            ids++;
        }
        else
        {
            cerr << "Variable " << (yyvsp[-2])->var_name << " is redefined at line " << (yyvsp[-2])->lineno << "." << endl;
        }
    }
    else
    {
        pair<int, string> p(0, (yyvsp[-2])->var_name);
        id_info temp;
        temp.id = ids;
        temp.type = &(yyvsp[-3])->type;
        idlist.insert(pair<pair<int, string>, id_info>(p, temp));
        (yyvsp[-2])->id_num = ids;
        ids++;
    }
}
#line 1703 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 194 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild((yyvsp[-1]));
    node->addChild((yyvsp[0]));
    (yyvsp[0])->type = (yyvsp[-1])->type;
    setType(node);
    (yyval) = node;
}
#line 1717 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 205 "src/main.y" /* yacc.c:1646  */
    { (yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT; }
#line 1723 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 206 "src/main.y" /* yacc.c:1646  */
    { (yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR; }
#line 1729 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 207 "src/main.y" /* yacc.c:1646  */
    { (yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_BOOL; }
#line 1735 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 211 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
    map<pair<int, string>, id_info>::iterator iter_id;
    if (id_section.size() > 0)
    {
        stack<int> temp;
        while (!id_section.empty())
        {
            iter_id = idlist.find(pair<int, string>(id_section.top(), (yyval)->var_name));
            if (iter_id == idlist.end())
            {
                temp.push(id_section.top());
                id_section.pop();
            }
            else
            {
                (yyval)->id_num = iter_id->second.id;
                (yyval)->type = *iter_id->second.type;
                break;
            }
            if (id_section.empty())
            {
                cerr << "Undefined identifier " << (yyvsp[0])->var_name << " at line " << (yyvsp[0])->lineno << "." << endl;
                break;
            }
        }
        while (!temp.empty())
        {
            id_section.push(temp.top());
            temp.pop();
        }
    }
    else
    {
        (yyval)->id_num = -1;
        cerr << "Undefined identifier " << (yyvsp[0])->var_name << " at line " << (yyvsp[0])->lineno << "." << endl;
    }
}
#line 1778 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 249 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1784 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 250 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1790 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 251 "src/main.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1796 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 252 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_ADD;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-2])->type;
    (yyval) = node;
}
#line 1810 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 261 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_SUB;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-2])->type;
    (yyval) = node;
}
#line 1824 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 270 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_MUL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-2])->type;
    (yyval) = node;
}
#line 1838 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 279 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_DIV;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-2])->type;
    (yyval) = node;
}
#line 1852 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 288 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_REM;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-2])->type;
    (yyval) = node;
}
#line 1866 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 297 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_EQ;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = TYPE_BOOL;
    (yyval) = node;
}
#line 1880 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 306 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_NE;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = TYPE_BOOL;
    (yyval) = node;
}
#line 1894 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 315 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_LE;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = TYPE_BOOL;
    (yyval) = node;
}
#line 1908 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 324 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_GE;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = TYPE_BOOL;
    (yyval) = node;
}
#line 1922 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 333 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_LT;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = TYPE_BOOL;
    (yyval) = node;
}
#line 1936 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 342 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_GT;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = TYPE_BOOL;
    (yyval) = node;
}
#line 1950 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 351 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_AND;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-2])->type;
    (yyval) = node;
}
#line 1964 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 360 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_OR;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-2])->type;
    (yyval) = node;
}
#line 1978 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 369 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_COMMA;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-2])->type;
    (yyval) = node;
}
#line 1992 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 378 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_NOT;
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-1])->type;
    (yyval) = node;
}
#line 2005 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 386 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_MINUS;
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-1])->type;
    (yyval) = node;
}
#line 2018 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 394 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_PLUS;
    node->addChild((yyvsp[0]));
    node->type = (yyvsp[-1])->type;
    (yyval) = node;
}
#line 2031 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 402 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_ADDADD;
    node->addChild((yyvsp[-1]));
    node->type = (yyvsp[-1])->type;
    (yyval) = node;
}
#line 2044 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 410 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_SUBSUB;
    node->addChild((yyvsp[-1]));
    node->type = (yyvsp[-1])->type;
    (yyval) = node;
}
#line 2057 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 418 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[0])->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_GETADD;
    node->addChild((yyvsp[0]));
    node->type = nullptr;
    (yyval) = node;
}
#line 2070 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 429 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
    map<pair<int, string>, id_info>::iterator iter_id;
    if (id_section.size() > 0)
    {
        stack<int> temp;
        while (!id_section.empty())
        {
            iter_id = idlist.find(pair<int, string>(id_section.top(), (yyval)->var_name));
            if (iter_id == idlist.end())
            {
                temp.push(id_section.top());
                id_section.pop();
            }
            else
            {
                (yyvsp[0])->id_num = iter_id->second.id;
                (yyvsp[0])->type = *iter_id->second.type;
                break;
            }
        }
        while (!temp.empty())
        {
            id_section.push(temp.top());
            temp.pop();
        }
    }
    else
    {
        (yyval)->id_num = -1;
    }
}
#line 2107 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 463 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-2])->lineno, NODE_ASSIGN);
    node->stype = STMT_ASSIGN;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2119 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 470 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-2])->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_ADD;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2132 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 478 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-2])->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_SUB;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2145 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 486 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-2])->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_MUL;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2158 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 494 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-2])->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_DIV;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2171 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 502 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-2])->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_REM;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2184 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 510 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-2])->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_AND;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2197 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 518 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-2])->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_OR;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2210 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 526 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_ASSIGN);
    node->stype = STMT_ASSIGN;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2222 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 536 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
    node->stype = STMT_IF;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2234 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 543 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-6])->lineno, NODE_STMT);
    node->stype = STMT_IF;
    node->addChild((yyvsp[-4]));
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2247 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 554 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-6])->lineno, NODE_STMT);
    node->stype = STMT_FOR;
    node->addChild((yyvsp[-4]));
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2261 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 565 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
    node->stype = STMT_WHILE;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2273 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 574 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
    node->stype = STMT_RETURN;
    (yyval) = node;
}
#line 2283 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 579 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
    node->stype = STMT_RETURN;
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2294 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 587 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
    node->stype = STMT_PRINTF;
    node->addChild((yyvsp[-2]));
    (yyval) = node;
}
#line 2305 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 593 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-6])->lineno, NODE_STMT);
    node->stype = STMT_PRINTF;
    node->addChild((yyvsp[-4]));
    node->addChild((yyvsp[-2]));
    (yyval) = node;
}
#line 2317 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 602 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
    node->stype = STMT_SCANF;
    node->addChild((yyvsp[-2]));
    (yyval) = node;
}
#line 2328 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 608 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-6])->lineno, NODE_STMT);
    node->stype = STMT_SCANF;
    node->addChild((yyvsp[-4]));
    node->addChild((yyvsp[-2]));
    (yyval) = node;
}
#line 2340 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 617 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-4])->lineno, NODE_FUNC);
    node->stype = STMT_FUNC;
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2351 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 623 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode * node = new TreeNode((yyvsp[-4])->lineno, NODE_FUNC);
    node->stype = STMT_FUNC;
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2362 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2366 "src/main.tab.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
                      yytoken, &yylval);
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
                  yystos[yystate], yyvsp);
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 629 "src/main.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
    cout << message << " at line " << lineno << endl;
    return -1;
}
