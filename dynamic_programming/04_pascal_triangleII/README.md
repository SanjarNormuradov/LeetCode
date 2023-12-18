# Problem

## Statement
Given an integer `rowIndex`, return the `rowIndex^th` (0-indexed) row  of __Pascal's triangle__.

In __Pascal's triangle__, each number is the sum of the two numbers directly above

### Examples
Example 1: \
Input: numRows = 4 \
Output: [1,4,6,4,1]

Example 2: \
Input: numRows = 0 \
Output: [[1]]

Example 3: \
Input: numRows = 6 \
Output: [1,6,15,20,15,6,1]


### Constraints
- `1 <= n <= 30`


# Solution

## Approach
- __Create container__: Use the same container for each row as it stores numbers from the previous row above. Initialize the answer with a container of 1 as `rowIndex >= 0`
- __Handle edge cases__: If `rowIndex > 0`, append 1. All the rest will be filled in the main loop. 
- __Compute each element__: If `rowIndex > 1`, iterate over each element and update with the sum of itself (which is equal to the element value in the row above) and the element value on the left in the current row.
- __Append common last element__: Once every element in the current row is updated, append 1.

### Complexity
- __Time__: `O(n^2)`, the sum of each row of size equal to its row number. Total sum is `1+2+..+n` which is `n(n+1)/2 ~ n^2`
- __Memory__: `O(n)`, space for row `dp` of `O(n)`.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_n4 | 6.93e-06 s |
| test2_n0 | 2.02e-06 s |
| test3_n6 | 3.13e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_n4 | 2.41e-05 s |
| test2_n0 | 1.14e-05 s |
| test3_n6 | 1.29e-05 s |

