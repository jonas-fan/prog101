# Hash table

A collection of data elements where each element is mapped to and associated with a unique key.

|            | Access | Search | Insert | Delete |
|------------|--------|--------|--------|--------|
| Hash table | -      | O(1)   | O(1)   | O(1)   |

> [!NOTE]
>
> A good hash function keeps average case `O(1)`. Worst case `O(n)` occurs when all keys are hashed into the same bucket.
>
> Collision resolution approaches:
>
> - Chaining: An approach where multiple keys hashed into the same bucket are stored as a linked list.
> - Open addressing: An approach where the algorithm searches for the next free bucket when a collision occurs.
>
> To avoid performance degradation (from `O(1)` to `O(n)`), some implementations convert a linked list into a balanced tree when the number of elements in a bucket exceeds a threshold.

## Implementations

C implementation of hash table (chaining for collision resolution):

```c
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct htable_entry {
    int key;
    int value;
    struct htable_entry * next;
};

struct htable {
    unsigned int size;
    struct htable_entry ** buckets;
};

static unsigned int roundup_power_2(unsigned int value) {
    unsigned int out = 1;

    if (value > 0)
        value--;

    while (value) {
        value >>= 1;
        out <<= 1;
    }

    return out;
}

static unsigned int htable_hash(const struct htable * table, int key) {
    return (unsigned int)key & (table->size - 1);
}

struct htable * htable_init(struct htable * table, unsigned int buckets) {
    memset(table, 0, sizeof(*table));

    table->size = roundup_power_2(buckets);
    table->buckets = calloc(table->size, sizeof(struct htable_entry *));

    return table->buckets ? table : NULL;
}

void htable_term(struct htable * table) {
    for (unsigned int index = 0; index < table->size; index++) {
        struct htable_entry ** indirect = &(table->buckets[index]);

        while (*indirect) {
            struct htable_entry * entry = *indirect;
            *indirect = (*indirect)->next;
            free(entry);
        }
    }

    free(table->buckets);

    table->size = 0;
    table->buckets = NULL;
}

bool htable_get(const struct htable * table, int key, int * out) {
    const unsigned int index = htable_hash(table, key);
    const struct htable_entry * entry = table->buckets[index];

    while (entry) {
        if (entry->key == key) {
            *out = entry->value;
            return true;
        }

        entry = entry->next;
    }

    return false;
}

bool htable_set(struct htable * table, int key, int value) {
    const unsigned int index = htable_hash(table, key);
    struct htable_entry ** indirect = &table->buckets[index];

    while (*indirect) {
        if ((*indirect)->key == key)
            break;

        indirect = &(*indirect)->next;
    }

    if (!*indirect) {
        if (!(*indirect = calloc(1, sizeof(struct htable_entry)))) {
            return false;
        }
    }

    (*indirect)->key = key;
    (*indirect)->value = value;

    return true;
}

bool htable_delete(struct htable * table, int key) {
    const unsigned int index = htable_hash(table, key);
    struct htable_entry ** indirect = &table->buckets[index];

    while (*indirect) {
        if ((*indirect)->key == key)
            break;

        indirect = &(*indirect)->next;
    }

    if (!*indirect) {
        return false;
    }

    struct htable_entry * entry = *indirect;
    *indirect = (*indirect)->next;
    free(entry);

    return true;
}
```

Examples:

```c
#include <stdio.h>
#include "htable.h"

static void lookup(const struct htable * table, int key) {
    int value;

    if (htable_get(table, key, &value)) {
        printf("key %d: value %d\n", key, value);
    } else {
        printf("key %d not found\n", key);
    }
}

int main(void) {
    struct htable table;

    htable_init(&table, 1000);
    htable_set(&table, 1234, 5678);
    htable_set(&table, 9527, 666666);

    lookup(&table, 1234);  // key 1234: value 5678
    lookup(&table, 5678);  // key 5678 not found
    lookup(&table, 9527);  // key 9527: value 666666

    htable_term(&table);

    return 0;
}
```
