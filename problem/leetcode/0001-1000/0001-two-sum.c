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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * twoSum(int * nums, int numsSize, int target, int * returnSize) {
    *returnSize = 2;

    int * out = (int *)calloc(*returnSize, sizeof(int));
    int i;
    int j;
    struct htable table;

    htable_init(&table, 1024);

    for (i = 0; i < numsSize; i++) {
        const int rest = target - nums[i];

        if (htable_get(&table, rest, &j)) {
            out[0] = i;
            out[1] = j;
            break;
        }

        htable_set(&table, nums[i], i);
    }

    htable_term(&table);

    return out;
}
