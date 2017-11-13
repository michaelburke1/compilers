/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
/* Tokens.  */
#define TOKEN_LT 258
#define TOKEN_GT 259
#define TOKEN_OR 260
#define TOKEN_AND 261
#define TOKEN_NOT 262
#define TOKEN_COMMA 263
#define TOKEN_COMMENT 264
#define TOKEN_LBRACK 265
#define TOKEN_RBRACK 266
#define TOKEN_LCURLY 267
#define TOKEN_RCURLY 268
#define TOKEN_CARAT 269
#define TOKEN_MULTIPLY 270
#define TOKEN_DIVIDE 271
#define TOKEN_MODULO 272
#define TOKEN_SINGLE_LINE 273
#define TOKEN_LPAREN 274
#define TOKEN_RPAREN 275
#define TOKEN_WHITESPACE 276
#define TOKEN_LE 277
#define TOKEN_GE 278
#define TOKEN_NOT_EQUAL 279
#define TOKEN_EQUAL 280
#define TOKEN_EQUIVALENT 281
#define TOKEN_COLON 282
#define TOKEN_SEMI 283
#define TOKEN_ADD 284
#define TOKEN_SUBTRACT 285
#define TOKEN_INCREMENT 286
#define TOKEN_DECREMENT 287
#define TOKEN_WHILE 288
#define TOKEN_VOID 289
#define TOKEN_FALSE 290
#define TOKEN_TRUE 291
#define TOKEN_RETURN 292
#define TOKEN_PRINT 293
#define TOKEN_FUNCTION 294
#define TOKEN_FOR 295
#define TOKEN_IF 296
#define TOKEN_ELSE 297
#define TOKEN_ARRAY 298
#define TOKEN_STRING 299
#define TOKEN_INTEGER 300
#define TOKEN_BOOLEAN 301
#define TOKEN_CHAR 302
#define TOKEN_BACKLASH 303
#define TOKEN_DIGITS 304
#define TOKEN_LETTER 305
#define TOKEN_IDENTIFIER 306
#define TOKEN_STRING_LITERAL 307
#define TOKEN_CHAR_LITERAL 308
#define TOKEN_ERROR 309




/* Copy the first part of user declarations.  */


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 61 "parser.bison"
{

    struct decl         *decl;
    struct stmt         *stmt;
    struct expr         *expr;
    struct param_list   *param_list;
    struct symbol       *symbol;
    struct type         *type;
    char                *name;
}
/* Line 193 of yacc.c.  */
#line 216 "parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 80 "parser.bison"


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




