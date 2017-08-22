/* LRU Cache: Design and build a "least recently used" cache, which evicts the least recently used item.
The cache should map from keys to values (allowing you to insert and retrieve a value associated
with a particular key) and be initialized with a max size. When it is full, it should evict the least
recently used item. You can assume the keys are integers and the values are strings.


SOLUTION

We should start off by defining the scope of the problem. What exactly do we need to achieve?

Inserting Key, Value Pair: We need to be able to insert a (key, value) pair

Retrieving Value by Key: We need to be able to retrieve the value using the key.

Finding Least Recently Used: We need to know the least recently used item (and, likely, the usage
ordering of all items).

Updating Most Recently Used: When we retrieve a value by key, we need to update the order to be the
most recently used item.

Eviction: The cache should have a max capacity and should remove the least recently used item when
it hits capacity.

The (key, value) mapping suggests a hash table. This would make it easy to look up the value associated
with a particular key.

Unfortunately, a hash table usually would not offer a quick way to remove the most recently used item. We
could mark each item with a timestamp and iterate through the hash table to remove the item with the
lowest timestamp, but that can get quite slow (O(N) for insertions).

Instead, we could use a linked list, ordered by the most recently used. This would make it easy to mark an
item as the most recently used (just put it in the front of the list) or to remove the least recently used item
(remove the end).

Unfortunately, this does not offer a quick way to look up an item by its key. We could iterate through the
linked list and find the item by key. But this could get very slow (O(N) for retrieval).

Each approach does half of the problem (different halves) very well, but neither approach does both parts
well.

Can we get the best parts of each? Yes. By using both!

The linked list looks as it did in the earlier example, but now it's a doubly linked list. This allows us to easily
remove an element from the middle of the linked list. The hash table now maps to each linked list node
rather than the value.

The algorithms now operate as follows:

Inserting Key, Value Pair: Create a linked list node with key, value. Insert into head of linked list. 
Insert key (same as of key value pair)-> node mapping into hash table.

Retrieving Value by Key: Look up node in hash table and return value. Update most recently used item

Finding Least Recently Used: Least recently used item will be found at the end of the linked list.
updated.

Updating Most Recently Used: Move node to front of linked list. Hash table does not need to be

Eviction: Remove tail of linked list. Get key from linked list node and remove key from hash table.

*/