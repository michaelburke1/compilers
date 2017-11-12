#include "decl.h"
#include "stmt.h"
#include "scope.h"
#include "expr.h"
#include "param_list.h"
#include <string.h>
#include <stdlib.h>

int currLocalVars = 0;
int resolveErrors = 0;
int checkErrors = 0;

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
    
    symbol_t kind = scope_level() > 1 ?
        SYMBOL_LOCAL : SYMBOL_GLOBAL;
    
    if (scope_level() == 1) {
        struct symbol * newS = symbol_create(kind, d->type, d->name);
        d->symbol = newS;
        scope_bind(d->name, newS);
    }
    if (scope_level() > 1) {
        currLocalVars++; 
        struct symbol * newS = symbol_create(kind, d->type, d->name);
        d->symbol = newS;
        scope_bind(d->name, newS);
    }
 
    if(d->code) {
        scope_enter();
        if (d->type->params) {
            //sym->params = d->type->params;
            param_list_resolve(d->type->params);
        }
        stmt_resolve(d->code);
        scope_exit();
    } else if (d->value) {
        expr_resolve(d->value);
    }

    if ((!d->code) && d->type->params ) {
		scope_enter();
		//sym->params = d->type->params;
		param_list_resolve(d->type->params);
		scope_exit();
	}

    decl_resolve(d->next);
}
