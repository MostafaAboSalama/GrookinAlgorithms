#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"

unsigned int hash(const char* key, unsigned int size) {
    unsigned int hashval = 0;
    for (int i = 0; i < strlen(key); i++) {
        hashval += key[i];
    }
    return hashval % size;
}

ht_t* ht_create(unsigned int size) {
    ht_t* hashtable = malloc(sizeof(ht_t));
    hashtable->size = size;
    hashtable->entries = malloc(size * sizeof(entry_t));
    for (int i = 0; i < size; i++) {
        hashtable->entries[i].key = NULL;
        hashtable->entries[i].value = 0;
    }
    return hashtable;
}

void ht_set(ht_t* hashtable, const char* key, float value) {
    unsigned int slot = hash(key, hashtable->size);
    entry_t* entry = &hashtable->entries[slot];
    while (entry->key != NULL) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return;
        }
        entry++;
    }
    entry->key = strdup(key);
    entry->value = value;
}

float ht_get(ht_t* hashtable, const char* key) {
    unsigned int slot = hash(key, hashtable->size);
    entry_t* entry = &hashtable->entries[slot];
    while (entry->key != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry++;
    }
    return 0;
}

void ht_print(ht_t* hashtable) {
    printf("{");
    for (int i = 0; i < hashtable->size; i++) {
        if (hashtable->entries[i].key != NULL) {
            printf("'%s': %f", hashtable->entries[i].key, hashtable->entries[i].value);
            if (i < hashtable->size - 1) {
                printf(", ");
            }
        }
    }
    printf("}\n");
}
