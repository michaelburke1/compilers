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
int loopCount = 0;
int strings = 0;
int argCount = 0;
int arguments[10] = {0,0,0,0,0,0,0,0,0,0},cont[10] = {0,0,0,0,0,0,0,0,0,0};
int labels = 0;
int count =0;

int registers[16] = {1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0};

struct expr * expr_create(expr_t kind, struct expr* left, struct expr *right) {

    struct expr *e = malloc(sizeof(*e));
    e->kind = kind;
    e->left = left;
    e->right = right;
    e->name = 0;
    e->literal_value = 0;
    e->string_literal = 0;
    e->Register = -1;

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
            printf(" -");
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

void expr_codegen(struct expr *e, FILE * file) {
    if (!e) {
        return;
    }
    struct type *type;
    struct hash_table *h;
    struct nReg *nR;

    switch (e->kind) {
        case EXPR_NAME:
            e->Register = scratch_alloc();
            if (e->symbol->kind == SYMBOL_LOCAL && e->symbol->type->kind == TYPE_ARRAY) {
                fprintf(file,  "\tLEAQ %s,%s\n", symbol_codegen(e->symbol, file), scratch_name(e->Register));
            } else {
                fprintf(file,  "\tMOVQ %s, %s\n", symbol_codegen(e->symbol, file), scratch_name(e->Register));
            }
            break;
        case EXPR_ADD:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file,  "ADDQ %s, %s\n",
                scratch_name(e->left->Register),
                scratch_name(e->right->Register));
            e->Register = e->right->Register;
            scratch_free(e->left->Register);
            break;
        case EXPR_SUB:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file,  "SUBQ %s, %s\n",
                scratch_name(e->right->Register), // switched of ADD
                scratch_name(e->left->Register));
            e->Register = e->left->Register;
            scratch_free(e->right->Register);
            break;
        case EXPR_NEG:
            expr_codegen(e->right, file);
            fprintf(file,  "\tMOVEQ $-1, %%rax\n");
            fprintf(file, "\tIMULQ %s\n", scratch_name(e->right->Register));      
            fprintf(file, "\tMOVQ %%rax,%s\n", scratch_name(e->right->Register));
            e->Register = e->right->Register;
            break;
        case EXPR_MULT:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tMOVQ %s,%%rax\n", scratch_name(e->left->Register));
            fprintf(file, "\tIMULQ %s\n", scratch_name(e->right->Register));      
            fprintf(file, "\tMOVQ %%rax,%s\n", scratch_name(e->right->Register));
            scratch_free(e->left->Register);
            e->Register = e->right->Register;
            break;
        case EXPR_DIVIDE:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tMOVQ %s,%%rax\n", scratch_name(e->left->Register));
            fprintf(file, "\tCDQ\n");
            fprintf(file, "\tIDIVQ %s\n", scratch_name(e->right->Register));
            fprintf(file, "\tMOVQ %%rax,%s\n", scratch_name(e->right->Register));
            scratch_free(e->left->Register);
            e->Register = e->right->Register;
            break;
        case EXPR_EQUAL:
            expr_codegen(e->right, file);
            if (e->left->kind == EXPR_NAME) {
                if (e->right->kind == EXPR_ARRAY_IDENT) {
                    fprintf(file,  "\tMOVQ %s, %s\n",
                        scratch_name(e->right->left->Register),
                        symbol_codegen(e->left->symbol, file));
                } else {
                    fprintf(file,  "\tMOVQ %s, %s\n",
                        scratch_name(e->right->Register),
                        symbol_codegen(e->left->symbol, file));
                }
            } else {
                fprintf(file,  "\tMOVQ %s,%s\n", 
                    scratch_name(e->right->Register), 
                    symbol_codegen(e->left->right->symbol, file));
                expr_codegen(e->left, file);
            }
            
