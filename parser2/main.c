#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "token.h"
#include "functions.h"
#include "decl.h"
#include "expr.h"
#include "stmt.h"
#include "symbol.h"
#include "type.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

extern int yyparse();
extern struct decl *parser_result;

int scan(char *file) {

    yyin = fopen( file, "r" );

    if (!yyin) {
        fprintf(stderr, "file no good\n");
        exit(1);
    }

    int token = yylex();
    while(token) {
        char *output = read_token(token);
        printf("Token: %s\n", output);
        token = yylex();
    }

    return 0;

}
int parse(char *file) {

    yyin = fopen( file, "r" );

    if (!yyin) {
        fprintf(stderr, "file no good\n");
        exit(1);
    }

    if (!yyparse()) {
        printf("parse successful\n");
        decl_print(parser_result, 0);
        return 0;
    }
    else {
        printf("Oh no\n");
        return 1;
    }

}

int main(int argc, char ** argv) { 

    // sets mode to either scan(1) or parse(2)
    int mode = 0;

    /* need 3 arguments */
    if (argc != 3) {
        fprintf(stderr, "Improper number of arguments");
        exit(1);
    }
    /* checking the flag */
    if (strcmp(argv[1],"-scan") == 0) {
        mode = 1;
    } 
    else if (strcmp(argv[1],"-parse") == 0) {
        mode = 2;
    }

    if (!mode) {
        fprintf(stderr, "Improper flag, set to -parse or -scan");
        exit(1);
    }
    yyin = fopen( argv[2], "r" );
    /* check if file was opened correctly */

    if (mode == 1) {
        scan(argv[2]);
    }
    else if (mode == 2) {
        if (parse(argv[2])) {
            fprintf(stderr, "parse failed\n");
            return 1;
        }
    }

    return 0;

}
