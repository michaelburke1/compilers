#include "decl.h"
#include "stmt.h"
#include "scope.h"
#include <stdlib.h>

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
    
    symbol_t kind = scope_level() > 1 ?
        SYMBOL_LOCAL : SYMBOL_GLOBAL;
    
    d->symbol = symbol_create(kind,d->type,d->name);
    
    scope_bind(d->name,d->symbol);
    
    if(d->value) {
        expr_resolve(d->value);
    }
    
    if(d->code) {
        scope_enter();
        param_list_resolve(d->type->params);
        stmt_resolve(d->code);
        scope_exit();
    }
    
    decl_resolve(d->next);
}
