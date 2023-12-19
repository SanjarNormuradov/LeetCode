# Problem

## Statement
The __Fibonacci numbers__, commonly denoted `F(n)` form a sequence, called the __Fibonacci sequence__, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,
`F(0) = 0, F(1) = 1`
`F(n) = F(n - 1) + F(n - 2), for n > 1`

Given n, calculate `F(n)`.

### Examples
Example 1: \
Input: n = 0 \
Output: 0 \
Explanation: F(0) = 0.

Example 2: \
Input: n = 1 \
Output: 1 \
Explanation: F(1) = 1.

Example 3: \
Input: n = 2 \
Output: 1 \
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 4: \
Input: n = 3 \
Output: 2 \
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 5: \
Input: n = 4 \
Output: 3 \
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

Example 6: \
Input: n = 7 \
Output: 13 \
Explanation: F(7) = F(6) + F(5) = F(5) + F(4) + F(4) + F(3) = F(4) + F(3) + 2 * F(4) + F(3) = 3 * F(4) + 2 * F(3) = 3 * 3 + 2 * 2 = 13.


### Constraints
- `0 <= n <= 30`


# Solution

## Approach
Two of the possible ways to solve the problem, both of which break finding optimal solution to the problem into optimal solutions of subproblems.
1. Bottom-up or Tabulation

2. Top-down or Memoization


### Complexity
- __Time__: `O(n)`, iterate over each element of `cache` of length `n`.
- __Memory__: `O(n)`, `cache` length.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_fib0 | 1.12e-05 s |
| test2_fib1 | 3.20e-06 s |
| test3_fib2 | 3.55e-06 s |
| test4_fib3 | 2.74e-06 s |
| test5_fib4 | 2.65e-06 s |
| test6_fib7 | 2.67e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_fib0 | 2.46e-05 s |
| test2_fib1 | 1.17e-05 s |
| test3_fib2 | 1.24e-05 s |
| test4_fib3 | 1.03e-05 s |
| test5_fib4 | 9.54e-06 s |
| test6_fib7 | 9.54e-06 s |

