#include "param_list.h"
#include "expr.h"
#include "decl.h"
#include "scope.h"
#include <stdlib.h>


struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ) {

    struct param_list *p = malloc(sizeof(*p));
    p->name = name;
    p->type = type;
    p->next = next;

    return p;
}

void param_list_print(struct param_list *p) {

    if (!p) return;

    printf("%s: ", p->name);
    type_print(p->type);
    if (p->next) {
        printf(", ");
        param_list_print(p->next);
    }
}

void param_list_resolve(struct param_list *pl) {
    
    if (!pl) return;
    
    struct symbol *s = symbol_create(SYMBOL_PARAM, pl->type, pl->name, 0, 0);
    scope_bind(pl->name, s);
    param_list_resolve(pl->next);
}
