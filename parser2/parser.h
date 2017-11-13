/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 168 "parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

