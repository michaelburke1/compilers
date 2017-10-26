//#include "token.h"
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "parser.h"

extern char* yytext;
extern int yylineno;

char * remove_quotes(char * token) {
    /* we copy the second through second to last chars from token
    and save into noQuotes */
    int size = strlen(token) - 2;
    char * noQuotes = (char*)malloc(size);
    int i;
    for (i = 0; i < size; ++i) {
        noQuotes[i] = token[i+1];
    }
    noQuotes[size] = '\0';
    return noQuotes;
}

char * replaceEscChars(char* str) {
    int i = 0, j = 0;
    int size = strlen(str);
    char * final = (char*)malloc(size);

    for (i = 0; i <= size; i++) {
        /* if str[i] is a \, then check if next char is a special char
        we need to replace */
       if (str[i] == '\\') {
            switch(str[i + 1]) {
                case 'n':
                final[j++] = '\n';
                break;
                case 'a':
                final[j++] = '\a';
                break;
                case 'b':
                final[j++] = '\b';
                break;
                case 'f':
                final[j++] = '\f';
                break;
                case 'r':
                final[j++] = '\r';
                break;
                case 'v':
                final[j++] = '\v';
                break;
                case 't':
                final[j++] = '\t';
                break;
                case '\\':
                final[j++] = '\\';
                break;
                case '\'':
                final[j++] = '\'';
                break;
                case '\"':
                final[j++] = '\"';
                break;
                case '\?':
                final[j++] = '\?';
                break;
                default:
                --i;
                ++size;
                final[j++] = str[i];
            }
            ++i;
            size--;
        }
        /* if not an escaped char, add it to the final string anyways*/
        else {
            final[j++] = str[i];
        }
    }
    /* add the null terminating character */
    final[j] = '\0';
    return final;
}


char * read_token(int token) {
    switch(token) {
        case TOKEN_OR:
        return "OR"; 

        case TOKEN_AND:
        return "AND"; 

        case TOKEN_NOT:
        return "NOT"; 

        case TOKEN_LBRACK:
        return "LBRACK"; 

        case TOKEN_RBRACK:
        return "RBRACK";  

        case TOKEN_LCURLY:
        return "LCURLY";

        case TOKEN_RCURLY:
        return "RCURLY";

        case TOKEN_CARAT:
        return "CARAT";

        case TOKEN_MULTIPLY:
        return "MULTIPLY";

        case TOKEN_DIVIDE:
        return "DIVIDE";

        case TOKEN_MODULO:
        return "MODULO";

        case TOKEN_COMMA:
        return "COMMA";

        case TOKEN_SEMI:
        return "SEMI";

        case TOKEN_LPAREN:
        return "LPAREN";

        case TOKEN_RPAREN:
        return "RPAREN";

        case TOKEN_DIGITS:
        return "DIGITS";

        case TOKEN_LT:
        return "LT";

        case TOKEN_GT:
        return "GT";

        case TOKEN_LE:
        return "LE";

        case TOKEN_GE:
        return "GE";

        case TOKEN_NOT_EQUAL:
        return "NOT_EQUAL";

        case TOKEN_EQUAL:
        return "EQUAL";

        case TOKEN_EQUIVALENT:
        return "EQUIVALENT";

        case TOKEN_COLON:
        return "COLON";

        case TOKEN_ADD:
        return "ADD";

        case TOKEN_SUBTRACT:
        return "SUBTRACT";

        case TOKEN_INCREMENT:
        return "INCREMENT";

        case TOKEN_DECREMENT:
        return "DECREMENT";

        case TOKEN_VOID:
        return "VOID";

        case TOKEN_FALSE:
        return "FALSE";

        case TOKEN_TRUE:
        return "TRUE";

        case TOKEN_RETURN:
        return "RETURN";

        case TOKEN_PRINT:
        return "PRINT";

        case TOKEN_FUNCTION:
        return "FUNCTION";

        case TOKEN_FOR:
        return "FOR";

        case TOKEN_IF:
        return "IF";

        case TOKEN_ELSE:
        return "ELSE";

        case TOKEN_ARRAY:
        return "ARRAY";

        case TOKEN_STRING:
        return "STRING";

        case TOKEN_INTEGER:
        return "INTEGER";

        case TOKEN_BOOLEAN:
        return "BOOLEAN";

        case TOKEN_CHAR:
        return "CHAR";

        case TOKEN_IDENTIFIER: {
            /* Check if the identifier is > than 256 characters*/
            int size = strlen(yytext);
            if (size > 256) {
                fprintf(stderr, "Identifiers cannot be more than 256 charcters long\n");
                exit(1);
            }
            return "IDENTIFIER";
        } 

        case TOKEN_STRING_LITERAL: {
            /* here we have to remove the quotes, and then replace escaped
            characters */
            char *noQuotes;
            noQuotes = remove_quotes(yytext);
            char *final;
            final = replaceEscChars(noQuotes);
            if (strlen(final) > 256) {
                fprintf(stderr, "String Literals cannot be longer than 256 characters\n");
                exit(1);
            }
            return final;
        } 

        case TOKEN_CHAR_LITERAL: {
            /* just remove the quotes */
            char *noQuotes;
            noQuotes = remove_quotes(yytext);
            return noQuotes;
            free(noQuotes);
        } 

        case TOKEN_ERROR:
        fprintf(stderr,"ERROR %s", yytext); return "ERROR";
        default:
        printf("we looking for something... %d", token);break;
    }
    
    return "ERROR";
}
