#ifndef SYMBOL_H
#define SYMBOL_H

#include "type.h"
#include <stdio.h>

typedef enum {
	SYMBOL_LOCAL,
	SYMBOL_PARAM,
	SYMBOL_GLOBAL
} symbol_t;

struct symbol {
	symbol_t kind;
	int which;
	struct type *type;
	char *name;
    struct type *subtype;
    int paramCount;
    int localCount;
};

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name, int w, struct type * subtype);
void symbol_print(struct symbol *s); 
const char * symbol_codegen(struct symbol *s, FILE * file);
#endif
