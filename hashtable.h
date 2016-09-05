#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};
typedef struct nlist nlist;

struct hashtable {
    int size;
    nlist** data;
};
typedef struct hashtable hashtable;


hashtable *create_hashtable(int expected_size);
void destroy_hashtable(hashtable *ht);
hashtable *regrow_hashtable(hashtable *ht, int new_hash_size);

nlist *lookup(hashtable *ht, char *s);
nlist *write(hashtable *ht, char *name, char *defn);

// Unit tests
void run_tests_hashtable();

#endif // HASHTABLE_H_INCLUDED