/* Line 216 of yacc.c.  */
#line 261 "parser.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    14,    21,    29,    36,
      46,    48,    50,    58,    62,    65,    69,    72,    82,    86,
      88,    94,   102,   105,   107,   109,   113,   115,   119,   121,
     125,   127,   131,   133,   137,   141,   145,   149,   153,   157,
     159,   163,   167,   169,   173,   177,   179,   183,   187,   189,
     192,   195,   197,   200,   203,   205,   208,   211,   213,   217,
     221,   226,   230,   234,   236,   238,   240,   242,   244,   250,
     252,   254,   256,   258,   259,   261,   263,   265,   271,   273,
     279,   281,   283,   285,   287,   293,   295,   301,   303,   305,
     306,   311,   312,   316,   318,   322
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    57,    -1,    58,    57,    -1,    -1,    85,
      27,    79,    28,    -1,    85,    27,    79,    25,    64,    28,
      -1,    85,    27,    79,    25,    12,    62,    13,    -1,    85,
      27,    79,    25,    12,    13,    -1,    85,    27,    43,    10,
      11,    80,    25,    64,    28,    -1,    61,    -1,    60,    -1,
      41,    19,    64,    20,    60,    42,    60,    -1,    12,    62,
      13,    -1,    64,    28,    -1,    38,    63,    28,    -1,    38,
      28,    -1,    40,    19,    78,    28,    78,    28,    78,    20,
      60,    -1,    37,    78,    28,    -1,    58,    -1,    41,    19,
      64,    20,    59,    -1,    41,    19,    64,    20,    60,    42,
      61,    -1,    59,    62,    -1,    59,    -1,    64,    -1,    64,
       8,    63,    -1,    65,    -1,    85,    25,    65,    -1,    66,
      -1,    66,     5,    67,    -1,    67,    -1,    67,     6,    68,
      -1,    68,    -1,    68,     4,    69,    -1,    68,     3,    69,
      -1,    68,    26,    69,    -1,    68,    24,    69,    -1,    68,
      23,    69,    -1,    68,    22,    69,    -1,    69,    -1,    69,
      29,    70,    -1,    69,    30,    70,    -1,    70,    -1,    70,
      15,    71,    -1,    70,    16,    71,    -1,    71,    -1,    70,
      17,    71,    -1,    71,    14,    72,    -1,    72,    -1,    30,
      72,    -1,     7,    72,    -1,    73,    -1,    31,    74,    -1,
      32,    74,    -1,    74,    -1,    75,    31,    -1,    75,    32,
      -1,    75,    -1,    19,    64,    20,    -1,    85,    19,    20,
      -1,    85,    19,    63,    20,    -1,    12,    63,    13,    -1,
      10,    64,    11,    -1,    76,    -1,    53,    -1,    49,    -1,
      52,    -1,    85,    -1,    85,    10,    64,    11,    82,    -1,
      77,    -1,    36,    -1,    35,    -1,    64,    -1,    -1,    45,
      -1,    47,    -1,    44,    -1,    43,    10,    64,    11,    79,
      -1,    46,    -1,    39,    80,    19,    81,    20,    -1,    34,
      -1,    45,    -1,    47,    -1,    44,    -1,    43,    10,    78,
      11,    80,    -1,    46,    -1,    39,    79,    19,    81,    20,
      -1,    34,    -1,    83,    -1,    -1,    10,    64,    11,    82,
      -1,    -1,    84,     8,    83,    -1,    84,    -1,    85,    27,
      79,    -1,    51,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   121,   124,   127,   129,   131,   133,   135,
     139,   141,   145,   147,   149,   151,   153,   155,   157,   159,
     163,   165,   169,   171,   175,   177,   181,   185,   189,   193,
     195,   199,   201,   205,   207,   209,   211,   213,   215,   217,
     221,   223,   225,   229,   231,   233,   235,   239,   241,   245,
     247,   249,   253,   255,   257,   261,   263,   265,   269,   271,
     273,   275,   277,   279,   283,   288,   292,   299,   301,   303,
     307,   309,   313,   316,   319,   321,   323,   325,   327,   329,
     331,   335,   337,   339,   341,   343,   345,   347,   351,   354,
     357,   360,   363,   365,   369,   373
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "program", "decl_list", "decl", "stmt", "stmt_regular", "stmt_no_inner",
  "stmt_list", "expr_list", "expr", "expr_assign", "expr_or", "expr_and",
  "expr_comp", "expr_as", "expr_md", "expr_expo", "expr_neg",
  "expr_preIncr", "expr_posIncr", "expr_group", "expr_values", "expr_bool",
  "expr_opt", "type", "type2", "param_list", "array_elements",
  "param_list_n", "param", "ident", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    70,    70,    70,    70,    71,    71,    72,
      72,    72,    73,    73,    73,    74,    74,    74,    75,    75,
      75,    75,    75,    75,    76,    76,    76,    76,    76,    76,
      77,    77,    78,    78,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      82,    82,    83,    83,    84,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     6,     7,     6,     9,
       1,     1,     7,     3,     2,     3,     2,     9,     3,     1,
       5,     7,     2,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     2,
       2,     1,     2,     2,     1,     2,     2,     1,     3,     3,
       4,     3,     3,     1,     1,     1,     1,     1,     5,     1,
       1,     1,     1,     0,     1,     1,     1,     5,     1,     5,
       1,     1,     1,     1,     5,     1,     5,     1,     1,     0,
       4,     0,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    95,     0,     2,     4,     0,     1,     3,     0,    80,
       0,     0,    76,    74,    78,    75,     0,    87,     0,     0,
      83,    81,    85,    82,     0,     0,     0,     5,     0,     0,
      73,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    70,    65,    66,    64,     0,    26,    28,    30,    32,
      39,    42,    45,    48,    51,    54,    57,    63,    69,    67,
       0,     0,     0,    89,    72,     0,     0,    88,    93,     0,
      50,    67,     0,     0,     0,    24,     0,    49,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,     0,     0,     0,
       0,     8,    73,     0,     0,     0,    19,    23,    11,    10,
       0,    24,    67,     6,     0,     0,    79,     0,     0,    62,
       0,    61,     0,    58,    77,    29,    31,    34,    33,    38,
      37,    36,    35,    40,    41,    43,    44,    46,    47,     0,
      59,     0,    27,     0,     0,    16,     0,    73,     0,    22,
       0,     7,    14,    86,    84,    92,    94,     0,    25,    91,
      60,    13,    18,    15,     0,     0,     9,     0,    68,    73,
       0,     0,     0,    20,    11,    91,    73,     0,    90,     0,
      12,    21,     0,     0,    17,     0,     0,     0,     0,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   106,   107,   108,   109,   110,    74,   150,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    65,    16,    24,    66,   168,    67,    68,
      59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -117
