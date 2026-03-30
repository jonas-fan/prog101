# Linked list

A sequence of data elements where each node points to the next (and sometimes previous) using references.

|             | Access | Search | Insert | Delete |
|-------------|--------|--------|--------|--------|
| Linked list | O(n)   | O(n)   | O(1)   | O(1)   |

## Doubly linked list

C implementation of doubly linked list:

```c
#include <string.h>
#include <stdbool.h>

struct list {
    int value;
    struct list * prev;
    struct list * next;
};

struct list * list_init(struct list * head) {
    memset(head, 0, sizeof(struct list));

    head->prev = head;
    head->next = head;

    return head;
}

struct list * list_with_value(struct list * head, int value) {
    head = list_init(head);
    head->value = value;

    return head;
}

bool list_empty(const struct list * head) {
    return head->next == head;
}

void list_insert(struct list * head, struct list * node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
}

void list_insert_before(struct list * head, struct list * node) {
    node->prev = head->prev;
    node->next = head;
    head->prev->next = node;
    head->prev = node;
}

void list_remove(struct list * node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = node;
    node->next = node;
}

void list_reverse(struct list * head) {
    struct list * curr = head;
    struct list * next = NULL;

    do {
        next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;
    } while (curr != head);
}

#define list_for_each(head, entry) \
    for ((entry) = (head)->next; \
         (entry) != (head); \
         (entry) = (entry)->next)
```

Examples:

```c
#include <stdio.h>
#include "list.h"

void list_dump(const struct list * head) {
    if (list_empty(head)) {
        printf("(empty)\n");
        return;
    }

    const struct list * entry;

    list_for_each(head, entry) {
        printf("%d%s",
            entry->value,
            entry->next == head ? "\n" : " -> "
            );
    }
}

int main(void) {
    struct list head;
    struct list nodes[4];

    list_init(&head);
    list_dump(&head);  // (empty)

    list_insert(&head, list_with_value(&nodes[0], 0));
    list_insert(&head, list_with_value(&nodes[1], 1));
    list_insert(&head, list_with_value(&nodes[2], 2));
    list_insert(&head, list_with_value(&nodes[3], 3));
    list_dump(&head);  // 3 -> 2 -> 1 -> 0

    list_reverse(&head);
    list_dump(&head);  // 0 -> 1 -> 2 -> 3

    list_remove(&nodes[2]);
    list_dump(&head);  // 0 -> 1 -> 3

    return 0;
}
```

## Singly linked list

C implemention of singly linked list:

```c
#include <string.h>

struct list {
    int value;
    struct list * next;
};

struct list * list_init(struct list * head, int value) {
    memset(head, 0, sizeof(struct list));

    head->value = value;

    return head;
}

struct list * list_insert(struct list * head, struct list * node) {
    node->next = head;

    return node;
}

struct list * list_remove(struct list * head, struct list * node) {
    struct list dummy = {
        .next = head,
    };

    for (struct list * prev = &dummy; prev->next; prev = prev->next) {
        if (prev->next == node) {
            prev->next = node->next;
            node->next = NULL;
            break;
        }
    }

    return dummy.next;
}

struct list * list_reverse(struct list * head) {
    struct list * prev = NULL;
    struct list * next = NULL;

    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

#define list_for_each(head, entry) \
    for ((entry) = (head); \
         (entry); \
         (entry) = (entry)->next)
```

Examples:

```c
#include <stdio.h>
#include "list.h"

void list_dump(const struct list * head) {
    if (!head) {
        printf("(empty)\n");
        return;
    }

    const struct list * entry;

    list_for_each(head, entry) {
        printf("%d%s",
            entry->value,
            entry->next ? " -> " : "\n"
            );
    }
}

int main(void) {
    struct list * head;
    struct list nodes[4];

    head = NULL;
    list_dump(head);  // (empty)

    head = list_init(&nodes[0], 0);
    head = list_insert(head, list_init(&nodes[1], 1));
    head = list_insert(head, list_init(&nodes[2], 2));
    head = list_insert(head, list_init(&nodes[3], 3));
    list_dump(head);  // 3 -> 2 -> 1 -> 0

    head = list_reverse(head);
    list_dump(head);  // 0 -> 1 -> 2 -> 3

    head = list_remove(head, &nodes[2]);
    list_dump(head);  // 0 -> 1 -> 3

    return 0;
}
```
