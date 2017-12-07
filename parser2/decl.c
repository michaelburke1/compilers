#include "decl.h"
#include "stmt.h"
#include "scope.h"
#include "expr.h"
#include "param_list.h"
#include "type.h"
#include "hash_table.h"
#include "stmt.h"
#include "symbol.h"
#include <string.h>
#include <stdlib.h>

int resolveErrors = 0;
int checkErrors = 0;
struct hash_table * initTable = NULL;
int const_expr = 0;
int paramCount = 0;
int localCount = 0;
int functionCount = 0; 


int incrementErrors(const char * s) {

    if (strcmp(s, "r") == 0) {
        return resolveErrors++;
    } else if (strcmp(s, "t") == 0) {
        return checkErrors++;
    }

    return -1;
}

int getErrors(const char * s) {

    if (strcmp(s, "r") == 0) {
        return resolveErrors;
    } else if (strcmp(s, "t") == 0) {
        return checkErrors;
    }

    return -1;
}

struct decl * decl_create( char *name, struct type *t, struct expr *v, struct stmt *code, struct decl *n, int empty)
{
    struct decl *d;
    d = (struct decl*)malloc(sizeof(*d));
    d->name = name;
    d->type = t;
    d->value = v;
    d->code = code;
    d->next = n;
    d->emptyFunc = empty;
    return d;
}

void decl_print( struct decl *d, int indent )
{
    if (!d) {return;}
    int i;

    for (i = indent; i > 0; --i) printf("\t");

    printf("%s: ", d->name);
    type_print(d->type);

    if (d->code) {
        printf(" = \n{\n");
        stmt_print(d->code, indent + 1);
        printf("\n}\n");//was }\n
    } else if (d->value) {
        printf(" = ");
        expr_print(d->value);
        printf(";\n");
    } else if (d->emptyFunc) {
        printf(" = { }\n");
    } else {
        printf(";\n");
    }
    decl_print(d->next, indent);
}

void decl_resolve( struct decl *d )
{
    if(!d) return;
    
    if (scope_lookup_current(d->name) != NULL && d->type->kind != TYPE_FUNCTION) {
        printf("DECL RESOLVE ERROR: %s is already declared\n", d->name);
        incrementErrors("r");
    }
    
    symbol_t kind;
    
    if (scope_level() > 1) {
        kind = SYMBOL_LOCAL;
        incrementParamCount(); incrementLocalCount();
    } else {
        kind = SYMBOL_GLOBAL;
    }

    struct symbol * newS = symbol_create(kind, d->type, d->name, 0, 0);
    d->symbol = newS;
    scope_bind(d->name, newS);

    expr_resolve(d->value);

    if(d->type->kind == TYPE_FUNCTION) {
        param_list_resolve(d->type->params);
        if(!initTable) initTable = hash_table_create(0,0);
        hash_table_insert(initTable, d->name, d->type);
    }

    if(d->code) {
        scope_enter();
        stmt_resolve(d->code);
        d->symbol->localCount = getLocalCount();

        scope_exit();
    }
    decl_resolve(d->next);
}

void decl_typecheck(struct decl *d) {

    if (!d) {
        return;
    }

    if (d->value) {
        if (d->type->kind != TYPE_ARRAY) {
            struct type* t;
            t = expr_typecheck(d->value);
            if(d->type->kind != t->kind){
                printf("Cannot assign ");
                expr_print(d->value);
                printf(" to ");
                type_print(d->type);
                printf("\n");
                incrementErrors("t");
            }
        } else {
            if (d->value->kind != EXPR_ARRAY_LIST) {
                printf("Cannot assign \n");
                expr_print(d->value);
                printf(" to array %s\n",d->name);
                incrementErrors("t");
            } else {
                struct type *currType = d->type;
                int args = 1;
                if (currType->expr) {
                    while (currType->kind == TYPE_ARRAY) {
                        if (currType->expr && currType->expr->kind != EXPR_INTEGER) {
                            printf("Array %s must have a literal value as index\n",d->name);
                            incrementErrors("t");
                            break;
                        } else {
                            args = currType->expr->literal_value;
                        }
                        currType = currType->subtype;
                    }
                } else {
                    args = 1000;
                    while (currType->kind == TYPE_ARRAY) {
                        currType = currType->subtype;
                    }
                }

                handleArrayValues(d->value, currType, d->name);
                if (const_expr > args) {
                    printf("Too many arguments when initializing array %s\n", d->name);
                    incrementErrors("t");
                }
            }
        }
    } 

    if (d->symbol->kind == SYMBOL_GLOBAL) {
        const_expr = 0;
        expr_constant(d->value);
        if (const_expr) {
            incrementErrors("t");
            printf("Tried to assign not constant variable in the declaration of %s\n",d->name);
        }
    }

    if (d->code) {
        stmt_typecheck(d->code, d->type->subtype);
    }

    decl_typecheck(d->next);
}