static const yytype_int16 yypact[] =
{
     -18,  -117,    36,  -117,   -18,    18,  -117,  -117,   -23,  -117,
     111,    30,  -117,  -117,  -117,  -117,   -10,  -117,   128,    43,
    -117,  -117,  -117,  -117,    28,   244,   306,  -117,    52,    46,
     333,   -18,   333,   333,   111,   333,   333,   333,   360,   360,
    -117,  -117,  -117,  -117,  -117,    61,  -117,    92,    90,     4,
      29,    40,    85,  -117,  -117,  -117,    37,  -117,  -117,    25,
      91,    77,   333,   -18,  -117,    95,    88,  -117,   101,    84,
    -117,    24,   104,    87,   107,   117,   110,  -117,  -117,  -117,
     128,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,  -117,  -117,   333,   271,   333,
     174,  -117,   333,   298,   115,   116,  -117,   174,  -117,  -117,
     124,     1,   114,  -117,   129,   111,  -117,   -18,   128,  -117,
     333,  -117,   333,  -117,  -117,    90,     4,    29,    29,    29,
      29,    29,    29,    40,    40,    85,    85,    85,  -117,   140,
    -117,   132,  -117,   146,   125,  -117,   133,   333,   333,  -117,
     137,  -117,  -117,  -117,  -117,  -117,  -117,   138,  -117,   150,
    -117,  -117,  -117,  -117,   141,   148,  -117,   333,  -117,   333,
     174,   165,   151,  -117,   136,   150,   333,   174,  -117,   160,
    -117,  -117,   209,   169,  -117,   333,   170,   209,   149,   209
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,   190,    13,    32,  -116,    26,   -88,   -97,    16,
     108,  -117,   127,   131,   112,   -15,    55,   -27,  -117,    41,
    -117,  -117,  -117,   -99,   -16,   -20,   154,    45,   105,  -117,
       0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       5,   141,    29,   144,     5,    70,   146,    83,    84,   122,
      77,     9,   143,     4,    73,    26,    10,     4,    27,   149,
      11,    12,    13,    14,    15,   158,    85,    86,    87,   152,
      88,    69,    71,     1,    97,    97,     6,    71,    71,    71,
      25,    45,    61,    98,    98,     8,    64,    31,   164,    72,
      99,    75,    76,    30,   174,    91,    92,    93,    89,    90,
     112,   180,    62,    69,   124,    63,   184,   138,    95,    96,
     172,   188,    80,   180,   133,   134,   111,   179,    45,    78,
      79,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,   154,    82,    81,    32,    94,
     112,    33,   156,   100,   101,   113,   115,   112,   116,   117,
      36,   118,   120,   139,    75,   119,   111,    69,    64,    75,
     121,    37,    38,    39,    97,   122,    40,    41,   102,   103,
     123,   104,   105,    98,   147,   148,   157,   151,    75,    99,
      42,     8,     1,    43,    44,    17,   135,   136,   137,   153,
      18,   159,   160,   162,    19,    20,    21,    22,    23,   161,
     167,   163,     9,    64,   165,   152,   166,    10,   170,   169,
     112,    28,    12,    13,    14,    15,   175,   112,   177,   176,
     182,    32,   112,   171,    33,    64,   100,   112,   185,   112,
     187,   189,    64,    36,     7,   127,   128,   129,   130,   131,
     132,   186,   173,   181,    37,    38,    39,   142,   125,    40,
      41,   102,   103,   126,   104,   105,    32,   114,     0,    33,
     178,   100,   155,    42,     0,     1,    43,    44,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    39,     0,     0,    40,    41,   102,   103,     0,   104,
     183,    32,     0,     0,    33,    34,    35,     0,    42,     0,
       1,    43,    44,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,     0,    32,    40,
      41,    33,     0,    35,     0,     0,     0,     0,     0,     0,
      36,   140,     0,    42,     0,     1,    43,    44,     0,     0,
       0,    37,    38,    39,     0,    32,    40,    41,    33,     0,
      35,     0,     0,    32,     0,     0,    33,    36,    60,     0,
      42,     0,     1,    43,    44,    36,   145,     0,    37,    38,
      39,     0,     0,    40,    41,     0,    37,    38,    39,     0,
      32,    40,    41,    33,     0,    35,     0,    42,     0,     1,
      43,    44,    36,     0,     0,    42,     0,     1,    43,    44,
       0,     0,     0,    37,    38,    39,     0,     0,    40,    41,
      33,     0,    35,     0,     0,     0,     0,     0,     0,    36,
       0,     0,    42,     0,     1,    43,    44,     0,     0,     0,
       0,     0,     0,     0,     0,    40,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,     1,    43,    44
};

