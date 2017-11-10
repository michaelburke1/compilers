#include<stdio.h>
#include<stdlib.h>
#include "hash_table.h"
#include "scope.h"

#include <stdio.h>
#include <stdlib.h>


struct scopeTable *head = NULL;
struct scopeTable *tail = NULL;

int scopeParamCount = 0;
int scopeLocalCount = 0;

int scope_level() {

    int level = 1;
    struct scopeTable *curr = tail;
    
    while (curr->prev) {
        level++;
        curr = curr->prev;
    }

    return level;
}

struct symbol * scope_lookup_current(const char *name) {

    if (!tail) {
        printf("no tail table\n");
        return NULL;
    }

    if (!hash_table_lookup(tail->table, name)) {
        return NULL;
    }

    return hash_table_lookup(tail->table, name);

}

struct symbol * scope_lookup(const char * name) {
    if (!tail) {
        printf("no tail table\n");
        return NULL;
    }

    struct scopeTable *curr = tail;
    struct symbol *result;

    while (curr) {
        result = (struct symbol *)hash_table_lookup(curr->table, name);
        if (result) {
            return result;
        }
        curr = curr->prev;
    }

    return NULL;
}

void scope_bind(const char * name, struct symbol *s) {

    hash_table_insert(tail->table, name, s);

    if (s->kind == SYMBOL_LOCAL) {
		s->which = scopeLocalCount;
		scopeLocalCount++;
	} else if (s->kind == SYMBOL_PARAM) {
		s->which = scopeParamCount;
		scopeParamCount++;
	}

}

void scope_enter() {

    struct scopeTable *st = malloc(sizeof(*st));
    st->table = hash_table_create(0,0);

    if (!head) {
        head = st;
        tail = st;
    } else {
        tail->next = st;
        st->prev = tail;
        tail = tail->next;
    }
}

void scope_exit() {
    if (!head) return; 

    if (head == tail) {
        scopeTableDelete(head);
        scopeTableDelete(tail);
    } else {
        struct scopeTable *st = tail->prev;
        scopeTableDelete(tail);
        tail = st;
    }

    if (head == tail) {
        scopeLocalCount = 0;
        scopeParamCount = 0;
    }
}

void scopeTableDelete(struct scopeTable * st) {
    hash_table_clear(st->table);
    hash_table_delete(st->table);
    free(st);
} 







