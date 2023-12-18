# Problem

## Statement
You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

### Examples
Example 1: \
Input: n = 2 \
Output: 2 \
Explanation: There are 2 ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2: \
Input: n = 3 \
Output: 3 \
Explanation: There are 3 ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
2. 2 steps

Example 3: \
Input: n = 6 \
Output: 13 \
Explanation: There are 13 ways to climb to the top.


### Constraints
- `1 <= n <= 45`


# Solution

## Approach
Two of the possible ways to solve the problem, both of which break finding optimal solution to the problem into optimal solutions of subproblems.
1. Backward Memoization
   - __Create container__: Each cell of the `memo` array of size (`n + 1`) stores possible ways to reach from the current cell to the end of the array by step size of 1 and/or 2
   - __Handle edge cases__: If at some point the step is outside of `memo`, return 0. Else if the step reached the end of `memo`, return 1 as it's only step.
   - __Avoid recomputation__: If `memo` cell is already computed, return its value.
   - __Compute each cell__: Each cell value is equal to value of next cells far from the current by step size of 1 and/or 2.
   - __Return the front__: The first element of `memo` contains total number of distinct ways to climb stairs.
2. Forward Dynamic Programming
   - __Create container__: Each cell of the `dp` array of size (`n + 1`) stores possible ways to reach the current cell from the beginning of the array.
   - __Initialize first cells__: Obviously, dp[0] = 0, dp[1] = 1, and if (n > 1) dp[2] = 2.
   - __Compute each cell__: If n > 1, each cell could be reached from previous cells by step size of 1 and/or 2.
   - __Return the back__: The last element of `dp` stores total number of distinct ways to climb stairs.

### Complexity
- __Time__: `O(n)`, iterate over each element of the container of length `n`.
- __Memory__: `O(n)`, the container (`dp`, `memo`) length.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_n2 | 6.70e-06 s |
| test2_n3 | 1.51e-06 s |
| test3_n6 | 1.35e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_n2 | 3.12e-05 s |
| test2_n3 | 1.76e-05 s |
| test3_n6 | 1.69e-05 s |

