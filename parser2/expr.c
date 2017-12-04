#include "expr.h"
#include "decl.h"
#include "symbol.h"
#include "scope.h"
#include <stdlib.h>
#include <string.h>

int topo = -1;
int cont_aux = 0;
int param_list = 0;
int arguments_cont = 0;
struct hash_table *variables = NULL;
int reloap_cont = 0;
int strings = 0;
int arguments2 = 0;
int arguments[10] = {0,0,0,0,0,0,0,0,0,0},cont[10] = {0,0,0,0,0,0,0,0,0,0};

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
    e->left = NULL;
    e->right = NULL;

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

struct expr * expr_create_character_literal(const char *c) {

    struct expr *e = malloc(sizeof(*e)); 
    e->kind = EXPR_CHARACTER;
    e->left = e->right = 0;
    e->string_literal = strdup(c);

    return e;
}


struct expr * expr_create_string_literal(const char *str) {

    struct expr *e = malloc(sizeof(*e)); 
    e->kind = EXPR_STRING;
    e->left = e->right = 0;
    e->string_literal = str;
    return e;
}

void expr_print( struct expr *e )
{
    if(e == NULL) {
        return;
    }

    expr_print(e->left);
    int isArrayList = 0;
    switch(e->kind) {
        case EXPR_ADD:
            printf("+");
            break;
        case EXPR_EQUAL:
            printf("=");
            break;
        case EXPR_SUB:
            printf("-");
            break;
        case EXPR_MULT:
            printf("*");
            break;
        case EXPR_DIVIDE:
            printf("/");
            break;
        case EXPR_MOD:
            printf("%%");
            break;
        case EXPR_NEG:
            printf("!");
            break;
        case EXPR_GT:
            printf(">");
            break;
        case EXPR_GE:
            printf(">=");
            break;
        case EXPR_LT:
            printf("<");
            break;
        case EXPR_LE:
            printf("<=");
            break;
        case EXPR_EQUIV:
            printf(" == ");
            break;
        case EXPR_NOT_EQUAL:
            printf("!=");
            break;
        case EXPR_PRE_INCREMENT:
        case EXPR_POST_INCREMENT:
            printf("++");
            break;
        case EXPR_PRE_DECREMENT:
        case EXPR_POST_DECREMENT:
            printf("--");
            break;
        case EXPR_OR:
            printf(" || ");
            break;
        case EXPR_AND:
            printf(" && ");
            break;
        case EXPR_CARAT:
            printf("^");
            break;
        case EXPR_BOOLEAN:
            if(e->literal_value)
                printf("true");
            else 
                printf("false");
            break;
        case EXPR_NAME:
            printf("%s",e->name);
            break;
        case EXPR_INTEGER:
            printf("%d",e->literal_value);
            break;
        case EXPR_CHARACTER:
            printf("%s",e->string_literal);
            break;
        case EXPR_STRING:
            printf("%s",e->string_literal);
            break;
        case EXPR_EXPR_LIST:
            printf(",");
            break;
        case EXPR_FUNCTION:
            printf("(");
            expr_print(e->right);
            printf(")");
            return;
            break;
        case EXPR_NOT:
            printf("!");
            break;
        case EXPR_ARRAY_LIST:
            isArrayList=1;
            break;
        case EXPR_GROUP:
            printf("(");
            expr_print(e->right);
            printf(")");
            return;
            break;
        case EXPR_ARRAY_ELEMENT:
            printf("]");
            if(e->right!=NULL)printf("[");
            break;
        default:
            break;
    }
    if(isArrayList == 1){
       printf("{");
       expr_print(e->right);
       printf("}");
    }
    
    else{
        if(e->kind == EXPR_ARRAY_IDENT){
            printf("[");
        expr_print(e->right); 
        }
        else if(EXPR_ARRAY_ELEMENT){
        expr_print(e->right);
        }
        else expr_print(e->right);              
    }
    
    //printf(")");      
}