            e->Register = e->right->Register;
            break;
        case EXPR_MOD:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tMOVQ %s,%%rax\n", scratch_name(e->left->Register));
            fprintf(file, "\tcdq\n");
            fprintf(file, "\tidivq %s\n", scratch_name(e->right->Register));
            fprintf(file, "\tMOVQ %%rdx,%s\n", scratch_name(e->right->Register));
            scratch_free(e->left->Register);
            e->Register = e->right->Register;
            break;
        case EXPR_PRE_INCREMENT:
            expr_codegen(e->right, file);
            fprintf(file, "\tMOVQ %s,%s\n", scratch_name(e->right->Register), scratch_name(e->right->Register));
            fprintf(file, "\taddq $1,%s\n", scratch_name(e->right->Register));     
            fprintf(file, "\tMOVQ %s,%s\n", scratch_name(e->right->Register),symbol_codegen(e->right->symbol, file));
            break;
        case EXPR_PRE_DECREMENT:
            expr_codegen(e->left, file);
            fprintf(file, "\tMOVQ %s,%s\n", scratch_name(e->right->Register), scratch_name(e->right->Register));
            fprintf(file, "\tsubq $1,%s\n", scratch_name(e->right->Register));     
            fprintf(file, "\tMOVQ %s,%s\n", scratch_name(e->right->Register),symbol_codegen(e->right->symbol, file));
            break;
        case EXPR_POST_INCREMENT:
            expr_codegen(e->left, file);
            fprintf(file, "\tMOVQ %s,%s\n", scratch_name(e->left->Register), scratch_name(e->left->Register));
            fprintf(file, "\taddq $1,%s\n", scratch_name(e->left->Register));     
            fprintf(file, "\tMOVQ %s,%s\n", scratch_name(e->left->Register),symbol_codegen(e->left->symbol, file));
            break;
        case EXPR_POST_DECREMENT:
            expr_codegen(e->left, file);
            fprintf(file, "\tMOVQ %s,%s\n", scratch_name(e->left->Register), scratch_name(e->left->Register));
            fprintf(file, "\tsubq $1,%s\n", scratch_name(e->left->Register));     
            fprintf(file, "\tMOVQ %s,%s\n", scratch_name(e->left->Register),symbol_codegen(e->left->symbol, file));
            break;
        case EXPR_LT:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tCMP %s,%s\n", scratch_name(e->right->Register), scratch_name(e->left->Register));
            fprintf(file, "\tJL R%d\n", loopCount);
            fprintf(file, "\tMOVQ $0,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJMP R%d\n", loopCount+1);
            fprintf(file, "R%d:\n", loopCount);
            fprintf(file, "\tMOVQ $1,%s\n", scratch_name(e->right->Register));
            fprintf(file, "R%d:\n", loopCount+1);
            e->Register = e->right->Register;
            scratch_free(e->left->Register);    
            loopCount += 2;
            break;
        case EXPR_GT:                       //nao se esqueca de testar todos os reloaps
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tcmp %s,%s\n", scratch_name(e->right->Register), scratch_name(e->left->Register));
            fprintf(file, "\tjg R%d\n",loopCount); // diferenca entre JMP e jl
            fprintf(file, "\tMOVQ $0,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJMP R%d\n",loopCount+1);
            fprintf(file, "R%d:\n",loopCount);
            fprintf(file, "\tMOVQ $1,%s\n", scratch_name(e->right->Register));
            fprintf(file, "R%d:\n",loopCount+1);
            e->Register = e->right->Register;
            scratch_free(e->left->Register); 
            loopCount+=2;
            break;
        case EXPR_LE:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tCMP %s,%s\n", scratch_name(e->right->Register), scratch_name(e->left->Register));
            fprintf(file, "\tJLE R%d\n",loopCount);
            fprintf(file, "\tMOVQ $0,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJMP R%d\n",loopCount+1);
            fprintf(file, "R%d:\n",loopCount);
            fprintf(file, "\tMOVQ $1,%s\n", scratch_name(e->right->Register));
            fprintf(file, "R%d:\n",loopCount+1);
            e->Register = e->right->Register;
            scratch_free(e->left->Register); 
            loopCount+=2;
            break;
        case EXPR_GE:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tCMP %s,%s\n", scratch_name(e->right->Register), scratch_name(e->left->Register));
            fprintf(file, "\tJGE R%d\n",loopCount);
            fprintf(file, "\tMOVQ $0,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJMP R%d\n",loopCount+1);
            fprintf(file, "R%d:\n",loopCount);
            fprintf(file, "\tMOVQ $1,%s\n", scratch_name(e->right->Register));
            fprintf(file, "R%d:\n",loopCount+1);
            e->Register = e->right->Register;
            scratch_free(e->left->Register); 
            loopCount+=2;
            break;
        case EXPR_EQUIV:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tCMP %s,%s\n", scratch_name(e->right->Register), scratch_name(e->left->Register));
            fprintf(file, "\tJE R%d\n",loopCount);
            fprintf(file, "\tMOVQ $0,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJMP R%d\n",loopCount+1);
            fprintf(file, "R%d:\n",loopCount);
            fprintf(file, "\tMOVQ $1,%s\n", scratch_name(e->right->Register));
            fprintf(file, "R%d:\n",loopCount+1);
            scratch_free(e->left->Register);
            e->Register = e->right->Register;
            loopCount+=2;
            break;
        case EXPR_NOT_EQUAL:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tCMP %s,%s\n", scratch_name(e->right->Register), scratch_name(e->left->Register));
            fprintf(file, "\tJE R%d\n",loopCount);
            fprintf(file, "\tMOVQ $1,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJMP R%d\n",loopCount+1);
            fprintf(file, "R%d:\n",loopCount);
            fprintf(file, "\tMOVQ $0,%s\n", scratch_name(e->right->Register));
            fprintf(file, "R%d:\n",loopCount+1);
            scratch_free(e->left->Register);
            e->Register = e->right->Register;
            loopCount+=2;
            break;
        case EXPR_AND:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tCMP $0,%s\n", scratch_name(e->left->Register));
            fprintf(file, "\tJE R%d\n",loopCount+1);
            fprintf(file, "\tCMP $0,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJE R%d\n",loopCount+1);   
            fprintf(file, "\tMOVQ $1,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJMP R%d\n",loopCount);
            fprintf(file, "R%d:\n",loopCount+1);
            fprintf(file, "\tMOVQ $0,%s\n", scratch_name(e->right->Register));
            fprintf(file, "R%d:\n",loopCount);
            e->Register = e->right->Register;
            scratch_free(e->left->Register); 
            loopCount+=2;
            break;
        case EXPR_OR:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            fprintf(file, "\tCMP $1,%s\n", scratch_name(e->left->Register));
            fprintf(file, "\tJE R%d\n",loopCount+1);
            fprintf(file, "\tCMP $1,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJE R%d\n",loopCount+1);   
            fprintf(file, "\tMOVQ $0,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJMP R%d\n",loopCount);
            fprintf(file, "R%d:\n",loopCount+1);
            fprintf(file, "\tMOVQ $1,%s\n", scratch_name(e->right->Register));
            fprintf(file, "R%d:\n",loopCount);
            loopCount+=2;
            break;
        case EXPR_CARAT:
            expr_codegen(e->left, file);
            expr_codegen(e->right, file);
            e->Register = scratch_alloc();
            fprintf(file, "\tPUSHQ %%r10\n");
            fprintf(file, "\tPUSHQ %%r11\n");
            fprintf(file, "\tMOVQ %s,%%rdi\n", scratch_name(e->left->Register));
            fprintf(file, "\tMOVQ %s,%%rsi\n", scratch_name(e->right->Register));
            fprintf(file, "\tCALL integer_power\n");
            fprintf(file, "\tPOPQ %%r11\n");
            fprintf(file, "\tPOPQ %%r10\n");
            fprintf(file, "\tMOVQ %%rax,%s\n", scratch_name(e->Register));
            scratch_free(e->left->Register);
            scratch_free(e->right->Register);   
            break;
        case EXPR_NOT:
            e->Register = scratch_alloc();
            expr_codegen(e->right, file);
            fprintf(file, "\tCMP $1,%s\n", scratch_name(e->right->Register));
            fprintf(file, "\tJE R%d\n",loopCount+1);
            fprintf(file, "\tMOVQ $1,%s\n", scratch_name(e->Register));
            fprintf(file, "\tJMP R%d\n",loopCount);
            fprintf(file, "\tR%d:\n",loopCount+1);
            fprintf(file, "\tMOVQ $0,%s\n", scratch_name(e->Register));
            fprintf(file, "R%d:\n",loopCount);
            scratch_free(e->right->Register);
            loopCount+=1;
            break;
        case EXPR_GROUP:
            expr_codegen(e->right, file);
            e->Register = e->right->Register;
            break;
                
