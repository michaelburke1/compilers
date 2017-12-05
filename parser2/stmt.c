#include "stmt.h"
#include "scope.h"
#include "expr.h"
#include "decl.h"
#include "param_list.h"
#include <stdlib.h>
#include <string.h>
struct stmt * stmt_create( stmt_kind_t kind, struct decl *d, struct expr *init_expr, struct expr *e, struct expr *next_expr, struct stmt *body, struct stmt *else_body ) {

    struct stmt *s = malloc(sizeof(*s));
    s->kind = kind;
    s->decl = d;
    s->init_expr = init_expr;
    s->expr = e; 
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = 0; 

    return s;
}

void Indent(int indent) {
    int i;
    for (i = indent; i > 0; --i) printf("\t");
}

void stmt_print(struct stmt *s, int indent) {
    if (!s) return;
    switch (s->kind) {
        case STMT_DECL:
            decl_print(s->decl, indent);
            break;
        case STMT_EXPR:
            Indent(indent);
            expr_print(s->expr);
            printf(";\n");
            //if(s->next) printf("\n");
            break;
        case STMT_IF_ELSE:
            Indent(indent);
            printf("if(");
            expr_print(s->expr);
            printf(") \n");
            if (s->body->kind == STMT_BLOCK) {
                stmt_print(s->body, indent);
            } else {
                stmt_print(s->body, indent+1);
            }
            if (s->else_body) {
                Indent(indent);
                printf("else \n");
                if (s->body->kind == STMT_BLOCK) {
                    stmt_print(s->else_body, indent);
                } else {
                    stmt_print(s->else_body, indent + 1);
                }
            }
            break;
        case STMT_FOR:
            Indent(indent);
            printf("for (");
            expr_print(s->init_expr); printf(";");
            expr_print(s->expr); printf(";");
            expr_print(s->next_expr);
            printf(") ");printf("\n");
            if (s->body->kind == STMT_BLOCK) {
                stmt_print(s->body, indent);
            } else {
                stmt_print(s->body, indent + 1);
            }
            break;
        case STMT_WHILE:
            printf("NO WHILE LOOPS ALLOWED!\n");
            break;
        case STMT_PRINT:
            Indent(indent);
            printf("print ");
            expr_print(s->expr);
            printf(";\n");
            break;
        case STMT_RETURN:
            Indent(indent);
            printf("return ");
            expr_print(s->init_expr);
            printf(";\n");
            break;
        case STMT_BLOCK:
            Indent(indent);
            printf("{\n");
            stmt_print(s->body, indent + 1);
            Indent(indent);
            printf("}\n");// \n
            break;
    }
    stmt_print(s->next, indent);
}

struct stmt * stmt_resolve(struct stmt *s) {

    if (!s) return NULL;
    
    switch (s->kind) {
        case STMT_DECL:
            decl_resolve(s->decl);
            break;
        case STMT_EXPR:
            expr_resolve(s->expr);
            break;
        case STMT_IF_ELSE:
            expr_resolve(s->expr); stmt_resolve(s->body); stmt_resolve(s->else_body);
            break;
        case STMT_FOR:
            expr_resolve(s->init_expr); expr_resolve(s->expr); expr_resolve(s->next_expr);
            stmt_resolve(s->body);
            break;
        case STMT_PRINT:
            expr_resolve(s->expr);
            break;
        case STMT_RETURN:
            expr_resolve(s->init_expr);
            break;
        case STMT_BLOCK:
            scope_enter();
            stmt_resolve(s->body);
            scope_exit();
            break;
        case STMT_WHILE:
            printf("this is impossible\n");
            break;
    }
    
    return stmt_resolve(s->next); 
}

void stmt_typecheck(struct stmt *s, struct type *subtype) {
    if (!s) {
        return;
    }

    //printf("stmt tc\n");
    struct type *tReturn;

    switch (s->kind) {
        case STMT_DECL:
            decl_typecheck(s->decl);
            break;
        case STMT_EXPR:
            expr_typecheck(s->expr);
            break;
        case STMT_IF_ELSE:
            expr_typecheck(s->expr);
            stmt_typecheck(s->body, subtype);
            stmt_typecheck(s->else_body, subtype);
            break;
        case STMT_FOR:
            expr_typecheck(s->init_expr);
            expr_typecheck(s->expr);
            expr_typecheck(s->next_expr);
            stmt_typecheck(s->body, subtype);
            break;
        case STMT_PRINT:
            expr_typecheck(s->expr);
            break;
        case STMT_RETURN:
            tReturn = expr_typecheck(s->init_expr);
            if (tReturn->kind != subtype->kind) {
                incrementErrors("t");
                printf("Tried to return the ");
                type_print(tReturn);
                printf(" ");
                expr_print(s->expr);
                printf(" in a function that was asking for a return of type ");
                type_print(subtype);
                printf("\n");   
            }
            break;
        case STMT_BLOCK:
            stmt_typecheck(s->body, subtype);
            break;
        case STMT_WHILE:
            printf("Nope nope nope\n");
            break;
    }
    stmt_typecheck(s->next, subtype);
}

