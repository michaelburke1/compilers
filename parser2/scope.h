#ifndef SCOPE_H
#define SCOPE_H

#include "hash_table.h"
#include "symbol.h"

struct scopeTable {
    struct hash_table *table;
    struct scopeTable *next;
    struct scopeTable *prev;

};



void scope_enter();
void scope_exit();
int scope_level();
void scope_bind( const char *name, struct symbol *sym );
struct symbol * scope_lookup( const char *name );
struct symbol * scope_lookup_current( const char *name );
void scopeTableDelete(struct scopeTable *st);

#endif
