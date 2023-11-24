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

Example 3:\
Input: obstacleGrid = [[1]]\
Output: 0

### Constraints
- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` is `0` or `1`.


# Solution

## Approach
To address this problem, a dynamic programming approach is used. A 1D array, dp, is created where `dp[j]` represents the count of distinct paths to reach cell (i, j) from the top-left corner (0, 0). The count for each cell is the sum of paths from the cell above `dp[i-1][j]` when the robot moves downwards, and from the cell to the left `dp[i][j-1]` when the robot moves right. If a cell contains an obstacle, its count is set to 0, indicating no accessible paths. \
No need to create 2D array of a shape `m x n` to store # paths for the entire grid, as we can move along each row at a time from the 1st column to the last (i.e. the robot moves right) and summing up recently updated value of a grid cell on the left with the current grid cell, which stores already counted # paths for the cell above. \
This method efficiently computes the total number of unique paths to the bottom-right corner while avoiding obstacles.

### Complexity
- __Time__: `O(m * n)`, as each cell in the `m x n` grid is processed once
- __Memory__: `O(n)` for the `dp` array storing paths for each cell

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_obstacleGrid1 | 8.26e-06 s |
| test2_obstacleGrid2 | 2.49e-06 s |
| test3_obstacleGrid3 | 1.83e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_obstacleGrid1 | 5.42e-03 s |
| test2_obstacleGrid2 | 8.15e-05 s |
| test3_obstacleGrid3 | 3.15e-05 s |

