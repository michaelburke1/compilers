#include "stmt.h"
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
/*
void stmt_print_indent( indent )
{
	while(indent > 0) {
		printf("\t");
		indent--;
	}
}


void stmt_print( struct stmt *s, int indent )
{
	while ( s ) {
    	switch ( s->kind ) {
    		case STMT_DECL:
    			decl_print(s -> decl, indent);
    			break;
    		case STMT_EXPR:
    			stmt_print_indent( indent );
    			expr_print(s -> init_expr);
    			printf(";");
    			break;
    		case STMT_IF_ELSE:
    			stmt_print_indent( indent );
    			printf("if (");
    			expr_print(s -> init_expr);
    			printf(")\n");
    
    			//stmt_print_indent( indent );
    			//printf("{\n");
                if (s->body->kind == STMT_BLOCK)
    			     stmt_print(s->body, indent);
                else
                    stmt_print(s->body, indent+1);
    			//printf("\n");
    			//stmt_print_indent( indent );
    			//printf("}");
    
    			if (s -> else_body) {
    				// if the if statement has else block
                    printf("\n");
                    stmt_print_indent( indent );
    				printf("else \n");
                    if (s->body->kind == STMT_BLOCK)
                        stmt_print(s->else_body, indent);
                    else
                        stmt_print(s->else_body, indent+1);
                    //printf("\n");
    				//stmt_print_indent( indent );
    				//printf("}");
    			}
    			break;
    		case STMT_FOR:
    			stmt_print_indent( indent );
    			printf("for (");
    			expr_print( s->init_expr );
    			printf(";");
    			expr_print( s->expr );
    			printf(";");
    			expr_print( s->next_expr );
    			printf(")\n");
                
                if (s->body->kind == STMT_BLOCK)
                     stmt_print(s->body, indent);
                else
                    stmt_print(s->body, indent+1);
    			break;
    		case STMT_PRINT:	
                stmt_print_indent(indent);
                printf("print ");
                expr_print(s->expr);
                printf(";\n");
                break;
    		case STMT_RETURN:
    			stmt_print_indent( indent );
                printf("return ");
    			expr_print( s->init_expr );
    			printf(";");
    			break;
    		case STMT_BLOCK:
                stmt_print_indent( indent );
                printf("{\n");
                stmt_print(s->body, indent+1);
                printf("\n");
                stmt_print_indent( indent );
                printf("}");
    			break;
    	}
        if ((s->next && s->kind != STMT_DECL)) printf("\n");
    	s = s->next;   	
	}
}

*/
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