static const yytype_int16 yycheck[] =
{
       0,    98,    18,   102,     4,    32,   103,     3,     4,     8,
      37,    34,   100,     0,    34,    25,    39,     4,    28,   107,
      43,    44,    45,    46,    47,   122,    22,    23,    24,    28,
      26,    31,    32,    51,    10,    10,     0,    37,    38,    39,
      10,    25,    26,    19,    19,    27,    30,    19,   147,    33,
      25,    35,    36,    10,   170,    15,    16,    17,    29,    30,
      60,   177,    10,    63,    80,    19,   182,    94,    31,    32,
     169,   187,    11,   189,    89,    90,    60,   176,    62,    38,
      39,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,   115,     6,     5,     7,    14,
     100,    10,   118,    12,    13,    28,    11,   107,    20,     8,
      19,    27,    25,    97,    98,    11,   100,   117,   102,   103,
      13,    30,    31,    32,    10,     8,    35,    36,    37,    38,
      20,    40,    41,    19,    19,    19,   120,    13,   122,    25,
      49,    27,    51,    52,    53,    34,    91,    92,    93,    20,
      39,    11,    20,    28,    43,    44,    45,    46,    47,    13,
      10,    28,    34,   147,   148,    28,    28,    39,    20,    28,
     170,    43,    44,    45,    46,    47,    11,   177,    42,    28,
      20,     7,   182,   167,    10,   169,    12,   187,    19,   189,
      20,    42,   176,    19,     4,    83,    84,    85,    86,    87,
      88,   185,   170,   177,    30,    31,    32,    99,    81,    35,
      36,    37,    38,    82,    40,    41,     7,    63,    -1,    10,
     175,    12,   117,    49,    -1,    51,    52,    53,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    -1,    -1,    35,    36,    37,    38,    -1,    40,
      41,     7,    -1,    -1,    10,    11,    12,    -1,    49,    -1,
      51,    52,    53,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,     7,    35,
      36,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    49,    -1,    51,    52,    53,    -1,    -1,
      -1,    30,    31,    32,    -1,     7,    35,    36,    10,    -1,
      12,    -1,    -1,     7,    -1,    -1,    10,    19,    12,    -1,
      49,    -1,    51,    52,    53,    19,    28,    -1,    30,    31,
      32,    -1,    -1,    35,    36,    -1,    30,    31,    32,    -1,
       7,    35,    36,    10,    -1,    12,    -1,    49,    -1,    51,
      52,    53,    19,    -1,    -1,    49,    -1,    51,    52,    53,
      -1,    -1,    -1,    30,    31,    32,    -1,    -1,    35,    36,
      10,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    49,    -1,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    56,    57,    58,    85,     0,    57,    27,    34,
      39,    43,    44,    45,    46,    47,    79,    34,    39,    43,
      44,    45,    46,    47,    80,    10,    25,    28,    43,    79,
      10,    19,     7,    10,    11,    12,    19,    30,    31,    32,
      35,    36,    49,    52,    53,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    85,
      12,    64,    10,    19,    64,    78,    81,    83,    84,    85,
      72,    85,    64,    80,    63,    64,    64,    72,    74,    74,
      11,     5,     6,     3,     4,    22,    23,    24,    26,    29,
      30,    15,    16,    17,    14,    31,    32,    10,    19,    25,
      12,    13,    37,    38,    40,    41,    58,    59,    60,    61,
      62,    64,    85,    28,    81,    11,    20,     8,    27,    11,
      25,    13,     8,    20,    79,    67,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    71,    72,    64,
      20,    63,    65,    62,    78,    28,    63,    19,    19,    62,
      64,    13,    28,    20,    80,    83,    79,    64,    63,    11,
      20,    13,    28,    28,    78,    64,    28,    10,    82,    28,
      20,    64,    78,    59,    60,    11,    28,    42,    82,    78,
      60,    61,    20,    41,    60,    19,    64,    20,    60,    42
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 118 "parser.bison"
    { parser_result = (yyvsp[(1) - (1)].decl); return 0; ;}
    break;

  case 3:
#line 122 "parser.bison"
    { (yyvsp[(1) - (2)].decl)->next = (yyvsp[(2) - (2)].decl); (yyval.decl) = (yyvsp[(1) - (2)].decl); ;}
    break;

  case 4:
#line 124 "parser.bison"
    { (yyval.decl) = 0; ;}
    break;

  case 5:
#line 128 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (4)].name), (yyvsp[(3) - (4)].type), 0, 0, 0, 0); ;}
    break;

  case 6:
#line 130 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (6)].name), (yyvsp[(3) - (6)].type), (yyvsp[(5) - (6)].expr), 0, 0, 0); ;}
    break;

  case 7:
#line 132 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (7)].name), (yyvsp[(3) - (7)].type), 0, (yyvsp[(6) - (7)].stmt), 0, 0); ;}
    break;

  case 8:
#line 134 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (6)].name), (yyvsp[(3) - (6)].type), 0, 0, 0, 1); ;}
    break;

  case 9:
#line 136 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (9)].name), (yyvsp[(6) - (9)].type), (yyvsp[(8) - (9)].expr), 0, 0, 0); ;}
    break;

  case 10:
#line 140 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 11:
#line 142 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 12:
#line 146 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(3) - (7)].expr), 0, (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt)); ;}
    break;

  case 13:
#line 148 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[(2) - (3)].stmt), 0); ;}
    break;

  case 14:
#line 150 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[(1) - (2)].expr), 0, 0, 0); ;}
    break;

  case 15:
#line 152 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[(2) - (3)].expr), 0, 0, 0); ;}
    break;

  case 16:
#line 154 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, 0, 0, 0, 0); ;}
    break;

  case 17:
#line 156 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt), 0); ;}
    break;

  case 18:
#line 158 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, (yyvsp[(2) - (3)].expr), 0, 0, 0, 0); ;}
    break;

  case 19:
#line 160 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[(1) - (1)].decl), 0, 0, 0, 0, 0); ;}
    break;

  case 20:
#line 164 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(3) - (5)].expr), 0, (yyvsp[(5) - (5)].stmt), 0); ;}
    break;

  case 21:
#line 166 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(3) - (7)].expr), 0, (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt)); ;}
    break;

  case 22:
#line 170 "parser.bison"
    { (yyvsp[(1) - (2)].stmt)->next = (yyvsp[(2) - (2)].stmt); (yyval.stmt) = (yyvsp[(1) - (2)].stmt); ;}
    break;

  case 23:
#line 172 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 24:
#line 176 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 25:
#line 178 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_COMMA, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 26:
#line 182 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 27:
#line 186 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_EQUAL, expr_create_name((yyvsp[(1) - (3)].name)), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 28:
#line 190 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 29:
#line 194 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 30:
#line 196 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 31:
#line 200 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 32:
#line 202 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 33:
#line 206 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_GT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 34:
#line 208 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_LT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 35:
#line 210 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_EQUIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 36:
#line 212 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NOT_EQUAL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 37:
#line 214 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_GE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 38:
#line 216 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_LE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 39:
#line 218 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 40:
#line 222 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 41:
#line 224 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 42:
#line 226 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 43:
#line 230 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_MULT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 44:
#line 232 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_DIVIDE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 45:
#line 234 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 46:
#line 236 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_MOD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 47:
#line 240 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_CARAT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 48:
#line 242 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 49:
#line 246 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NEG, 0, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 50:
#line 248 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NOT, 0, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 51:
#line 250 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 52:
#line 254 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_PRE_INCREMENT, 0, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 53:
#line 256 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_PRE_DECREMENT, 0, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 54:
#line 258 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 55:
#line 262 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_POST_INCREMENT, (yyvsp[(1) - (2)].expr), 0); ;}
    break;

  case 56:
#line 264 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_POST_DECREMENT, (yyvsp[(1) - (2)].expr), 0); ;}
    break;

  case 57:
#line 266 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 58:
#line 270 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_GROUP, 0, (yyvsp[(2) - (3)].expr)); ;}
    break;

  case 59:
#line 272 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_FUNCTION, expr_create_name((yyvsp[(1) - (3)].name)), 0); ;}
    break;

  case 60:
#line 274 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_FUNCTION, expr_create_name((yyvsp[(1) - (4)].name)), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 61:
#line 276 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARRAY_LITERAL, (yyvsp[(2) - (3)].expr), 0); ;}
    break;

  case 62:
#line 278 "parser.bison"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 63:
#line 280 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 64:
#line 284 "parser.bison"
    { 
                    char *txt = replaceEscChars(yytext);
                    (yyval.expr) = expr_create_character_literal(txt[1]);
                 ;}
    break;

  case 65:
#line 289 "parser.bison"
    {
                    (yyval.expr) = expr_create_integer_literal(atoi(yytext)); 
                ;}
    break;

  case 66:
#line 293 "parser.bison"
    { 
                    char * txt;
                    txt = (char *)malloc(515); 
                    strcpy(txt, yytext);
                    (yyval.expr) = expr_create_string_literal(txt);
                ;}
    break;

  case 67:
#line 300 "parser.bison"
    { (yyval.expr) = expr_create_name((yyvsp[(1) - (1)].name)); ;}
    break;

  case 68:
#line 302 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_ARRAY_IDENT,expr_create_name((yyvsp[(1) - (5)].name)),expr_create(EXPR_ARRAY_ELEMENT,(yyvsp[(3) - (5)].expr),(yyvsp[(5) - (5)].expr)));;}
    break;

  case 69:
#line 304 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 70:
#line 308 "parser.bison"
    { (yyval.expr) = expr_create_boolean_literal(1); ;}
    break;

  case 71:
#line 310 "parser.bison"
    { (yyval.expr) = expr_create_boolean_literal(0); ;}
    break;

  case 72:
#line 314 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 73:
#line 316 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 74:
#line 320 "parser.bison"
    { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0); ;}
    break;

  case 75:
