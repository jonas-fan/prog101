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
