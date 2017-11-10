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

struct param_list * param_list_resolve(struct param_list *pl) {

    struct param_list * curr = pl;

    while (curr) {
        if (scope_lookup(curr->name)) {
            printf("params list resolve error: %s is already declared\n", curr->name);
            incrementErrors("r");
            // exit(1);
        }
        struct symbol *s = symbol_create(SYMBOL_PARAM, curr->type, curr->name);
		scope_bind(curr->name, s);
        curr = curr->next;
    }

    return curr;
}