#line 322 "parser.bison"
    { (yyval.type) = type_create(TYPE_CHARACTER, 0, 0, 0); ;}
    break;

  case 76:
#line 324 "parser.bison"
    { (yyval.type) = type_create(TYPE_STRING, 0, 0, 0); ;}
    break;

  case 77:
#line 326 "parser.bison"
    { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[(3) - (5)].expr), 0, (yyvsp[(5) - (5)].type)); ;}
    break;

  case 78:
#line 328 "parser.bison"
    { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0); ;}
    break;

  case 79:
#line 330 "parser.bison"
    { (yyval.type) = type_create(TYPE_FUNCTION, 0, (yyvsp[(4) - (5)].param_list), (yyvsp[(2) - (5)].type)); ;}
    break;

  case 80:
#line 332 "parser.bison"
    { (yyval.type) = type_create(TYPE_VOID, 0, 0, 0); ;}
    break;

  case 81:
#line 336 "parser.bison"
    { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0); ;}
    break;

  case 82:
#line 338 "parser.bison"
    { (yyval.type) = type_create(TYPE_CHARACTER, 0, 0, 0); ;}
    break;

  case 83:
#line 340 "parser.bison"
    { (yyval.type) = type_create(TYPE_STRING, 0, 0, 0); ;}
    break;

  case 84:
