# Problem

## Statement
Given the `root` of a binary tree, return the pre/in/post- and level-order (i.e., from left to right, level by level) traversal of its nodes' values.

### Examples
Example 1: \
Input: \
root = [1, null, 2, 3] \
Output: \
in-order: [1, 3, 2] \

Example 2: \
Input: \
root = [] \
Output: \
[] \

Example 3: \
Input: \
root = [1] \
Output: \
[1] \

Example 4-7: \
Input: \
root = [1, 5, 2, 6, null, 3, 4] \
Output: \
pre-order: [1, 5, 6, 2, 3, 4] \
in-order: [6, 5, 1, 3, 2, 4] \
post-order: [6, 5, 3, 4, 2, 1] \
level-order: [[1], [5, 2], [6, 3, 4]] \

Example 8: \
Input: \
root = [0, 2, 4, 1, null, 3, -1, 5, 1, null, 6, null, 8] \
Output: \
level-order: [[0], [2, 4], [1, 3, -1], [5, 1, 6, 8]] \


### Constraints
- `0 <= capacity <= 2000`
- `-1000 <= value <= 1000`

# Solution

## Approach
__Implement DFS (aka recursion) for Pre/In/Post-Order Traversal__:
if the passed node is not None/nullptr:
- pre-order: visit current -> left -> right nodes 
- in-order: visit left -> current -> right nodes
- post-order: visit left -> right -> current nodes

__Implement BFS (aka queue) for Level-Order Traversal__:
- if the root-list is empty, return None/nullptr
- otherwise, push the first node into queue
- while the queue not empty: 
  - get the current level size (number of nodes added in the previous iteration):
    - go through all nodes within the above range:
      - add the node to a current level list of nodes
      - push left/right child nodes of the current node if they are not None/nullptr
  - add the current level list of nodes to the final list

__Implement Helper to Create a Tree Structure from the Given Root(list)__:
- if the root-list is empty, return None/nullptr
- otherwise, push the first node into queue
- while the queue not empty and the end of the root-list isn't reached: 
  - keep visiting nodes in the queue:
    - initialize of left/right child nodes with non-None values from the root-list
    - push the new nodes to the queue

### Complexity
- __Time__: `O(n)`  since each node is processed exactly once.
- __Memory__: `O(n)` (pre/in/post-order) for the recursion call stack with the worst case for a skewed tree; (level-order) because the queue could hold up to n/2 nodes at the last level in the worst case (complete tree).

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_InOrder1 | 1.17e-05 s |
| test2_InOrder2 | 1.57e-06 s |
| test3_InOrder3 | 2.43e-06 s |
| test4_InOrder4 | 4.34e-06 s |
| test5_PreOrder1 | 4.28e-06 s |
| test6_PostOrder1 | 4.43e-06 s |
| test7_LevelOrder1 | 1.02e-05 s |
| test8_LevelOrder2 | 1.04e-05 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_InOrder1 | 3.03e-05 s |
| test2_InOrder2 | 9.78e-06 s |
| test3_InOrder3 | 9.06e-06 s |
| test4_InOrder4 | 1.29e-05 s |
| test5_PreOrder1 | 1.22e-05 s |
| test6_PostOrder1 | 1.10e-05 s |
| test7_LevelOrder1 | 1.29e-05 s |
| test8_LevelOrder2 | 1.53e-05 s |