        case EXPR_FUNCTION:            
            argCount = 0;
            e->Register = scratch_alloc();
            nR = NULL;
            
            findArgument(e->right, &nR, file);
            
            fprintf(file, "\tPUSHQ %%r10\n");
            fprintf(file, "\tPUSHQ %%r11\n");
            argCount = 0;
            while(nR) {
                if(argCount == 0){
                    fprintf(file, "\tMOVQ %s,%%rdi\n", scratch_name(nR->Register));
                    scratch_free(nR->Register);
                }
                if(argCount == 1){
                    fprintf(file, "\tMOVQ %s,%%rsi\n", scratch_name(nR->Register));
                    scratch_free(nR->Register);
                }
                if(argCount == 2){
                    fprintf(file, "\tMOVQ %s,%%rdx\n", scratch_name(nR->Register));
                    scratch_free(nR->Register);
                }
                if(argCount == 3){
                    fprintf(file, "\tMOVQ %s,%%rcx\n", scratch_name(nR->Register));
                    scratch_free(nR->Register);  
                }
                if(argCount == 4){
                    fprintf(file, "\tMOVQ %s,%%r8\n", scratch_name(nR->Register));
                    scratch_free(nR->Register);  
                }
                if(argCount == 5){
                    fprintf(file, "\tMOVQ %s,%%r9\n", scratch_name(nR->Register)); 
                    scratch_free(nR->Register);
                }
                if(argCount>5){
                    printf("Too many arguments\n");
                    exit(0);
                }
                argCount++;
                nR = nR->next;
            }
            fprintf(file, "\tCALL %s\n",e->left->name);
            fprintf(file, "\tPOPQ %%r11\n");
            fprintf(file, "\tPOPQ %%r10\n");
            fprintf(file, "\tMOVQ %%rax,%s\n", scratch_name(e->Register));
            h = getInit();
            argCount = 0;
            type = hash_table_lookup(h, e->left->name);
            if(type->subtype->kind == TYPE_VOID) {
                scratch_free(e->Register);  
            }
            break;
        case EXPR_INTEGER:
            e->Register = scratch_alloc();
            fprintf(file, "\tMOVQ $%d,%s\n",e->literal_value, scratch_name(e->Register));
            break;
        case EXPR_BOOLEAN:
            e->Register = scratch_alloc();
            fprintf(file, "\tMOVQ $%d,%s\n",e->literal_value, scratch_name(e->Register));
            break;
        case EXPR_CHARACTER:
            e->Register = scratch_alloc();
            fprintf(file, "\tMOVQ $%s,%s\n",e->string_literal, scratch_name(e->Register));
        break;
        case EXPR_STRING:
            e->Register = scratch_alloc();
            fprintf(file, ".data\n.str%d:    .string %s\n.text\n LEAQ .str%d, %s\n", 
                strings,
                e->string_literal,
                strings,
                scratch_name(e->Register));
            strings++;
            break;
        case EXPR_ARRAY_LIST:
            expr_codegen(e->right, file);
            if (e->right->kind == EXPR_INTEGER) {
                fprintf(file, "%d", e->literal_value);
            } else {
                expr_codegen(e->right, file);
            } 
            break;
        case EXPR_EXPR_LIST:
            printf("hit%d\n", count);
            //expr_codegen(e->left, file);
            if (e->left->kind == EXPR_INTEGER) { 
                fprintf(file, "%d", e->left->literal_value);
                count++;
            }
            fprintf(file, ", ");
            if (e->right->kind == EXPR_INTEGER) {
                fprintf(file, "%d", e->right->literal_value);
                count++;
                return;
            } else {
                expr_codegen(e->right, file);
            } 
            break;
        case EXPR_ARRAY_IDENT:
            e->Register = scratch_alloc();
            fprintf(file, "\tLEAQ %s, %s\n", e->left->name, scratch_name(e->Register));
            e->right->left->Register = scratch_alloc();
            fprintf(file, "\tMOVQ $%d, %s\n", e->right->left->literal_value, scratch_name(e->right->left->Register));
            fprintf(file, "\tMOVQ 4(%s, %s, 4), %s\n", scratch_name(e->Register), scratch_name(e->right->left->Register), scratch_name(e->Register));
            scratch_free(e->right->left->Register);
            break;
        default:
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
    for (i = 0; i < 16; ++i) {
        if (!registers[i]) {
            registers[i] = 1;
            return i;
        }
    }
    printf("Ran out of registers! no!\n");
    return -1;
}

