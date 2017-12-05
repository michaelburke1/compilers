#include "symbol.h"
#include <stdlib.h>
#include <string.h>

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

const char * symbol_codegen(struct symbol *s, FILE * file) {
	
	char instruction[100];
	char * rValue = malloc(256);
	int vars[30];

	if (s->kind == SYMBOL_GLOBAL) {
		return s->name;
	}

	int bytes = s->localCount * 8;

	if (bytes) {
		int tmp = bytes, curr = 0;
		while (tmp > 0) {
			vars[curr] = tmp % 10;
			++curr;
			tmp /= 10;
		}
		curr--;
		int i, j = 1;

		for (i = curr; i >= 0; --i) {
			instruction[j] = '0' + vars[i];
			++j;
		}

		instruction[j++] = '(';
		instruction[j++] = '%';
		instruction[j++] = 'r';
		instruction[j++] = 'b';
		instruction[j++] = 'p';
		instruction[j++] = ')';
		instruction[j] = '\0';
		strcpy(rValue, instruction);
		return rValue;
	}
	return "";
}