void decl_codegen(struct decl *d, FILE * file) {
    if (!d) {
        return;
    }

    if (d->symbol->kind == SYMBOL_GLOBAL) {
        fprintf(file, ".data\n");
        if (d->type->kind != TYPE_FUNCTION && !d->value && !d->code) {
            if (d->type->kind != TYPE_STRING) {
                fprintf(file,  "%s: .quad 0\n", d->name);
            } else {
                fprintf(file,  ".global orig%s\norig%s:\n  .string \"\" \n", d->name, d->name);
                fprintf(file, ".global %s\n%s:\n .quad orig%s\n", d->name, d->name, d->name);
            }
        } else if (d->type->kind == TYPE_ARRAY && d->value) {
            fprintf(file, ".global %s\n%s:\n\t .quad ", d->name, d->name);
            int i, j;
            if (d->type->expr->literal_value) {
                i = d->type->expr->literal_value;
            }
            struct expr *e = d->value->right;
            for (j = 0; j < i; ++j) {
                if (!e->left) {
                    if (e) {
                        fprintf(file, "%d", e->literal_value);
                    }
                    break;
                }
                fprintf(file, "%d", e->left->literal_value);
                if (e->right) {
                    fprintf(file, ", ");
                    e = e->right;
                } else {
                    break;
                }
            }

            //expr_codegen(d->value, file);
            fprintf(file, "\n");
        } else {
            if (d->type->kind != TYPE_FUNCTION && d->value) {
                if (d->type->kind == TYPE_STRING) {
                    fprintf(file,  ".data\n.global orig%s\norig%s:\n  .string ""%s""\n", d->name, d->name, d->value->string_literal);
                    fprintf(file, ".global %s\n%s:\n .quad orig%s\n", d->name, d->name, d->name);
                    
                } else {
                    fprintf(file,  ".data\n.global %s\n%s:\n  .quad %d\n", d->name, d->name, d->value->literal_value);
                }
            } else if (d->type->kind == TYPE_FUNCTION) {
                if (d->code) {
                    fprintf(file,  ".text\n.global %s\n%s:\n", d->name, d->name);
                    struct param_list *p = d->type->params;
                    fprintf(file,  "\tPUSHQ %%rbp\n\tMOVQ  %%rsp, %%rbp\n");
                    int pCount = 0;

                    while (p) {
                        p = p->next;
                        pCount++;
                    }
                    if (pCount >= 1) {
                        fprintf(file,  "\tPUSHQ %%rdi\n");
                    }
                    if(pCount >= 2){
                        fprintf(file,  "\tPUSHQ %%rsi\n");
                    }
                    if(pCount >= 3){
                        fprintf(file,  "\tPUSHQ %%rdx\n");
                    }
                    if(pCount >= 4){
                        fprintf(file,  "\tPUSHQ %%rcx\n");
                    }
                    if(pCount >= 5){
                        fprintf(file,  "\tPUSHQ %%r8\n");
                    }
                    if(pCount == 6){
                        fprintf(file,  "\tPUSHQ %%r9\n");
                    }
                    if(d->symbol->localCount > 0){        
                        fprintf(file,  "\tsubq $%d,%%rsp\n", d->symbol->localCount*8);
                    }
                    fprintf(file,  "\tPUSHQ %%rbx\n");
                    fprintf(file,  "\tPUSHQ %%r12\n");
                    fprintf(file,  "\tPUSHQ %%r13\n");
                    fprintf(file,  "\tPUSHQ %%r14\n");
                    fprintf(file,  "\tPUSHQ %%r15\n\n");      
                    stmt_codegen(d->code, file);
                    fprintf(file,  "FUNCTION%d:\n", getFunctionCount());
                    fprintf(file,  "\n");
                    fprintf(file,  "\tPOPQ %%r15\n");
                    fprintf(file,  "\tPOPQ %%r14\n");
                    fprintf(file,  "\tPOPQ %%r13\n");
                    fprintf(file,  "\tPOPQ %%r12\n");
                    fprintf(file,  "\tPOPQ %%rbx\n");
                    fprintf(file,  "\tMOVQ %%rbp,%%rsp\n");
                    fprintf(file,  "\tPOPQ %%rbp\n");
                    fprintf(file,  "\tret\n");
                    incrementFunctionCount();
                }
            }
        }
    } else if (d->symbol->kind == SYMBOL_LOCAL && d->value) {
        expr_codegen(d->value, file);
        fprintf(file,  "\tMOVQ %s,-%d(%%rbp)\n",
            scratch_name(d->value->Register),
            d->symbol->paramCount * 8);
        scratch_free(d->value->Register);
    }

    decl_codegen(d->next, file);
}

void handleArrayValues(struct expr *e,struct type *t,const char *name)
{

    if(!e) {
        return;
    }

    if (e->kind == EXPR_EXPR_LIST || e->kind == EXPR_ARRAY_LIST) { 
        handleArrayValues(e->left, t, name); 
        handleArrayValues(e->right, t, name);
    }
    else {
        const_expr++;   
        struct type *aux2 = expr_typecheck(e);
        if(aux2->kind != t->kind) {
            incrementErrors("t");
            printf("Passing wrong argument to array %s: incorrect expression list ", name);
            type_print(aux2);
            printf(" ");
            expr_print(e);
            printf("\n");
        }
    
    }
}

void expr_constant(struct expr *e)
{
    if (!e || const_expr > 0)return;
    expr_constant(e->left);
    expr_constant(e->right);
    if (e->kind == EXPR_NAME)const_expr++;
}

struct hash_table * getInit() {
    return initTable;
}

void incrementParamCount() {
    paramCount++;
}
void incrementLocalCount() {
    localCount++;
}
void incrementFunctionCount() {
    functionCount++;
}
int getParamCount() {
    return paramCount;
}
int getLocalCount() {
    return localCount;
}

int getFunctionCount() {
    return functionCount;
}

void resetParamCount() {
    paramCount = 0;
}

void resetLocalCount() {
    localCount = 0;
}

void resetFunctionCount() {
    functionCount = 0;
}
