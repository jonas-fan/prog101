# Linked list

A sequence of data elements where each node points to the next (and sometimes previous) using references.

|             | Access | Search | Insert | Delete |
|-------------|--------|--------|--------|--------|
| Linked list | O(n)   | O(n)   | O(1)   | O(1)   |

C implemention (singly linked list):

```c
#include <stdio.h>
#include <string.h>

struct list
{
    int value;
    struct list * next;
};

struct list * list_init(struct list * head, int value)
{
    memset(head, 0, sizeof(struct list));

    head->value = value;

    return head;
}

struct list * list_insert(struct list * head, struct list * node)
{
    node->next = head;

    return node;
}

struct list * list_remove(struct list * head, struct list * node)
{
    struct list dummy = {
        .next = head,
    };

    for (struct list * prev = &dummy; prev->next; prev = prev->next) {
        if (prev->next == node) {
            prev->next = node->next;
            break;
        }
    }

    return dummy.next;
}

struct list * list_reverse(struct list * head)
{
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

int main(void)
{
    struct list * head;
    struct list nodes[4];

    {
        head = list_init(&nodes[0], 0);
        head = list_insert(head, list_init(&nodes[1], 1));
        head = list_insert(head, list_init(&nodes[2], 2));
        head = list_insert(head, list_init(&nodes[3], 3));

        for (struct list * each = head; each; each = each->next) {
            printf("%d%s", each->value, each->next ? " -> " : "\n");
        }
    }

    {
        head = list_reverse(head);

        for (struct list * each = head; each; each = each->next) {
            printf("%d%s", each->value, each->next ? " -> " : "\n");
        }
    }

    {
        head = list_remove(head, head->next);

        for (struct list * each = head; each; each = each->next) {
            printf("%d%s", each->value, each->next ? " -> " : "\n");
        }
    }

    return 0;
}
```
