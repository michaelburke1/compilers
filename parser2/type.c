#include "type.h"
#include <stdlib.h>

struct type * type_create( type_kind_t kind, struct expr *expr, struct param_list *params, struct type *subtype ) {

    struct type *t = malloc(sizeof(*t));
    t->kind = kind;
    t->expr = expr;
    t->params = params;
    t->subtype = subtype;

    return t;
}

void type_print(struct type * t) {

    if (!t) return;

    switch(t->kind) {
        case TYPE_BOOLEAN:
            printf("boolean");
            break;
        case TYPE_CHARACTER:
            printf("char");
            break;
        case TYPE_INTEGER:
            printf("integer");
            break;
        case TYPE_STRING:
            printf("string");
            break;
        case TYPE_ARRAY:
            printf("array [");
            expr_print(t->expr);
            printf("] ");
            type_print(t->subtype);
            break;
        case TYPE_FUNCTION:
            printf("function ");
            type_print(t->subtype);
            printf(" (");
            param_list_print(t->params);
            printf(")");
            break;
        case TYPE_VOID:
            printf("void");
            break;
    }

}

struct type * type_copy(struct type *t) {
    struct type *tmp = type_create(t->kind, t->expr, t->params, t->subtype);
    return tmp;
}

int type_equals(struct type *a, struct type *b) {

    if (!a || !b) { 
        return 0;
    }

	struct param_list *p1;
	struct param_list *p2;
	
    if (a->kind == TYPE_FUNCTION && b->kind == TYPE_FUNCTION) {
		if (b->subtype != b->subtype) {
			return 0;
        }

		p1 = a->params;
		p2 = b->params;
		while (p1 && p2) {
			if (p1->type->kind != p2->type->kind) {
				return 0;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		if (p1 || p2) {
			return 0;
		}
		return 1;
	}
	if (a->kind == b->kind) {
        return 1;
    } else {
        return 0;
    }
}

void type_delet(struct type *t) {
    printf("delete\n");

}





