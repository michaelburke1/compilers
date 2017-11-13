#include "stmt.h"
#include "scope.h"
#include "expr.h"
#include "decl.h"
#include "param_list.h"
#include <stdlib.h>

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
/*
struct type *stmt_typecheck(struct stmt *s) {
	if(!s) return 0;
	struct type *result = stmt_typecheck(s->next);

	decl_typecheck(s->decl);
	expr_typecheck(s->init_expr);
	expr_typecheck(s->expr);
	expr_typecheck(s->next_expr);

	struct type *body = stmt_typecheck(s->body);
	if(body) {
		if(!result || body->kind == result->kind) {
			result = body;
		} else {
			printf("You must return the same type consistently within a function\n");
		    incrementErrors("t");  
        }
	}
	struct type *else_part = stmt_typecheck(s->else_body);
	if(else_part) {
		if(!result || else_part->kind == result->kind) {
			result = else_part;
		} else {
			printf("You must return the same type consistently within a function\n");
		    incrementErrors("t");
        }
	}
	if(else_part && body && else_part->kind != body->kind) {
		printf("You must return the same type consistently within a function\n");
	    incrementErrors("t");  
    }
	if(s->kind == STMT_RETURN) {
		struct type *new_result = expr_typecheck(s->expr);
        type_print(new_result);
        type_print(result);

        if(!result || new_result->kind == result->kind) {
			result = new_result;
			while(result->subtype) result = result->subtype;
		} else {
			printf("You must return the same type consistently within a function\n");
		    incrementErrors("t");  
        }
	}
	if(s->kind == STMT_PRINT) {
		expr_typecheck(s->expr->left);
	}
	return result;
}



*/















