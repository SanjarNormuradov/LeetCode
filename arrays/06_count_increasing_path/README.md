# Problem

## Statement
You are given an `m x n` integer matrix `grid`, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo `10^9 + 7`.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

### Examples
Example 1:\
Input: grid = [[1,1],[3,4]]\
Output: 8\
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.

Example 2:\
Input: grid = [[1],[2]]\
Output: 3\
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.

### Constraints
- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 1000`
- `1 <= m * n <= 105`
- `1 <= grid[i][j] <= 105`


# Solution

## Approach
This grid problem is solved using a blend of __Depth-First-Search (DFS)__ and dynamic programming for efficiency. The strategy involves exhaustively searching through the grid, cell by cell, and exploring all paths that progress to adjacent cells with increasing values. Dynamic programming enhances this process by storing the count of paths from each cell after their initial calculation, eliminating repetitive computations. When revisiting a cell, the stored count is reused. The overall solution sums the counts from each cell, providing the total number of increasing paths in the grid. This approach effectively combines thorough path exploration with computational optimization.

### Complexity
- __Time__: `O(m * n)`. Each cell in the m x n grid is examined once using Depth-First Search (DFS), with dynamic programming ensuring no redundant path calculations.
- __Memory__: `O(m * n)`. The space is mainly used for storing the count of paths from each cell, proportional to the grid's size.

## Test Results

### C++ Test Times

| Test Name | Time Spent |
| --- | --- |
| test1_Grid1 | 5.62e-05 s |
| test2_Grid2 | 2.16e-05 s |
| test3_Grid3 | 1.73e-05 s |
| test4_Grid4 | 1.67e-05 s |
| test5_Grid4 | 1.78e-05 s |
| test6_Grid6 | 2.04e-05 s |

### Python Test Times

| Test Name | Time Spent |
| --- | --- |
| test1_Grid1 | 1.47e-02 s |
| test2_Grid2 | 6.87e-03 s |
| test3_Grid3 | 7.27e-05 s |
| test4_Grid4 | 5.89e-05 s |
| test5_Grid5 | 5.87e-05 s |
| test6_Grid6 | 1.04e-02 s |