/*
void expr_print(struct expr *e) {
    if (!e) return;
    
    int array = 0;
    expr_print(e->left);
     
    //if (e->kind != EXPR_COMMA && e->kind != EXPR_NAME && e->kind != EXPR_LBRACK && e->kind != EXPR_EQUAL) printf("(");
    switch (e->kind) {
        case EXPR_ARRAY_LITERAL:
            array = 1;
            break;
        case EXPR_ARRAY_ELEMENT:
            printf("]");
            if(e->right!=NULL)printf("[");
            break;
        case EXPR_ADD:
            printf(" + ");
            break;
        case EXPR_SUB:
            printf(" - ");
            break;
        case EXPR_NEG:
            printf("-");
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
        case EXPR_PRE_INCREMENT:
        case EXPR_POST_INCREMENT:
            printf("++");
            break;
        case EXPR_PRE_DECREMENT:
        case EXPR_POST_DECREMENT:
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
    if (array) {
        printf("{");
        expr_print(e->right);
        printf("}");
    } else {
        if (e->kind == EXPR_ARRAY_IDENT) {
            printf("[");
            expr_print(e->right);
        } else {
            expr_print(e->right);
        }
    }

    //if (e->kind != EXPR_NAME && e->kind != EXPR_COMMA && e->kind != EXPR_NAME && e->kind != EXPR_LBRACK && e->kind != EXPR_EQUAL) printf(")");
    if (e->kind == EXPR_FUNCTION) printf(")");
 //   if (e->kind == EXPR_RBRACK) printf("[");
}*/

void expr_resolve(struct expr *e) {
    if (!e)return;

    expr_resolve(e->left);
    expr_resolve(e->right);

    if (!e->name) return;
//    printf("%d\n", e->kind);
    if (e->kind == EXPR_NAME || e->kind == EXPR_FUNCTION) {
        struct symbol *s = scope_lookup(e->name);
        if (s) {
            e->symbol = s;
            printf("%s resolves to ", e->name);
            symbol_print(s); printf("\n");
        } else {
            if (e->kind == EXPR_NAME) {
                printf("variable %s is not defined in this scope\n", e->name);
                printf("%d\n", scope_level());
                incrementErrors("r");
                // exit(1); // exit here?
            } else if (e->kind == EXPR_FUNCTION) {
                printf("variable function %s is not defined in this scope\n", e->name);
                incrementErrors("r");
                // exit(1); // exit here? 
            }
        }
    } 
}

struct type * expr_typecheck(struct expr *e) {
    //printf("in expr tc\n");
    if (!e) return type_create(TYPE_VOID, 0,0,0);

    struct type *l = expr_typecheck(e->left);
    struct type *r = expr_typecheck(e->right);
    struct symbol *s = malloc(sizeof(*s));
    
    struct hash_table * h;
    struct type *type;  
    struct param_list *p;  

