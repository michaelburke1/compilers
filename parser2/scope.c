#include<stdio.h>
#include<stdlib.h>


struct hash_list *tail = NULL;

int scope_level() {

    int level = 1;
    struct *hash_list curr = tail;
    
    while (curr->parent) {
        level++;
        curr = curr->before;
    }

    return level;
}

struct symbol usedInScope(const char * name) {
    if (!tail) {
        return NULL;
    }

    if (!hashTableLookup(tail->table, name)) {
        return NULL;
    }

    return hashTableLookup(tail->table, name);

}
