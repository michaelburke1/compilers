

#include "decl.h"
#include "stmt.h"
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
