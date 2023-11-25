# Problem

## Statement
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.


### Examples
Example 1: \
Input: \
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"] \
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]] \
Output: \
[null, null, null, 1, null, -1, null, -1, 3, 4] \
Explanation: 
- LRUCache lRUCache = new LRUCache(2);
- lRUCache.put(1, 1); // cache is {1=1}
- lRUCache.put(2, 2); // cache is {1=1, 2=2}
- lRUCache.get(1);    // return 1
- lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
- lRUCache.get(2);    // returns -1 (not found)
- lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
- lRUCache.get(1);    // return -1 (not found)
- lRUCache.get(3);    // return 3
- lRUCache.get(4);    // return 4

Example 2: \
["LRUCache", "put", "put", "put", "get"] \
[[2], [1, 1], [2, 2], [2, 3], [3]] \
Output: \
[null, null, null, null, 3] \
Explanation: 
- LRUCache lRUCache = new LRUCache(2);
- lRUCache.put(1, 1); // cache is {1=1}
- lRUCache.put(2, 2); // cache is {1=1, 2=2}
- lRUCache.put(2, 2); // cache is {1=1, 2=3}
- lRUCache.get(2);    // return 3


### Constraints
- `1 <= capacity <= 3000`
- `0 <= key <= 10^4`
- `0 <= value <= 10^5`

# Solution

## Approach
__Select Data Structures__: 
- Use a hash map for O(1) key access.
- Use a double-linked list to maintain usage order.

__Implement Node Class__:
- Create a Node class with `key`, `value`, `next`, and `prev` attributes.

__Implement LRUCache Class__:
- Initialize with a specific capacity.
- Maintain a hash map and a double-linked list.

__Implement get Method__:
- Retrieve and return value from the hash map.
- Move the node to the head of the list if it exists.

__Implement put Method__:
- If key exists, update value and move node to head (if it's not already there).
- If key doesn't exist, create and insert a new node at head.
- If at capacity, remove the tail node and its key from the hash map.

### Complexity
- __Time__: `O(1)` [get(key), put(key, value)] - hash map provides O(1) access to any node in the double-linked list, and moving nodes to the head or removing the tail node in a double-linked list also takes O(1) time
- __Memory__: `O(capacity)` - cache stores each key-value pair as a node in the double-linked list and an entry in the hash map.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Cache1 | 3.01e-05 s |
| test2_Cache2 | 6.30e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Cache1 | 7.01e-05 s |
| test2_Cache2 | 2.41e-05 s |

