# Problem

## Statement
You are given two __non-empty__ linked lists representing two non-negative integers. The digits are stored in __reverse order__, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


### Examples
Example 1: \
Input: l1 = [2,4,3], l2 = [5,6,4] \
Output: [7,0,8] \
Explanation: 342 + 465 = 807.

Example 2: \
Input: l1 = [0], l2 = [0] \
Output: [0]

Example 3: \
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9] \
Output: [8,9,9,9,0,0,0,1]


### Constraints
- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.


# Solution

## Approach
__Iterate through both lists__: Add corresponding digits along with any carry from the previous addition.
__Handle carry__: Update the carry for the next iteration (sum divided by 10).
__Create new nodes__: For each sum, create a new node in the result list with the sum modulo 10.
__Continue until lists are exhausted__: If one list ends, treat its values as 0.
__Add carry if needed__: After processing both lists, if there's a remaining carry, add a new node for it.


### Complexity
- __Time__: `O(max(n, m))`, where n and m are the lengths of the two lists.
- __Memory__: `O(max(n, m))`, for the new list created to store the result.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_807 | 6.47e-06 s |
| test2_0 | 1.41e-06 s |
| test3_10009998 | 3.64e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_807 | 3.17e-05 s |
| test2_0 | 1.41e-05 s |
| test3_10009998 | 2.31e-05 s |

