
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 61 "parser.bison"


    struct decl         *decl;
    struct stmt         *stmt;
    struct expr         *expr;
    struct param_list   *param_list;
    struct symbol       *symbol;
    struct type         *type;
    char                *name;



/* Line 1676 of yacc.c  */
#line 119 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


