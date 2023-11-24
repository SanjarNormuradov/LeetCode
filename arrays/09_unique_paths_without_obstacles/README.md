# Problem

## Statement
There is a robot on an `m x n` grid. The robot is initially located at the top-left corner (i.e., `grid[0][0]`). \
The robot tries to move to the bottom-right corner (i.e., `grid[m - 1][n - 1]`). \
The robot can _only move either down or right_ at any point in time.

Given the two integers `m` and `n`, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to `2 * 10^9`.

### Examples
Example 1:\
Input: m = 3, n = 7\
Output: 28

Example 2:\
Input: m = 3, n = 2\
Output: 3\
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

### Constraints
- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`

# Solution

## Approach
To address this problem, a dynamic programming approach is used. A 1D array, dp, is created where `dp[j]` represents the count of distinct paths to reach cell (i, j) from the top-left corner (0, 0). The count for each cell is the sum of paths from the cell above `dp[i-1][j]` when the robot moves downwards, and from the cell to the left `dp[i][j-1]` when the robot moves right. \
No need to create 2D array of a shape `m x n` to store # paths for the entire grid, as we can move along each row at a time from the 1st column to the last (i.e. the robot moves right) and summing up recently updated value of a grid cell on the left with the current grid cell, which stores already counted # paths for the cell above. \
This method efficiently computes the total number of unique paths to the bottom-right corner while avoiding obstacles.

### Complexity
- __Time__: `O(m * n)`, as each cell in the `m x n` grid is processed once
- __Memory__: `O(n)` for the `dp` array storing paths for each cell

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Grid1 | 6.75e-06 s |
| test2_Grid2 | 1.42e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Grid1 | 2.16e-04 s |
| test2_Grid2 | 6.37e-05 s |

