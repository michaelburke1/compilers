/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "parser.c" /* yacc.c:339  */

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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    TOKEN_LT = 258,
    TOKEN_GT = 259,
    TOKEN_OR = 260,
    TOKEN_AND = 261,
    TOKEN_NOT = 262,
    TOKEN_COMMA = 263,
    TOKEN_COMMENT = 264,
    TOKEN_LBRACK = 265,
    TOKEN_RBRACK = 266,
    TOKEN_LCURLY = 267,
    TOKEN_RCURLY = 268,
    TOKEN_CARAT = 269,
    TOKEN_MULTIPLY = 270,
    TOKEN_DIVIDE = 271,
    TOKEN_MODULO = 272,
    TOKEN_SINGLE_LINE = 273,
    TOKEN_LPAREN = 274,
    TOKEN_RPAREN = 275,
    TOKEN_WHITESPACE = 276,
    TOKEN_LE = 277,
    TOKEN_GE = 278,
    TOKEN_NOT_EQUAL = 279,
    TOKEN_EQUAL = 280,
    TOKEN_EQUIVALENT = 281,
    TOKEN_COLON = 282,
    TOKEN_SEMI = 283,
    TOKEN_ADD = 284,
    TOKEN_SUBTRACT = 285,
    TOKEN_INCREMENT = 286,
    TOKEN_DECREMENT = 287,
    TOKEN_WHILE = 288,
    TOKEN_VOID = 289,
    TOKEN_FALSE = 290,
    TOKEN_TRUE = 291,
    TOKEN_RETURN = 292,
    TOKEN_PRINT = 293,
    TOKEN_FUNCTION = 294,
    TOKEN_FOR = 295,
    TOKEN_IF = 296,
    TOKEN_ELSE = 297,
    TOKEN_ARRAY = 298,
    TOKEN_STRING = 299,
    TOKEN_INTEGER = 300,
    TOKEN_BOOLEAN = 301,
    TOKEN_CHAR = 302,
    TOKEN_BACKLASH = 303,
    TOKEN_DIGITS = 304,
    TOKEN_LETTER = 305,
    TOKEN_IDENTIFIER = 306,
    TOKEN_STRING_LITERAL = 307,
    TOKEN_CHAR_LITERAL = 308,
    TOKEN_ERROR = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "parser.bison" /* yacc.c:355  */


    struct decl         *decl;
    struct stmt         *stmt;
    struct expr         *expr;
    struct param_list   *param_list;
    struct symbol       *symbol;
    struct type         *type;
    char                *name;

#line 173 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 80 "parser.bison" /* yacc.c:358  */


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "decl.h"
#include "stmt.h"
#include "expr.h"
#include "type.h"
#include "symbol.h"
#include "param_list.h"
#include "functions.c"
#include <string.h>
/*#define YYSTYPE struct expr * */

/*
Clunky: Manually declare the interface to the scanner generated by flex. 
*/

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

/*
Clunky: Keep the final result of the parse in a global variable,
so that it can be retrieved by main().
*/

struct decl *parser_result;