#line 342 "parser.bison"
    { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[(3) - (5)].expr), 0, (yyvsp[(5) - (5)].type)); ;}
    break;

  case 85:
#line 344 "parser.bison"
    { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0); ;}
    break;

  case 86:
#line 346 "parser.bison"
    { (yyval.type) = type_create(TYPE_FUNCTION, 0, (yyvsp[(4) - (5)].param_list), (yyvsp[(2) - (5)].type)); ;}
    break;

  case 87:
#line 348 "parser.bison"
    { (yyval.type) = type_create(TYPE_VOID, 0, 0, 0); ;}
    break;

  case 88:
#line 352 "parser.bison"
    { (yyval.param_list) = (yyvsp[(1) - (1)].param_list); ;}
    break;

  case 89:
#line 354 "parser.bison"
    { (yyval.param_list) = 0; ;}
    break;

  case 90:
#line 358 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_ARRAY_ELEMENT,(yyvsp[(2) - (4)].expr),(yyvsp[(4) - (4)].expr));;}
    break;

  case 91:
#line 360 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 92:
#line 364 "parser.bison"
    { (yyvsp[(1) - (3)].param_list)->next = (yyvsp[(3) - (3)].param_list); (yyval.param_list) = (yyvsp[(1) - (3)].param_list); ;}
    break;

  case 93:
#line 366 "parser.bison"
    { (yyval.param_list) = (yyvsp[(1) - (1)].param_list); ;}
    break;

  case 94:
#line 370 "parser.bison"
    { (yyval.param_list) = param_list_create((yyvsp[(1) - (3)].name), (yyvsp[(3) - (3)].type), 0); ;}
    break;

  case 95:
#line 374 "parser.bison"
    { 
                    char *txt;
                    txt = (char *)malloc(sizeof(yytext));
                    strcpy(txt, yytext);
                    (yyval.name) = txt;
                ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2162 "parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 381 "parser.bison"


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

