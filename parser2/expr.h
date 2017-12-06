#ifndef EXPR_H
#define EXPR_H
#include "symbol.h"
#include "type.h"
#include "param_list.h"
#include <stdio.h>
typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MULT,
	EXPR_DIVIDE,
	EXPR_COMMA,
	EXPR_EQUAL,
    EXPR_LBRACK,
    EXPR_RBRACK,
    EXPR_BRACKS,
    EXPR_OR,
    EXPR_AND,
    EXPR_GT,
    EXPR_LT,
    EXPR_EQUIV,
    EXPR_NOT_EQUAL,
    EXPR_GE,
    EXPR_LE,
    EXPR_MOD,
    EXPR_CARAT,
    EXPR_NEG,
    EXPR_NOT,
    EXPR_PRE_INCREMENT,
    EXPR_PRE_DECREMENT,
    EXPR_POST_INCREMENT,
    EXPR_POST_DECREMENT,
    EXPR_FUNCTION,
    EXPR_ARRAY_LITERAL,
    EXPR_NAME,
    EXPR_INTEGER,
    EXPR_CHARACTER,
    EXPR_BOOLEAN,
    EXPR_STRING,
    EXPR_GROUP,
    EXPR_ARRAY_IDENT,
    EXPR_ARRAY_ELEMENT,
    EXPR_EXPR_LIST,
    EXPR_ARRAY_LIST
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by various leaf exprs */
	const char *name;
	struct symbol *symbol;
	int literal_value;
	const char * string_literal;
    int Register;
};

struct reg {
    char * name;
    int r;
    int used;
};

struct nReg {
    int Register;
    struct nReg * next;
};

struct param_list;

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );

struct expr * expr_create_name( const char *n );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_character_literal(const char *c);
struct expr * expr_create_string_literal( const char *str );
void expr_resolve(struct expr * e);
struct type * expr_typecheck(struct expr * e);
void expr_codegen(struct expr *e, FILE * file);
void expr_print( struct expr *e );
void checkParams(struct expr *e, struct param_list *p, const char *name);
//void initRegisters();
int scratch_alloc();
void scratch_free(int r);
const char * scratch_name(int r);
int label_create();
const char * label_name(int label);
void findArgument(struct expr *e, struct nReg **nR, FILE * file);
#endif
