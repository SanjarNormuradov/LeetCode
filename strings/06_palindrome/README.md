# Problem

## Statement
Given an integer `x`, return true if x is a _palindrome_, and false otherwise.

### Examples
Example 1:\
Input: x = 121\
Output: true\
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:\
Input: x = -121\
Output: false\
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:\
Input: x = 10\
Output: false\
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

### Constraints
- `-2^31 <= x <= 2^31 - 1`

# Solution

## Approach
To determine if an integer is a palindrome, the solution involves reversing the number and comparing it with the original. Negative numbers are immediately considered non-palindromic. The reverse of the integer is constructed by iteratively extracting and appending its digits. Finally, the original number and its reverse are compared to check for palindromicity.

### Complexity
- __Time__: `O(log x)`, where x is the input integer. This reflects the number of digits in x.
- __Memory__: `O(1)`, as the space used is constant and independent of the input size.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_121 | 1.73e-05 s |
| test2_n121 | 1.19e-06 s |
| test3_10 | 1.03e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_121 | 2.55e-05 s |
| test2_n121 | 1.17e-05 s |
| test3_10 | 9.78e-06 s |
