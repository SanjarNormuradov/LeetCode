# Problem

## Statement
Given an integer `numRows`, return the first `numRows` of __Pascal's triangle__.

In __Pascal's triangle__, each number is the sum of the two numbers directly above

### Examples
Example 1: \
Input: numRows = 5 \
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2: \
Input: numRows = 1 \
Output: [[1]]

Example 3: \
Input: numRows = 7 \
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1],[1,5,10,10,5,1],[1,6,15,20,15,6,1]]


### Constraints
- `1 <= n <= 30`


# Solution

## Approach
 Finally append 1 before pushing into global container which stores the answer.
- __Create container__: Use the same container for each row as it stores numbers from the previous row above. Initialize the answer with a container of 1 as `numRows >= 1`
- __Handle edge cases__: If `numRows > 1`, append the next row of 2 elements (1). All the rest will be filled in the main loop. 
- __Compute each element__: If `numRows > 2`, iterate through each row starting from the end and update each element with the sum of itself (which is equal to the element value in the row above) and the element value on the left in the current row.
- __Append updated row__: Once every element in the current row is updated, append 1 to the row. Then append the row to the answer.

### Complexity
- __Time__: `O(n^2)`, the sum of each row of size equal to its row number. Total sum is `1+2+..+n` which is `n(n+1)/2 ~ n^2`
- __Memory__: `O(n^2)`, the same as above plus additional space for dp of `O(n)`.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_n5 | 1.55e-05 s |
| test2_n1 | 3.42e-06 s |
| test3_n7 | 1.12e-05 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_n5 | 2.65e-05 s |
| test2_n1 | 1.26e-05 s |
| test3_n7 | 1.53e-05 s |

