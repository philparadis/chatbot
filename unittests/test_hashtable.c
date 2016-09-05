#include <stdio.h>
#include <stdlib.h>

#include "../hashtable.h"

int count_collisions(nlist *val)
{
    nlist *nextval;
    int count_collisions = 0;

    nextval = val;
    while (nextval->next)
    {
        count_collisions++;
        nextval = nextval->next;
    }

    return count_collisions;
}

int test_lookup(hashtable *ht, char *key)
{
    nlist *val;
    printf("Looking up key '%s'...\n", key);
    val = lookup(ht, key);
    if (val == NULL) {
        printf("Key '%s' not found in hashtable.\n", key);
        return NULL;
    }
    printf("Key '%s' FOUND in hashtable with value = '%s'\n", key, val->defn);
    return count_collisions(val);
}

int test_collisions(hashtable *ht, char *key)
{
    nlist *val, *nextval;
    int count_collisions;
    count_collisions = 0;

    printf("Looking up key '%s'...\n", key);
    val = lookup(ht, key);
    if (val == NULL)
        printf("Key '%s' not found in hashtable.\n", key);
    else
    {
        nextval = val;
        do
        {
            count_collisions++;
            printf("Collision %d: Key = '%s', value = '%s'.\n", count_collisions, nextval->name, nextval->defn);
            nextval = nextval->next;
        }
        while (nextval->next);
        printf("Found %d collisions in total for key '%s'!\n", count_collisions, key);
    }
    return count_collisions;
}

int print_nlist(nlist *lst)
{
    nlist *nextlst;
    int count_collisions = 0;

    nextlst = lst;
    if (nextlist == NULL)
        return 0;
    do
    {
        count_collisions++;
        printf("Collision %d: Key = '%s', value = '%s'.\n", count_collisions, nextlst->name, nextlst->defn);
        nextlst = nextlst->next;
    }
    while (nextlst->next);
    return count_collisions;
}

int print_full_hashtable(hashtable *ht)
{
    int j;
    nlist *val;
    int count_collisions = 0;
    int count_table_entry = 0;

    printf("Printing full hash table (reserved size of %d):\n", ht->size);
    for(j=0; j<ht->size; j++)
    {
        if (val) {
            val = ht->data[j];
            printf("data[%4d] = \n    ", j);
            count_collisions += print_nlist(val);
            count_table_entry++;
        } else {
            printf("data[%4d] = NULL\n", j);
        }
    }
    printf("Total of %d entries in table filled (Percent of table filled = %2.2f).\n",
            count_table_entry, (float)count_table_entry)/(float)ht->size;
    printf("Total of %d values.\n", count_collisions);
    printf("Average number of nlist entries per hash table element = %2.2f\n", (float)count_collisions / (float)ht->size);
}

int run_test_general()
{
    hashtable *ht;
    nlist out;

    printf("Creating hash table...\n");
    ht = create_hashtable(25);
    if (ht)
    {
        printf("Success!\n");
    }
    else
    {
        printf("Failure! Not enough memory!\n");
        exit(-1);
    }

    printf("New hash table of size: %d.\n", ht->size);

    printf("Inserting some words, then printing hash table...\n");
    write(ht, "abc", "1000");
    write(ht, "hello", "monkey");
    write(ht, "123", "pizza");
    // Overwrite abc
    write(ht, "abc", "horsey");
    // Overwrite abc
    write(ht, "abc", "Johnny Johnny Yes Papa");
    write(ht, "george", "1");
    write(ht, "the", "2");
    write(ht, "monkey", "3");
    write(ht, "chair", "4");
    write(ht, "piano", "5");
    write(ht, "computer", "6");
    write(ht, "jarry", "7");
    write(ht, "jerry", "8");
    write(ht, "gerry", "9");
    write(ht, "jerry bouletry", "10");
    write(ht, "harry", "1");
    write(ht, "potter", "1");
    write(ht, "megalomaniac", "1");
    write(ht, "hermione", "1");
    write(ht, "ron", "1");
    write(ht, "sleepy", "1");

    test_lookup(ht, "hello");
    test_lookup(ht, "123");
    test_lookup(ht, "abc");

    print_full_hashtable(ht);

    printf("Destroying hash table...\n");
    destroy_hashtable(ht);

    printf("End of testing hash table.");
}


void run_tests_hashtable()
{
    run_test_general();
}
