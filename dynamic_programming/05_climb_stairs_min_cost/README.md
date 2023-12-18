# Problem

## Statement
You are given an integer array `cost` where `cost[i]` is the cost of `i^th` step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

Return the _minimum cost to reach the top of the floor_.

### Examples
Example 1: \
Input: cost = [10,15,20] \
Output: 15 \
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2: \
Input: cost = [1,100,1,1,1,100,1,1,100,1] \
Output: 6 \
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.


### Constraints
- `2 <= cost.length <= 1000`
- `0 <= cost[i] <= 999`


# Solution

## Approach
Two of the possible ways to solve the problem, both of which break finding optimal solution to the problem into optimal solutions of subproblems.
1. Backward Memoization
   - __Create container__: Each cell of the `memo` array of size (`n + 1`) stores min cost to reach from the current cell to the end of the array by step size of 1 and/or 2. Initial values are set to -1 to differentiate between non-visited/visited with some cost (0 is possible).
   - __Handle edge cases__: If at some point the step is outside of `memo`, return 0, encouraging towards the lowest cost.
   - __Avoid recomputation__: If `memo` cell is already computed, return its value.
   - __Compute each cell__: Each cell value is equal to the sum of the corresponding cell in `cost` and min value of next cells far from the current by step size of 1 and/or 2. Exception is for the first `memo` cell which is just the min value of the next two cells as `memo` size is greater than `cost` by 1.
   - __Return the front__: The first element of `memo` contains total min cost to reach the top.
2. Forward Dynamic Programming
   - __Create container__: Each cell of the `dp` array of size (`n + 1`) stores min cost to reach the current cell from the beginning of the array. Inital values are 0.
   - __Initialize first cells__: Obviously, dp[0] = cost[0], dp[1] = cost[1].
   - __Compute each cell__: If n > 2, each cell could be reached from previous cells by step size of 1 and/or 2 + as it's already visited, the total value is the sum of the corresponding cell in `cost` and min value of the previous two cells. Exception is the last element of `dp` which is just min value of the previous two cells as `dp.size() = cost.size() + 1`.
   - __Return the back__: The last element of `dp` stores total min cost to reach the top.

### Complexity
- __Time__: `O(n)`, iterate over each element of the container of length `n`.
- __Memory__: `O(n)`, the container (`dp`, `memo`) length.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_cost1 | 7.57e-06 s |
| test2_cost2 | 2.54e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_cost1 | 3.12e-05 s |
| test2_cost2 | 2.05e-05 s |

