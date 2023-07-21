#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct {
    char* key;
    float value;
} entry_t;

typedef struct {
    entry_t* entries;
    unsigned int size;
} ht_t;

ht_t* ht_create(unsigned int size);
void ht_set(ht_t* hashtable, const char* key, float value);
float ht_get(ht_t* hashtable, const char* key);
void ht_print(ht_t* hashtable);

#endif /* HASHTABLE_H */
