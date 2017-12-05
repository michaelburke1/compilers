
#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include <stdio.h>

struct decl {
	char *name;
	struct type *type;
	struct expr *value;
	struct stmt *code;
	struct symbol *symbol;
	struct decl *next;
    int emptyFunc;
};

int incrementErrors(const char *s);
struct decl * decl_create( char *name, struct type *t, struct expr *v, struct stmt *c, struct decl *next, int noInit );
void decl_print( struct decl *d, int indent );
void decl_resolve(struct decl * d);
void decl_typecheck(struct decl *d);
void decl_codegen(struct decl *d, FILE * file);
int incrementErrors(const char * s);
int getErrors(const char * s);
void expr_constant(struct expr *e);
struct hash_table * getInit();
void handleArrayValues(struct expr *e,struct type *t,const char *name);
void incrementParamCount();
void incrementLocalCount();
void incrementFunctionCount();
int getParamCount();
int getLocalCount();
int getFunctionCount();
void resetParamCount();
void resetLocalCount();
void resetFunctionCount();
#endif