#line 222 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   122,   125,   129,   131,   133,   135,   140,
     142,   144,   146,   148,   150,   152,   154,   159,   161,   163,
     165,   167,   169,   171,   176,   179,   183,   185,   190,   195,
     198,   202,   204,   209,   214,   219,   221,   226,   228,   233,
     235,   240,   242,   244,   246,   248,   250,   252,   257,   259,
     261,   266,   268,   270,   272,   277,   279,   284,   286,   288,
     293,   295,   297,   302,   304,   306,   311,   313,   315,   317,
     319,   321,   325,   329,   333,   340,   342,   347,   350,   353,
     355,   357,   359,   361,   363,   365,   369,   371,   373,   375,
     377,   379,   381,   385,   388,   391,   393,   398,   403,   406,
     410
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_LT", "TOKEN_GT", "TOKEN_OR",
  "TOKEN_AND", "TOKEN_NOT", "TOKEN_COMMA", "TOKEN_COMMENT", "TOKEN_LBRACK",
  "TOKEN_RBRACK", "TOKEN_LCURLY", "TOKEN_RCURLY", "TOKEN_CARAT",
  "TOKEN_MULTIPLY", "TOKEN_DIVIDE", "TOKEN_MODULO", "TOKEN_SINGLE_LINE",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_WHITESPACE", "TOKEN_LE",
  "TOKEN_GE", "TOKEN_NOT_EQUAL", "TOKEN_EQUAL", "TOKEN_EQUIVALENT",
  "TOKEN_COLON", "TOKEN_SEMI", "TOKEN_ADD", "TOKEN_SUBTRACT",
  "TOKEN_INCREMENT", "TOKEN_DECREMENT", "TOKEN_WHILE", "TOKEN_VOID",
  "TOKEN_FALSE", "TOKEN_TRUE", "TOKEN_RETURN", "TOKEN_PRINT",
  "TOKEN_FUNCTION", "TOKEN_FOR", "TOKEN_IF", "TOKEN_ELSE", "TOKEN_ARRAY",
  "TOKEN_STRING", "TOKEN_INTEGER", "TOKEN_BOOLEAN", "TOKEN_CHAR",
  "TOKEN_BACKLASH", "TOKEN_DIGITS", "TOKEN_LETTER", "TOKEN_IDENTIFIER",
  "TOKEN_STRING_LITERAL", "TOKEN_CHAR_LITERAL", "TOKEN_ERROR", "$accept",
  "program", "decl_list", "decl", "stmt", "stmt_match", "stmt_list",
  "stmt_list_n", "stmt_list2", "expr_list", "expr_list_n",
  "expr_list_array", "expr", "expr_assign", "expr_or", "expr_and",
  "expr_comp", "expr_as", "expr_md", "expr_expo", "expr_neg",
  "expr_preIncr", "expr_posIncr", "expr_group", "expr_values", "expr_opt",
  "type", "type2", "param_list", "param_list_n", "param_list2",
  "array_elements", "ident", YY_NULLPTR
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
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -35

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -32,   -92,    25,   -92,   -32,     2,   -92,   -92,   146,   -92,
     222,    28,   -92,   -92,   -92,   -92,    29,   -92,   236,    46,
     -92,   -92,   -92,   -92,    50,   176,   202,   -92,    55,    52,
     211,   -32,   211,   222,   211,   211,   211,    47,    47,   -92,
     -92,   -92,   -92,   -92,     3,   -92,    83,    89,   120,    72,
     111,   100,   -92,   -92,   -92,    13,   -92,    17,    11,    64,
     211,   -32,    95,   151,    90,   -92,   -92,   140,   -92,   147,
     -92,   164,    14,    84,   -92,   -92,   -92,   236,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   -92,   -92,   211,   211,    11,   211,   211,
     160,   163,   -92,    11,   173,   -92,   -92,    42,     5,   -92,
     178,   222,   -92,   222,   211,   -92,   211,   -92,   -92,    95,
     174,    89,   120,    72,    72,    72,    72,    72,    72,   111,
     111,   100,   100,   100,   -92,     9,   180,   -92,   190,   182,
     185,   211,   211,   -92,   128,   -92,   -92,   -92,   -92,   207,
     130,   -92,   206,   -92,   -92,   -92,   -92,   189,    88,   -32,
     -92,   211,   -92,   211,    99,   -92,    15,   191,    11,   211,
     211,   201,   205,   184,   -92,   193,   138,   206,   211,   209,
     208,   212,   211,   211,    11,   197,   -92,   224,   210,   215,
     216,   217,    96,   -92,    11,   211,    99,   -92,   220,   229,
     211,    99,   230,   -92,    99,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   100,     0,     2,     4,     0,     1,     3,     0,    85,
       0,     0,    81,    79,    83,    80,     0,    92,     0,     0,
      88,    86,    90,    87,     0,     0,     0,     7,     0,     0,
      78,    94,     0,     0,     0,     0,     0,     0,     0,    76,
      75,    73,    74,    72,     0,    34,    36,    38,    40,    47,
      50,    53,    56,    59,    62,    65,    71,    67,    25,     0,
       0,    94,    77,     0,     0,    93,    96,     0,    58,     0,
      33,     0,    32,     0,    57,    60,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,     0,    30,    25,    78,    30,
       0,     0,     9,    26,     0,    24,    27,    32,    67,     5,
       0,     0,    84,     0,     0,    70,     0,    66,    82,     0,
      35,    37,    39,    42,    41,    46,    45,    44,    43,    48,
      49,    51,    52,    54,    55,     0,     0,    29,     0,     0,
       0,    78,     0,    28,     0,     8,    10,    91,    89,    95,
       0,    31,    99,    69,    12,    15,    16,     0,     0,     0,
       6,     0,    68,    78,     0,    97,     0,     0,    25,    78,
      30,     0,     0,     9,    14,     0,     0,    99,    78,     0,
       0,     0,    78,     0,     0,    10,    98,     0,    12,    15,
      16,     0,     0,    13,     0,    78,     0,    11,     0,     0,
      78,     0,     0,    17,     0,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   227,     1,   -79,   -47,   -90,   156,   -92,   -91,
     -83,   -92,   -23,   171,   -92,   194,   192,   203,    45,    85,
     -15,   -92,   132,   -92,   -92,   -88,    -9,   -27,   213,   117,
     -92,   101,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   102,   103,   175,   104,   105,   106,   136,
      70,    71,    62,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    63,    16,    24,    64,    65,
      66,   162,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,     4,    44,    59,     5,     4,    69,   138,   140,    29,
     139,    72,    73,   137,    77,    95,   137,    68,    32,     1,
     152,    74,   116,    97,    96,     6,   177,    95,    78,     8,
      35,    67,     8,   151,    78,   107,    96,    44,    25,    78,
      78,    36,    37,    38,    93,    94,    39,    40,    98,    99,
     116,   100,   101,   157,    26,   119,    30,    27,   108,    34,
      41,    67,     1,    42,    43,    60,    35,    78,   118,    31,
     146,    61,   135,    72,   107,   167,    72,   134,   179,   181,
     144,   180,    39,    40,   148,   174,   149,   137,    79,    78,
     187,   150,   109,    72,   191,    80,    41,   108,     1,    42,
      43,    87,    88,   108,   117,   193,    32,   198,   164,    78,
     112,   168,   202,    78,    92,   197,   196,   174,    35,   158,
      78,    78,   193,    81,    82,   197,    89,    90,    91,    36,
      37,    38,   129,   130,    39,    40,   169,   170,   166,   171,
     172,   176,    83,    84,    85,   107,    86,    72,    41,   199,
       1,    42,    43,    78,   203,    78,   146,   205,   160,    67,
     192,   144,   111,    78,   108,   173,   185,   113,   108,    75,
      76,   144,   114,   176,   131,   132,   133,   115,   176,   141,
       9,   176,   142,    32,   108,    10,   145,    33,    34,    11,
      12,    13,    14,    15,   108,    35,   108,   173,   147,   -34,
     153,   108,   173,   154,   108,   173,    36,    37,    38,    32,
     155,    39,    40,   156,    58,   159,   161,   163,    32,   178,
     182,    35,   188,    34,   183,    41,   -22,     1,    42,    43,
      35,     7,    36,    37,    38,   184,   189,    39,    40,   -21,
     190,    36,    37,    38,   194,   195,    39,    40,   200,   120,
     204,    41,   -20,     1,    42,    43,    17,   -18,   -19,   143,
      41,    18,     1,    42,    43,    19,    20,    21,    22,    23,
       9,   201,   122,   121,   110,    10,   165,     0,   186,    28,
      12,    13,    14,    15,   123,   124,   125,   126,   127,   128
};

