#include "expr.h"
#include "symbol.h"
#include <stdlib.h>


struct expr * expr_create(expr_t kind, struct expr* left, struct expr *right) {

    struct expr *e = malloc(sizeof(*e));
    e->kind = kind;
    e->left = left;
    e->right = right;
    e->name = 0;
    e->literal_value = 0;
    e->string_literal = 0;

    return e;
}

struct expr * expr_create_name(const char *n) {
    
    struct expr *e = malloc(sizeof(*e)); 
    e->name = n;
    e->kind = EXPR_NAME;
    e->left = e->right = 0;

    return e;
}

struct expr * expr_create_boolean_literal(int c) {

    struct expr *e = malloc(sizeof(*e)); 
    e->kind = EXPR_BOOLEAN;
    e->left = e->right = 0;
    e->literal_value = c;

    return e;
}


struct expr * expr_create_integer_literal(int c) {

    struct expr *e = malloc(sizeof(*e)); 
    e->kind = EXPR_INTEGER;
    e->left = e->right = 0;
    e->literal_value = c;

    return e;
}

struct expr * expr_create_character_literal(int c) {

    struct expr *e = malloc(sizeof(*e)); 
    e->kind = EXPR_CHARACTER;
    e->left = e->right = 0;
    e->literal_value = c;

    return e;
}


struct expr * expr_create_string_literal(const char *str) {

    struct expr *e = malloc(sizeof(*e)); 
    e->kind = EXPR_STRING;
    e->left = e->right = 0;
    e->string_literal = str;
    return e;
}

void expr_print(struct expr *e) {
    if (!e) return;
    if (e->kind == EXPR_BRACKS) {
        printf("[");
        expr_print(e->left);
        printf("]");
    } else if (e->kind == EXPR_ARRAY_LITERAL) {
        printf("{");
        expr_print(e->left);
        printf("}");
    } 
    else {
        expr_print(e->left);
    } 
    //if (e->kind != EXPR_COMMA && e->kind != EXPR_NAME && e->kind != EXPR_LBRACK && e->kind != EXPR_EQUAL) printf("(");
    switch (e->kind) {
        case EXPR_ADD:
            printf(" + ");
            break;
        case EXPR_SUB:
            printf(" - ");
            break;
        case EXPR_MULT:
            printf(" * ");
            break;
        case EXPR_DIVIDE:
            printf(" / ");
            break;
        case EXPR_COMMA:
            printf(", ");
            break;
        case EXPR_EQUAL:
            printf(" = ");
            break;
        case EXPR_LBRACK:
            printf("[");
            break;
        case EXPR_RBRACK:
            printf("]");
            break;
        case EXPR_BRACKS:
      //      printf("[");
            //expr_print(e->left);
    //        printf("]");
            //expr_print(e->right); 
            break;
        case EXPR_ARRAY_LITERAL:
            break;
        case EXPR_OR:
            printf(" || ");
            break;
        case EXPR_AND:
            printf(" && ");
            break;
        case EXPR_GT:
            printf(" > ");
            break;
        case EXPR_LT:
            printf(" < ");
            break;
        case EXPR_EQUIV:
            printf(" == ");
            break;
        case EXPR_NOT_EQUAL:
            printf(" != ");
            break;
        case EXPR_GE:
            printf(" >= ");
            break;
        case EXPR_LE:
            printf(" <= ");
            break;
        case EXPR_MOD:
            printf("%c", '%');
            break;
        case EXPR_CARAT:
            printf("^");
            break;
        case EXPR_NOT:
            printf("!");
            break;
        case EXPR_INCREMENT:
            printf("++");
            break;
        case EXPR_DECREMENT:
            printf("--");
            break;
        case EXPR_FUNCTION:
            printf("(");
            break;
        case EXPR_NAME:
            printf("%s", e->name);
            break;
        case EXPR_BOOLEAN:
            if (e->literal_value)
                printf("true");
            else 
                printf("false");
            break;
        case EXPR_INTEGER:
            printf("%d", e->literal_value);
            break;
        case EXPR_CHARACTER:
            printf("'%c'", e->literal_value);
            break;
        case EXPR_STRING:
            printf("%s", e->string_literal);
            break;
        case EXPR_GROUP:
            printf("(");
            expr_print(e->right);
            printf(")");
            return;
            break;
    }
    expr_print(e->right);
    //if (e->kind != EXPR_NAME && e->kind != EXPR_COMMA && e->kind != EXPR_NAME && e->kind != EXPR_LBRACK && e->kind != EXPR_EQUAL) printf(")");
    if (e->kind == EXPR_FUNCTION) printf(")");
 //   if (e->kind == EXPR_RBRACK) printf("[");
}























