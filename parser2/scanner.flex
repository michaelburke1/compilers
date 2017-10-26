%option noyywrap
%option nounput
%{ 
#include <stdio.h>
//#include "token.h"
#include "parser.h"
int eatComments();
%}


DIGIT           [0-9]
LETTER          [a-zA-Z]
WHITESPACE      [ \t\n\r] 

%%

\/\*                                eatComments();
\/\/.*                              /* comment  */
\|\|                                return TOKEN_OR;
&&                                  return TOKEN_AND;
!                                   return TOKEN_NOT;
\[                                  return TOKEN_LBRACK;
\]                                  return TOKEN_RBRACK;
\{                                  return TOKEN_LCURLY;
\}                                  return TOKEN_RCURLY;
\^                                  return TOKEN_CARAT;
\*                                  return TOKEN_MULTIPLY;
\/                                  return TOKEN_DIVIDE;
%                                   return TOKEN_MODULO;
\(                                  return TOKEN_LPAREN;
\)                                  return TOKEN_RPAREN;
\<                                  return TOKEN_LT;
\>                                  return TOKEN_GT;
\<=                                 return TOKEN_LE;
\>=                                 return TOKEN_GE;
!=                                  return TOKEN_NOT_EQUAL;
=                                   return TOKEN_EQUAL;
==                                  return TOKEN_EQUIVALENT;
:                                   return TOKEN_COLON;
;                                   return TOKEN_SEMI;
,                                   return TOKEN_COMMA;
\+\+                                return TOKEN_INCREMENT;
\--                                 return TOKEN_DECREMENT;
\+                                  return TOKEN_ADD;
-                                   return TOKEN_SUBTRACT;  
void                                return TOKEN_VOID;  
false                               return TOKEN_FALSE;  
true                                return TOKEN_TRUE;  
return                              return TOKEN_RETURN;  
print                               return TOKEN_PRINT;  
function                            return TOKEN_FUNCTION;  
while                               return TOKEN_WHILE;
for                                 return TOKEN_FOR;  
if                                  return TOKEN_IF;  
else                                return TOKEN_ELSE;  
array                               return TOKEN_ARRAY;
string                              return TOKEN_STRING;
integer                             return TOKEN_INTEGER;
boolean                             return TOKEN_BOOLEAN;
char                                return TOKEN_CHAR;
{DIGIT}+                            return TOKEN_DIGITS;
({LETTER}|_)({DIGIT}|{LETTER}|_)*   return TOKEN_IDENTIFIER;
\"(([^"\n]|([^\\]\\\"))*)\"         return TOKEN_STRING_LITERAL;
\'({LETTER}|{DIGIT}|\\({LETTER}|{DIGIT}))\'  			return TOKEN_CHAR_LITERAL;
{WHITESPACE}                        /* do nothing */
.                                   return TOKEN_ERROR;

%% 

int eatComments() {
    int c;
    while(1) {
        while((c = input()) != '*' && c != EOF);
        if (c == '*') {
            while((c = input()) == '*');
            if (c == '/') {
                break;
            }
        }
        if (c == EOF) {
            fprintf(stderr, "error parsing comment\n");
            return 1;
        }
    }
    printf("eat\n");
    return 0;
}