static const yytype_int16 yycheck[] =
{
       0,     0,    25,    26,     4,     4,    33,    97,    99,    18,
      98,    34,    35,    96,    11,    10,    99,    32,     7,    51,
      11,    36,     8,    12,    19,     0,    11,    10,    25,    27,
      19,    31,    27,   116,    25,    58,    19,    60,    10,    25,
      25,    30,    31,    32,    31,    32,    35,    36,    37,    38,
       8,    40,    41,   141,    25,    78,    10,    28,    58,    12,
      49,    61,    51,    52,    53,    10,    19,    25,    77,    19,
      28,    19,    95,    96,    97,   163,    99,    92,   168,   170,
     103,   169,    35,    36,   111,   164,   113,   170,     5,    25,
     178,   114,    28,   116,   182,     6,    49,    97,    51,    52,
      53,    29,    30,   103,    20,   184,     7,   195,    20,    25,
      20,    12,   200,    25,    14,   194,    20,   196,    19,   142,
      25,    25,   201,     3,     4,   204,    15,    16,    17,    30,
      31,    32,    87,    88,    35,    36,    37,    38,   161,    40,
      41,   164,    22,    23,    24,   168,    26,   170,    49,   196,
      51,    52,    53,    25,   201,    25,    28,   204,    28,   159,
     183,   184,    11,    25,   164,   164,    28,    27,   168,    37,
      38,   194,    25,   196,    89,    90,    91,    13,   201,    19,
      34,   204,    19,     7,   184,    39,    13,    11,    12,    43,
      44,    45,    46,    47,   194,    19,   196,   196,    20,    25,
      20,   201,   201,    13,   204,   204,    30,    31,    32,     7,
      28,    35,    36,    28,    12,     8,    10,    28,     7,    28,
      19,    19,    13,    12,    19,    49,    42,    51,    52,    53,
      19,     4,    30,    31,    32,    42,    28,    35,    36,    42,
      28,    30,    31,    32,    20,    28,    35,    36,    28,    78,
      20,    49,    42,    51,    52,    53,    34,    42,    42,   103,
      49,    39,    51,    52,    53,    43,    44,    45,    46,    47,
      34,    42,    80,    79,    61,    39,   159,    -1,   177,    43,
      44,    45,    46,    47,    81,    82,    83,    84,    85,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    56,    57,    58,    87,     0,    57,    27,    34,
      39,    43,    44,    45,    46,    47,    81,    34,    39,    43,
      44,    45,    46,    47,    82,    10,    25,    28,    43,    81,
      10,    19,     7,    11,    12,    19,    30,    31,    32,    35,
      36,    49,    52,    53,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    87,    12,    67,
      10,    19,    67,    80,    83,    84,    85,    87,    75,    82,
      65,    66,    67,    67,    75,    77,    77,    11,    25,     5,
       6,     3,     4,    22,    23,    24,    26,    29,    30,    15,
      16,    17,    14,    31,    32,    10,    19,    12,    37,    38,
      40,    41,    58,    59,    61,    62,    63,    67,    87,    28,
      83,    11,    20,    27,    25,    13,     8,    20,    81,    67,
      68,    70,    71,    72,    72,    72,    72,    72,    72,    73,
      73,    74,    74,    74,    75,    67,    64,    65,    61,    80,
      64,    19,    19,    62,    67,    13,    28,    20,    82,    82,
      67,    65,    11,    20,    13,    28,    28,    80,    67,     8,
      28,    10,    86,    28,    20,    84,    67,    80,    12,    37,
      38,    40,    41,    58,    59,    60,    67,    11,    28,    61,
      80,    64,    19,    19,    42,    28,    86,    80,    13,    28,
      28,    80,    67,    59,    20,    28,    20,    59,    80,    60,
      28,    42,    80,    60,    20,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    73,    73,    73,    73,    74,    74,    75,    75,    75,
      76,    76,    76,    77,    77,    77,    78,    78,    78,    78,
      78,    78,    79,    79,    79,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    84,    84,    85,    86,    86,
      87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     6,     9,     4,     7,     1,
       2,     9,     3,     7,     5,     3,     3,     7,     3,     3,
       3,     2,     1,     9,     1,     0,     1,     1,     2,     1,
       0,     3,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     2,     2,     1,
       2,     2,     1,     2,     2,     1,     3,     1,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     5,     1,     5,     1,     1,     1,     1,     5,
       1,     5,     1,     1,     0,     3,     1,     5,     4,     0,
       1
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
#line 119 "parser.bison" /* yacc.c:1646  */
    { parser_result = (yyvsp[0].decl); return 0; }
#line 1467 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 123 "parser.bison" /* yacc.c:1646  */
    { (yyvsp[-1].decl)->next = (yyvsp[0].decl); (yyval.decl) = (yyvsp[-1].decl); }
#line 1473 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 125 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = 0; }
#line 1479 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 130 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-5].name), (yyvsp[-3].type), (yyvsp[-1].expr), 0, 0, 0); }
#line 1485 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 132 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-8].name), type_create(TYPE_ARRAY, 0, 0, (yyvsp[-3].type)), (yyvsp[-1].expr), 0, 0, 0); }
#line 1491 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 134 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-3].name), (yyvsp[-1].type), 0, 0, 0, 0); }
#line 1497 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-6].name), (yyvsp[-4].type), 0, (yyvsp[-1].stmt), 0, 0); }
#line 1503 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 141 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), 0, 0, 0, 0, 0); }
#line 1509 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 143 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0); }
#line 1515 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 145 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 1521 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 147 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[-1].stmt), 0); }
#line 1527 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 149 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 1533 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 151 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-2].expr), 0, (yyvsp[0].stmt), 0); }
#line 1539 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 153 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1545 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 155 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[-1].expr), 0, 0, 0); }
#line 1551 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 160 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 1557 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 162 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1563 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 164 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[-1].expr), 0, 0, 0); }
#line 1569 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 166 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[-1].stmt), 0); }
#line 1575 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 168 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0); }
#line 1581 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 170 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), 0, 0, 0, 0, 0); }
#line 1587 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 172 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 1593 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1599 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 179 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = 0; }
#line 1605 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 184 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1611 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 186 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1617 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 191 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].stmt); (yyvsp[-1].stmt)->next = (yyvsp[0].stmt); }
#line 1623 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 196 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1629 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 198 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1635 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 203 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EXPR_LIST, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1641 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 205 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1647 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 210 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1653 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 215 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1659 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 220 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1665 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 222 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1671 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 227 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1677 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 229 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1683 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 234 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1689 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 236 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1695 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 241 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1701 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 243 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1707 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 245 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EQUIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1713 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 247 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NOT_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1719 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 249 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1725 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 251 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1731 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 253 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1737 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 258 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1743 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 260 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1749 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 262 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1755 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 267 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MULT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1761 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 269 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DIVIDE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1767 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 271 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1773 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 273 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1779 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 278 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_CARAT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1785 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 280 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1791 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 285 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NEG, 0, (yyvsp[0].expr)); }
#line 1797 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 287 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NOT, 0, (yyvsp[0].expr)); }
#line 1803 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 289 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1809 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 294 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_PRE_INCREMENT, 0, (yyvsp[0].expr)); }
#line 1815 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 296 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_PRE_DECREMENT, 0, (yyvsp[0].expr)); }
#line 1821 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 298 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1827 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 303 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_POST_INCREMENT, (yyvsp[-1].expr), 0); }
#line 1833 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 305 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_POST_DECREMENT, (yyvsp[-1].expr), 0); }
#line 1839 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 307 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1845 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 312 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GROUP, 0, (yyvsp[-1].expr)); }
#line 1851 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 314 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_name((yyvsp[0].name)); }
#line 1857 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 316 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ARRAY_IDENT, expr_create_name((yyvsp[-4].name)), expr_create(EXPR_ARRAY_ELEMENT, (yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 1863 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 318 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_FUNCTION, expr_create_name((yyvsp[-3].name)), (yyvsp[-1].expr)); }
#line 1869 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 320 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ARRAY_LIST, 0, (yyvsp[-1].expr)); }
#line 1875 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 326 "parser.bison" /* yacc.c:1646  */
    { 
                    (yyval.expr) = expr_create_character_literal(strdup(yytext));
                 }
#line 1883 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 330 "parser.bison" /* yacc.c:1646  */
    {
                    (yyval.expr) = expr_create_integer_literal(atoi(yytext)); 
                }
#line 1891 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 334 "parser.bison" /* yacc.c:1646  */
    { 
                    char * txt;
                    txt = (char *)malloc(515); 
                    strcpy(txt, yytext);
                    (yyval.expr) = expr_create_string_literal(txt);
                }
#line 1902 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 341 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal(1); }
#line 1908 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 343 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal(0); }
#line 1914 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 348 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1920 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 350 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1926 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 354 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0); }
#line 1932 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 356 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHARACTER, 0, 0, 0); }
#line 1938 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 358 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, 0, 0, 0); }
#line 1944 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 360 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[-2].expr), 0, (yyvsp[0].type)); }
#line 1950 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 362 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0); }
#line 1956 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 364 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FUNCTION, 0, (yyvsp[-1].param_list), (yyvsp[-3].type)); }
#line 1962 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 366 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_VOID, 0, 0, 0); }
#line 1968 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 370 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0); }
#line 1974 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 372 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHARACTER, 0, 0, 0); }
#line 1980 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 374 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, 0, 0, 0); }
#line 1986 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 376 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[-2].expr), 0, (yyvsp[0].type)); }
#line 1992 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 378 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0); }
#line 1998 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 380 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FUNCTION, 0, (yyvsp[-1].param_list), (yyvsp[-3].type)); }
#line 2004 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 382 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_VOID, 0, 0, 0); }
#line 2010 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 386 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = (yyvsp[0].param_list); }
#line 2016 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 388 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = 0; }
#line 2022 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 392 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create((yyvsp[-2].name), (yyvsp[0].type), 0); }
#line 2028 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 394 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = (yyvsp[0].param_list); }
#line 2034 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 399 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create((yyvsp[-4].name), (yyvsp[-2].type), (yyvsp[0].param_list)); }
#line 2040 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 404 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create(EXPR_ARRAY_ELEMENT,(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2046 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 406 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2052 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 411 "parser.bison" /* yacc.c:1646  */
    { 
                    char *txt;
                    txt = (char *)malloc(sizeof(yytext));
                    strcpy(txt, yytext);
                    (yyval.name) = txt;
                }
#line 2063 "parser.c" /* yacc.c:1646  */
    break;


#line 2067 "parser.c" /* yacc.c:1646  */
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
#line 418 "parser.bison" /* yacc.c:1906  */


/*
This function will be called by bison if the parse should
encounter an error.  In principle, "str" will contain something
useful.  In practice, it often does not.
*/

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
    return 1;
}