void scratch_free(int r) {
    registers[r] = 0;
    registers[0] = 1;
    registers[2] = 1;    
    registers[3] = 1;
    registers[4] = 1;
    registers[5] = 1;
    registers[6] = 1;
    registers[7] = 1;
    registers[8] = 1;
    registers[9] = 1;
}

const char * scratch_name(int r) {
    if(r == 0)return "%rax";
    if(r == 1)return "%rbx";
    if(r == 2)return "%rcx";
    if(r == 3)return "%rdx";
    if(r == 4)return "%rsi";
    if(r == 5)return "%rdi";
    if(r == 6)return "%rbp";
    if(r == 7)return "%rsp";
    if(r == 8)return "%r8";
    if(r == 9)return "%r9";
    if(r == 10)return "%r10";
    if(r == 11)return "%r11";
    if(r == 12)return "%r12";
    if(r == 13)return "%r13";
    if(r == 14)return "%r14";
    if(r == 15)return "%r15";
    return "";
}

int label_create() {
    return labels++;
}

void findArgument(struct expr *e, struct nReg ** nR, FILE * file) {
    if (!e) {
        return;
    }

    if (e->kind == EXPR_EXPR_LIST) {
        findArgument(e->left, nR, file);
        findArgument(e->right, nR, file);
        return;
    }
    expr_codegen(e, file);
    
    if (!(*nR)) {
        (*nR) = malloc(sizeof(*nR));
        (*nR)->Register = e->Register;
        (*nR)->next = NULL;
    }
    else {
        struct nReg *nR1 = malloc(sizeof(*nR1));
        nR1->Register = e->Register;
        nR1->next = NULL;
        struct nReg *nR2 = *nR;
        while (nR2->next!=NULL) {
            nR2 = nR2->next;
        }
        nR2->next = nR1; 
    }
}

