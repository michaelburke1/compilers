#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"
#include "type.h"
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
    EXPR_NOT,
    EXPR_INCREMENT,
    EXPR_DECREMENT,
    EXPR_FUNCTION,
    EXPR_ARRAY_LITERAL,
    EXPR_NAME,
    EXPR_INTEGER,
    EXPR_CHARACTER,
    EXPR_BOOLEAN,
    EXPR_STRING,
    EXPR_GROUP
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
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );

struct expr * expr_create_name( const char *n );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_character_literal( int c );
struct expr * expr_create_string_literal( const char *str );
struct expr * expr_resolve(struct expr * e);
void expr_print( struct expr *e );

#endif
