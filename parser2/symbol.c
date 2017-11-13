#include "symbol.h"
#include <stdlib.h>

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name, int w, struct type *subtype) {
    struct symbol *s = malloc(sizeof(*s));
    s->kind = kind;
    s->which = w;
    s->subtype = subtype;
    s->type = type;
    s->name = name;

    return s;
}

void symbol_print(struct symbol *s) {
	switch(s->kind) {
		case SYMBOL_LOCAL:
			printf("local %d", s->which);
			break;
		case SYMBOL_GLOBAL:
			printf("global %s", s->name);
			break;
		case SYMBOL_PARAM:
			printf("param %d", s->which);
            break;
	}
}
