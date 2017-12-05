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
#include "scope.h"

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

int resolve(char *file) {
    yyin = fopen( file, "r" );

    if (!yyin) {
        fprintf(stderr, "file no good\n");
        exit(1);
    }

    if (!yyparse()) {
        printf("parse successful\n");
        scope_enter();
        decl_resolve(parser_result);
        printf("%d resolve errors found\n",getErrors("r"));
        if(getErrors("r") > 0) {
            return 1;
        }
        return 0;
    }
    else {
        printf("Oh no\n");
        return 1;
    }

}

int typecheck(char *file) {
    yyin = fopen( file, "r" );

    if (!yyin) {
        fprintf(stderr, "file no good\n");
        exit(1);
    }

    if (!yyparse()) {
        printf("parse successful\n");
        scope_enter();
        decl_resolve(parser_result);
        printf("%d resolve errors found\n",getErrors("r"));
        //printf("typecheckinggg");
        decl_typecheck(parser_result);
        if (getErrors("t") > 0) {
            exit(1);
        }
        return 0;
    }
    else {
        printf("Oh no\n");
        return 1;
    }

}

int codegen(char *file1, char *file2) {
    yyin = fopen( file1, "r" );

    if (!yyin) {
        fprintf(stderr, "file no good\n");
        exit(1);
    }

    if (!yyparse()) {
        printf("parse successful\n");
        scope_enter();
        decl_resolve(parser_result);
        printf("%d resolve errors found\n",getErrors("r"));
        //printf("typecheckinggg");
        decl_typecheck(parser_result);
        if (getErrors("t") > 0) {
            exit(1);
        }
        FILE * file;
        file = fopen(file2, "w+");
        decl_codegen(parser_result, file);
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
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Improper number of arguments");
        exit(1);
    }
    /* checking the flag */
    if (strcmp(argv[1],"-scan") == 0) {
        mode = 1;
    } else if (strcmp(argv[1],"-print") == 0) {
        mode = 2;
    } else if (strcmp(argv[1], "-resolve") == 0 ) {
        mode = 3;
    } else if (strcmp(argv[1], "-typecheck") == 0 ) {
        mode = 4;
    } else if (strcmp(argv[1], "-codegen") == ) {
        mode = 5;
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
    } else if (mode == 3) {
        if (resolve(argv[2])) {
            fprintf(stderr, "parse failed\n");
            return 1;
        } else {
            printf("resolve passed\n");
        }
        
    } else if (mode == 4) {
        //printf("running typecheck\n");
        if (typecheck(argv[2])) {
            fprintf(stderr, "typecheck failed\n");
            return 1;
        } else {
            printf("typecheck passed\n");
        }
    } else if (mode == 5) {
        if (codegen(argv[2], argv[3])) {
            fprintf(stderr, "codgen failed\n");
            return 1;
        } else {
            printf("codegen passed\n");
        }
    }

    return 0;

}