void stmt_codegen(struct stmt *s, FILE * file) {
    if (!s) {
        return; 
    }
    
    printf("stmt codecg we here\n");

    int else_label, done_label;

    switch(s->kind) {
        case STMT_EXPR:
            expr_codegen(s->expr, file);
            scratch_free(s->expr->Register);
            break;
        case STMT_DECL:
            decl_codegen(s->decl, file);
            break;
        case STMT_RETURN:
            if (s->init_expr) {
                printf("in return, going into expr\n");
                expr_codegen(s->init_expr, file);
                printf("expr done\n");
                printf("doing move and scratch_name\nreg: %d\n", s->init_expr->Register);
                fprintf(file,  "MOV %s, %%rax\n", scratch_name(s->init_expr->Register));
                printf("return freeing\n");
                scratch_free(s->init_expr->Register);
                printf("return freed\n");
            }
            fprintf(file,  "JMP FUNCTION%d\n", getFunctionCount());
            break;
        case STMT_IF_ELSE:
            printf("we ifing\n");
            else_label = label_create();
            done_label = label_create();
            expr_codegen(s->expr, file);
            fprintf(file,  "\tCMP $0, %s\n", scratch_name(s->expr->Register));
            scratch_free(s->expr->Register);
            char label1[50];
            label1[0] = '.'; 
            label1[1] = 'L'; 
            label1[2] = '\0';
            char num[100];
            sprintf(num, "%d", else_label);
            strcat(label1, num);
            
            fprintf(file,  "\tJE %s\n", label1);
            stmt_codegen(s->body, file); 
            
            char label2[50];
            label2[0] = '.'; 
            label2[1] = 'L'; 
            label2[2] = '0';
            char num2[100];
            sprintf(num2, "%d", done_label);
            strcat(label2, num2);
            fprintf(file,  "JMP %s\n",label2);
            fprintf(file,  "%s:\n",label1);
            stmt_codegen(s->else_body, file);
            fprintf(file,  "%s:\n",label2);
            break;
        case STMT_BLOCK:
            stmt_codegen(s->body, file);
            break;
        case STMT_FOR:
        expr_resolve(s->init_expr); expr_resolve(s->expr); expr_resolve(s->next_expr);
            stmt_resolve(s->body);
            if (s->init_expr) {
                expr_codegen(s->init_expr, file);
                scratch_free(s->init_expr->Register);
            }
            fprintf(file,  "\tFOR: \n");

            if (s->expr) {
                expr_codegen(s->expr, file);
                scratch_free(s->expr->Register);
                fprintf(file, "\tcmp $0,%s\n", scratch_name(s->expr->Register));
                fprintf(file, "\tJE FOR\n");
                printf("scratching freeing\n");
                scratch_free(s->expr->Register);
            }
            printf("stmt cging\n");
            stmt_codegen(s->body, file);
            printf("expr cging\n");
            expr_codegen(s->next_expr, file);
            fprintf(file, "\tJMP FOR\nFOR:");
            break;
        case STMT_PRINT:
            printStmt(s->expr, file);
            break;
        default:
            break;
    }

    stmt_codegen(s->next, file);
}

void printStmt(struct expr *e, FILE * file) {
  
    if (!e) {
        return;
    }

    if (e->kind == EXPR_EXPR_LIST) {
        printStmt(e->left, file);
        printStmt(e->right, file);
        return;
    }
    expr_codegen(e, file);

    fprintf(file,  "\tPUSHQ %%r10\n");
    fprintf(file,  "\tPUSHQ %%r11\n");
    fprintf(file,  "\tMOVQ %s,%%rdi\n", scratch_name(e->Register));

    if (expr_typecheck(e)->kind  == TYPE_INTEGER) {
        fprintf(file, "\tCALL print_integer\n");
    }
    else if (expr_typecheck(e)->kind  == TYPE_STRING) {
        fprintf(file, " CALL print_string\n");
    }
    else if (expr_typecheck(e)->kind  == TYPE_BOOLEAN) {
        fprintf(file, "\t  CALL print_boolean\n");
    }
    else if (expr_typecheck(e)->kind  == TYPE_CHARACTER) {
            fprintf(file, "\tCALL print_character\n");
    }

    fprintf(file,  "\tPOPQ %%r11\n");
    fprintf(file,  "\tPOPQ %%r10\n");
    scratch_free(e->Register);
}
















