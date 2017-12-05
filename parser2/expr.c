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
int labels = 0;

struct reg registers[7];

void initRegisters() {
    int i;

    for (i = 0; i < 7; ++i) {
        registers[i].r = 0;
        strcat(registers[i].name, "%%r");
        if (i == 0) {
            strcat(registers[i].name, "bx");
        } else {
            strcat(registers[i].name, "1");
            strcat(registers[i].name, itoa(i));
        }
        registers[i].used = 0;
        printf("Register %d\n", registers[i].r);
        printf("Name: %s\n", registers[i].name);
        printf("In Use: %d\n", registers[i].used);
    }
}

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
            printf(" + ");
            break;
        case EXPR_EQUAL:
            printf(" = ");
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
        case EXPR_MOD:
            printf(" %% ");
            break;
        case EXPR_NEG:
            printf(" ! ");
            break;
        case EXPR_GT:
            printf(" > ");
            break;
        case EXPR_GE:
            printf(" >= ");
            break;
        case EXPR_LT:
            printf(" < ");
            break;
        case EXPR_LE:
            printf(" <= ");
            break;
        case EXPR_EQUIV:
            printf(" == ");
            break;
        case EXPR_NOT_EQUAL:
            printf(" != ");
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
            isArrayList = 1;
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
        if(e->kind == EXPR_ARRAY_IDENT) {
            printf("[");
            expr_print(e->right); 
        }
        else if(EXPR_ARRAY_ELEMENT) {
            expr_print(e->right);
        } 
        else {
            expr_print(e->right);              
        }
    }   
}

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
    if (!e) {
        return type_create(TYPE_VOID, 0,0,0);
    }

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

            while (p) {
                p = p->next; 
                arguments_cont++;
            }
            arguments[topo] = arguments_cont;
           
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
            if(l->kind!= TYPE_INTEGER || r->kind!= TYPE_INTEGER) {
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
            if(l->kind!= TYPE_INTEGER || r->kind!= TYPE_INTEGER) {
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
            if(l->kind != r->kind) {
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
            if(l->kind!=r->kind) {
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
            if(l->kind!=r->kind) {
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
        case EXPR_EXPR_LIST:
            expr_typecheck(e->left);
            expr_typecheck(e->right);
            return type_create(TYPE_VOID, 0, 0, 0);
            break;
        case EXPR_GROUP:
            r = expr_typecheck(e->right);
            return type_create(r->kind, 0, 0, 0);
            break;
        case EXPR_ARRAY_IDENT:
            s = scope_lookup(e->left->name);
            type = s->type;
            if(type->kind == TYPE_STRING){
                struct type *t = expr_typecheck(e->right->left);
                if(t->kind != TYPE_INTEGER)
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
            break;
    }
    return type_create(TYPE_VOID, 0, 0, 0);
}

void expr_codegen(struct expr *e) {
    if (!e) {
        return;
    }

    switch (e->kind) {
        case EXPR_NAME:
            e->register = scratch_alloc();
            printf("MOVQ %s, %s\n", 
                symbol_codegen(e->symbol), 
                scratch_name(e->register));
            break;
        case EXPR_ADD:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("ADDQ %s, %s\n",
                scratch_name(e->left->register),
                scratch_name(e->right->register));
            e->register = e->right->register;
            scratch_free(e->left->register);
            break;
        case EXPR_ASSIGN:
            expr_codegen(e->left);
            printf("MOVQ %s, %s\n",
                scratch_name(e->left->register),
                symbol_codegen(e->right->symbol));
            e->register = e->left->register;
            break;

    }
}

void checkParams(struct expr *e, struct param_list *p, const char *name) {
    if (!e || !p) {
        return;
    }

    if (e->kind == EXPR_EXPR_LIST) {
        checkParams(e->left,p,name); 
        checkParams(e->right,p,name);
    }
    else {
    
        cont[topo]++;
        struct param_list *aux = p;
        int i;
        for(i = 0; i < cont[topo] - 1; ++i){
           aux = aux->next;
           if(!aux){
            return;
           }        
        }
        struct type *aux2 = expr_typecheck(e);
        if (aux2->kind != aux->type->kind) {
            incrementErrors("t");
            printf("Passing wrong argument to function %s: Passing the ", name);
            type_print(aux2);
            printf(" ");
            expr_print(e);
            printf(" expected a ");
            type_print(aux->type);
            printf("\n");
        }
    }
}

int scratch_alloc() {
    int i;
    for (i = 0; i < 7; ++i) {
        if (!registers[i].used) {
            registers[i].used = 1;
            return registers[i].r;
        }
    }

    return -1;
}

void scratch_free(int r) {
    registers[r].used = 0;
}

const char * scratch_name(int r) {
    return registers[r].name;
}

int label_create() {
    return labels++;
}

const char * label_name(int label) {
    char *tmp = "";
    strcat(tmp, "'.L");
    strcat(tmp, itoa(label));
    strcat(tmp, "'");
    return tmp;
}
