    switch(e->kind) {
        case EXPR_INTEGER:
            return type_create(TYPE_INTEGER,0,0,0);
            break;
        case EXPR_STRING:
            return type_create(TYPE_STRING,0,0,0);
            break;
        case EXPR_CHARACTER:
            return type_create(TYPE_CHARACTER,0,0,0);
            break;
        case EXPR_BOOLEAN:
            return type_create(TYPE_BOOLEAN,0,0,0);
            break;
        case EXPR_NAME:
            return type_create(e->symbol->type->kind,0,0,0);
            break;
        case EXPR_FUNCTION:
            topo++;
            arguments_cont = 0;
            cont_aux = 0;
            h = getInit();
            type = hash_table_lookup(h, e->left->name);
            p = type->params;

            checkParams(e->right, p, e->left->name);
            if (arguments[topo] < cont[topo]) {
                incrementErrors("t");
                printf("Passing too many arguments to function %s\n", e->left->name);
                return type_create(type->subtype->kind, 0, 0, 0);
            } else if (arguments[topo] > cont[topo]) {
                 incrementErrors("t");
                printf("Passing too few arguments to function %s\n", e->left->name);
                return type_create(type->subtype->kind, 0, 0, 0);
            }
            arguments[topo] = 0;
            cont[topo] = 0;
            topo--;
            return type_create(type->subtype->kind, 0, 0, 0);
            break;
        case EXPR_ADD:
            if(l->kind!= TYPE_INTEGER || r->kind!= TYPE_INTEGER ) {
                expr_print(e);
                printf("Cannot add the ");
                type_print(l);
                printf(" ");
                expr_print(e->left);
                printf(" to the ");
                type_print(r);
                printf(" ");
                expr_print(e->right);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER, 0, 0, 0);
            break;
        case EXPR_SUB:
            if(l->kind!= TYPE_INTEGER || r->kind!= TYPE_INTEGER ) {
                printf("Cannot subtract the ");
                type_print(l);
                printf(" ");
                expr_print(e->left);
                printf(" to the ");
                type_print(r);
                printf(" ");
                expr_print(e->right);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER ,0,0,0);
            break;
        case EXPR_MULT:
            if(l->kind!= TYPE_INTEGER || r->kind!= TYPE_INTEGER ) {
                printf("Cannot multiply the ");
                type_print(l);
                printf(" ");
                expr_print(e->left);
                printf(" to the ");
                type_print(r);
                printf(" ");
                expr_print(e->right);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER ,0,0,0);
            break;
        case EXPR_DIVIDE:
            if(expr_typecheck(e->left)->kind!= TYPE_INTEGER  || expr_typecheck(e->right)->kind!= TYPE_INTEGER ) {
                printf("Cannot divide the ");
                type_print(expr_typecheck(e->left));
                printf(" ");
                expr_print(e->left);
                printf(" to the ");
                type_print(expr_typecheck(e->right));
                printf(" ");
                expr_print(e->right);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER ,0,0,0);
            break;
        case EXPR_CARAT:
            if(expr_typecheck(e->left)->kind!= TYPE_INTEGER  || expr_typecheck(e->right)->kind!= TYPE_INTEGER ) {
                printf("Cannot raise the ");
                type_print(expr_typecheck(e->left));
                printf(" ");
                expr_print(e->left);
                printf(" to the ");
                type_print(expr_typecheck(e->right));
                printf(" ");
                expr_print(e->right);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER ,0,0,0);
            break;
        case EXPR_MOD:
            if(expr_typecheck(e->left)->kind!= TYPE_INTEGER  || expr_typecheck(e->right)->kind!= TYPE_INTEGER ) {
                printf("Cannot evaluate the rest of the ");
                type_print(expr_typecheck(e->left));
                printf(" ");
                expr_print(e->left);
                printf(" by the ");
                type_print(expr_typecheck(e->right));
                printf(" ");
                expr_print(e->right);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER ,0,0,0);
            break;
        case EXPR_NEG:
            if(expr_typecheck(e->right)->kind != TYPE_INTEGER) {
                printf("Cannot set the ");
                type_print(expr_typecheck(e->right));
                printf(" ");
                expr_print(e->right);
                printf(" to a negative value\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER,0,0,0);
            break;
        case EXPR_NOT:
            if(expr_typecheck(e->right)->kind != TYPE_BOOLEAN)
            {
                printf("Cannot negate the ");
                type_print(expr_typecheck(e->right));
                printf(" ");
                expr_print(e->right);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_BOOLEAN ,0,0,0);
            break;
        case EXPR_PRE_INCREMENT:
            if(r->kind != TYPE_INTEGER)
            {
                printf("Cannot increment the ");
                type_print(r);
                printf(" ");
                expr_print(e->right);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER,0,0,0);
            break;
        case EXPR_PRE_DECREMENT:
            if(r->kind != TYPE_INTEGER)
            {
                printf("Cannot decrement the ");
                type_print(r);
                printf(" ");
                expr_print(e->right);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER,0,0,0);
            break;
        case EXPR_POST_INCREMENT:
            if(l->kind != TYPE_INTEGER)
            {
                printf("Cannot increment the ");
                type_print(l);
                printf(" ");
                expr_print(e->left);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER,0,0,0);
            break;
        case EXPR_POST_DECREMENT:
            if(l->kind != TYPE_INTEGER)
            {
                printf("Cannot decrement the ");
                type_print(l);
                printf(" ");
                expr_print(e->left);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_INTEGER,0,0,0);
            break;
        case EXPR_EQUAL:
            if(l->kind!=r->kind){
                printf("Cannot make the ");
                type_print(l);
                printf(" ");
                expr_print(e->left);
                printf(" equal to the ");
                type_print(r);
                printf(" ");
                expr_print(e->right);
                printf("\n");
                incrementErrors("t");
            }   
            return type_create(expr_typecheck(e->left)->kind,0,0,0);
            break;
        case EXPR_EQUIV:
            if(l->kind!=r->kind){
                printf("Cannot compare the ");
                type_print(expr_typecheck(e->right));
                printf(" ");
                expr_print(e->right);
                printf(" with the ");
                type_print(expr_typecheck(e->left));
                printf(" ");
                expr_print(e->left);
                printf("\n");
                incrementErrors("t");

            }   
            return type_create(TYPE_BOOLEAN,0,0,0);
            break;
        case EXPR_NOT_EQUAL:
            if(l->kind!=r->kind){
                printf("Cannot compare the ");
                type_print(r);
                printf(" ");
                expr_print(e->right);
                printf(" with the ");
                type_print(l);
                printf(" ");
                expr_print(e->left);
                printf("\n");
                incrementErrors("t");

            }   
            return type_create(TYPE_BOOLEAN,0,0,0);
            break;
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GE:
        case EXPR_GT:
            if(expr_typecheck(e->left)->kind!= TYPE_INTEGER  || expr_typecheck(e->right)->kind!= TYPE_INTEGER ){
                incrementErrors("t");
                printf("Cannot compare the ");
                type_print(expr_typecheck(e->right));
                printf(" ");
                expr_print(e->right);
                printf(" with the ");
                type_print(expr_typecheck(e->left));
                printf(" ");
                expr_print(e->left);
                printf("\n");

            }
            return type_create(TYPE_BOOLEAN,0,0,0); 
            break;
        case EXPR_OR:
            if(expr_typecheck(e->left)->kind!= TYPE_BOOLEAN  || expr_typecheck(e->right)->kind!= TYPE_BOOLEAN ){
                printf("Cannot compare the ");
                type_print(expr_typecheck(e->right));
                printf(" ");
                expr_print(e->right);
                printf(" with the ");
                type_print(expr_typecheck(e->left));
                printf(" ");
                expr_print(e->left);
                printf("\n");
                incrementErrors("t");
            }
            return type_create(TYPE_BOOLEAN,0,0,0); 
            break;
        case EXPR_COMMA:
            expr_typecheck(e->left);
            expr_typecheck(e->right);
            return type_create(TYPE_VOID, 0, 0, 0);
            break;
        case EXPR_ARRAY_IDENT:
            s = scope_lookup(e->left->name);
            type = s->type;
            if(type->kind == TYPE_STRING){
                struct type *t = expr_typecheck(e->right->left);
                if(t->kind !=TYPE_INTEGER)
                {
                    printf("Index for the string %s needs to be and integer\n", e->left->name);
                    incrementErrors("t");
                }
                return type_create(TYPE_CHARACTER, 0, 0, 0);
            }
            while(type->kind == TYPE_ARRAY) {
                type = type->subtype;
            }
            return type_create(type->kind, 0, 0, 0);   
            break;
        default:
            // printf("\nthis: \n");
            // expr_print(e);
            // printf("\n%d\n", e->kind);
            break;
        //case EXPR_LIST
    }
    return type_create(TYPE_VOID, 0, 0, 0);
}

void checkParams(struct expr *e, struct param_list *p, const char *name) {
    if (!e || !p) {
        return;
    }

    if(e->kind == EXPR_COMMA){checkParams(e->left,p,name); checkParams(e->right,p,name);}
    else{
    
        cont[topo]++;
        struct param_list *aux = p;
        int i;
        for(i=0;i<cont[topo]-1;i++){
           aux = aux->next;
           if(!aux){
            return;
           }        
        }
        struct type *aux2 = expr_typecheck(e);
        if(aux2->kind != aux->type->kind){
            incrementErrors("t");
            printf("Passing wrong argument to function %s: Passing the ",name);
            type_print(aux2);
            printf(" ");
            expr_print(e);
            printf(" expected a ");
            type_print(aux->type);
            printf("\n");
        }
    }

}

/*
struct type *expr_typecheck(struct expr *e) {
	if(!e) { 
        return type_create(TYPE_VOID, 0, 0, 0);
    }
    
    struct param_list *param_ptr;
	struct expr *expr_ptr;
	struct type *left;
	struct type *right;
	
    switch(e->kind) {
		case EXPR_GROUP:
            printf("group?\n");
			left = expr_typecheck(e->left);
			right = expr_typecheck(e->right);
			return type_create(TYPE_VOID, 0, 0, 0);
			break;
		case EXPR_EQUAL:
            printf("equal\n");
            left = expr_typecheck(e->left);
			right = expr_typecheck(e->right);
			while(left->kind == TYPE_ARRAY) left = left->subtype;
			while(right->kind == TYPE_ARRAY) left = left->subtype;
			if(type_equals(left, right) && left->kind != TYPE_FUNCTION) {
				return type_copy(left);
			} else {
				printf("Cannot assign ");
				type_print(right);
				printf(" to ");
				type_print(left);
				if(e->left->name) {
					printf(" %s\n", e->left->name);
				} else {
					printf("\n");
				}
				incrementErrors("t"); 
                return left;
			}
			break;
		case EXPR_NOT_EQUAL:
		case EXPR_EQUIV:
			left = expr_typecheck(e->left);
			right = expr_typecheck(e->right);
			if(type_equals(left, right) && left->kind != TYPE_FUNCTION && left->kind != TYPE_ARRAY) {
				return type_create(TYPE_BOOLEAN, 0, 0, 0);
			} else {
				printf("Cannot perform logical equals operation on ");
				type_print(left);
				printf(" and ");
				type_print(right);
				printf("\n");
				incrementErrors("t"); 
                return type_create(TYPE_BOOLEAN, 0, 0, 0);
			}
			break;
		case EXPR_LT:
		case EXPR_GT:
		case EXPR_LE:
		case EXPR_GE:
			left = expr_typecheck(e->left);
			right = expr_typecheck(e->right);
			if(left->kind == TYPE_INTEGER && right->kind == TYPE_INTEGER) {
				return type_create(TYPE_BOOLEAN, 0, 0, 0);
			} else {
				printf("Cannot perform boolean operations on ");
				type_print(left);
				printf(" and ");
				type_print(right);
				printf("\n");
				incrementErrors("t"); 
                return type_create(TYPE_BOOLEAN, 0, 0, 0);
			}
			break;
		case EXPR_ADD:
		case EXPR_SUB:
		case EXPR_MULT:
		case EXPR_DIVIDE:
		case EXPR_MOD:
		case EXPR_CARAT:
            printf("arthimetic\n");
			left = expr_typecheck(e->left);
			right = expr_typecheck(e->right);
			if(left->kind == TYPE_INTEGER && right->kind == TYPE_INTEGER) {
				printf("integer\n");
                return type_create(TYPE_INTEGER, 0, 0, 0);
			} else {
				printf("Cannot perform arithmetic operations on ");
				type_print(left);
				printf(" and ");
				type_print(right);
				printf("\n");
				incrementErrors("t"); 
                return type_create(TYPE_INTEGER, 0, 0, 0);
			}
			break;
		case EXPR_NEG:
			right = expr_typecheck(e->right);
			if(right->kind == TYPE_INTEGER) {
				return type_create(TYPE_INTEGER, 0, 0, 0);
			} else {
				printf("Cannot take the negative of ");
				type_print(right);
				printf("\n");
				incrementErrors("t"); 
                return type_create(TYPE_INTEGER, 0, 0, 0);
			}
			break;
		case EXPR_OR:
		case EXPR_AND:
			left = expr_typecheck(e->left);
			right = expr_typecheck(e->right);
			if(left->kind == TYPE_BOOLEAN && right->kind == TYPE_BOOLEAN) {
				return type_create(TYPE_BOOLEAN, 0, 0, 0);
			} else {
				printf("Cannot perform logical operations on ");
				type_print(left);
				printf(" and ");
				type_print(right);
				printf("\n");
				incrementErrors("t"); 
                return type_create(TYPE_BOOLEAN, 0, 0, 0);
			}
			break;
		case EXPR_NOT:
			right = expr_typecheck(e->right);
			if(right->kind == TYPE_BOOLEAN) {
				return type_create(TYPE_BOOLEAN, 0, 0, 0);
			} else {
				printf("Cannot perform a logical not on ");
				type_print(right);
				printf("\n");
				incrementErrors("t"); 
                return type_create(TYPE_BOOLEAN, 0, 0, 0);
			}
			break;
		case EXPR_PRE_INCREMENT:
		case EXPR_PRE_DECREMENT:
			right = expr_typecheck(e->right);
			if(right->kind == TYPE_INTEGER) {
				return type_create(TYPE_INTEGER, 0, 0, 0);
			} else {
				printf("Cannot perform integer operations on ");
				type_print(right);
				printf("\n");
				incrementErrors("t"); 
                return type_create(TYPE_INTEGER, 0, 0, 0);
			}
			break;
		case EXPR_POST_INCREMENT:
		case EXPR_POST_DECREMENT:
			left = expr_typecheck(e->left);
			if(left->kind == TYPE_INTEGER) {
				return type_create(TYPE_INTEGER, 0, 0, 0);
			} else {
				printf("Cannot perform integer operations on ");
				type_print(left);
				printf("\n");
				incrementErrors("t"); 
                return type_create(TYPE_INTEGER, 0, 0, 0);
			}
			break;
		case EXPR_FUNCTION:
            printf("function!\n");
	        struct param_list *param_ptr = e->left->symbol->type->params;
			printf("after ptr\n");
            expr_ptr = e->right;
			while(param_ptr) {
				if(!expr_ptr) {
					printf("Not enough arguments given for function %s\n", e->left->name);
					incrementErrors("t"); 
                    break;
				}
				if(!type_equals(param_ptr->type, expr_typecheck(expr_ptr->left))) {
					printf("Function %s requires a paramater of type ", e->left->name);
					type_print(param_ptr->type);
					printf(" but ");
					expr_print(expr_ptr->left);
					printf(" is of type ");
					type_print(expr_typecheck(expr_ptr->left));
					printf("\n");
					incrementErrors("t"); 
                    break;
				}
				param_ptr = param_ptr->next;
				expr_ptr = expr_ptr->right;
			}
			if(expr_ptr) {
				printf("Too many arguments given for function %s\n", e->left->name);
		        incrementErrors("t");
            }
			return e->left->symbol->type->subtype;
			break;
		case EXPR_BOOLEAN:
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_INTEGER:
			return type_create(TYPE_INTEGER, 0, 0, 0);
			break;
		case EXPR_CHARACTER:
			return type_create(TYPE_CHARACTER, 0, 0, 0);
			break;
		case EXPR_STRING:
			return type_create(TYPE_STRING, 0, 0, 0);
			break;
		case EXPR_NAME:
			if (e->symbol) return e->symbol->type;
			return type_create(TYPE_VOID, 0, 0, 0);
			break;
		case EXPR_LBRACK:
			left = expr_typecheck(e->left);
			right = expr_typecheck(e->right);
			if(right->kind == TYPE_INTEGER) {
				return type_create(left->subtype->kind, 0, 0, 0);
			} else {
				printf("Cannot use ");
				type_print(right);
				printf(" as an array index. Must use an integer\n");
				incrementErrors("t");
                return type_create(left->subtype->kind, 0, 0, 0);
			}
			break;
		case EXPR_ARRAY_LITERAL:
			left = expr_typecheck(e->right->left);
			return type_create(TYPE_ARRAY, 0, 0, left->subtype);
			break;
	}
	return type_create(TYPE_VOID, 0, 0, 0);
}





*/

















