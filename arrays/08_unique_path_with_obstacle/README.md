# Problem

## Statement
You are given an `m x n` integer array `grid`. There is a robot initially located at the top-left corner (i.e., `grid[0][0]`). \
The robot tries to move to the bottom-right corner (i.e., `grid[m - 1][n - 1]`). \
The robot can _only move either down or right_ at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to `2 * 10^9`.

### Examples
Example 1:\
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]\
Output: 2\
Explanation: There is one obstacle in the middle of the 3x3 grid above. \
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:\
Input: obstacleGrid = [[0,1],[0,0]]\
Output: 1

### Constraints
- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` is `0` or `1`.


# Solution

## Approach
To address this problem, a dynamic programming approach is used. A 2D array, dp, is created where `dp[i][j]` represents the count of distinct paths to reach cell (i, j) from the top-left corner. The count for each cell is the sum of paths from the cell above `dp[i-1][j]` and from the cell to the left `dp[i][j-1]`. If a cell contains an obstacle, its count is set to 0, indicating no accessible paths. This method efficiently computes the total number of unique paths to the bottom-right corner while avoiding obstacles.

### Complexity
- __Time__: O(m * n), as each cell in the `m x n` grid is processed once
- __Memory__: O(m * n) for the `dp` array storing paths for each cell

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_obstacleGrid1 | 1.01e-05 s |
| test2_obstacleGrid2 | 3.15e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_obstacleGrid1 | 1.71e-04 s |
| test2_obstacleGrid2 | 4.98e-05 s |

