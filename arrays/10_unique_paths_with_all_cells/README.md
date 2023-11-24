# Problem

## Statement
You are given an `m x n` integer array grid where `grid[i][j]` could be:
- `1` representing the starting square. There is exactly one starting square.
- `2` representing the ending square. There is exactly one ending square.
- `0` representing empty squares we can walk over.
- `-1` representing obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that _walk over every non-obstacle square exactly once_.

### Examples
Example 1:\
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]\
Output: 2\
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)


Example 2:\
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]\
Output: 4\
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:\
Input: grid = [[0,1],[2,0]]\
Output: 0\
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

### Constraints
- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 20`
- `1 <= m * n <= 20`
- `-1 <= grid[i][j] <= 2`

# Solution

## Approach
- __Backtracking__: Explore paths from the start square to the end square using recursion.
- __Count Non-Obstacle Squares__: Determine the total number of squares that can be walked over.
- __Recursive Exploration__: Move recursively in four directions from each square.
- __Visit Tracking__: Mark squares as visited during exploration and unvisited during backtracking.
- __Valid Path Counting__: Increase path count when the end is reached and all non-obstacle squares are visited.

### Complexity
- __Time__: O(4 (m * n)) - In the worst case, the algorithm explores all four directions at each step. The grid has `m x n` squares, leading to a time complexity of O(4^(m * n)). However, this is a loose upper bound since the algorithm stops exploring further when it hits obstacles or the grid boundaries.
- __Memory__: O(m * n). Additionally, if modifying the grid in place is not considered as extra space, then the space complexity is solely due to the recursion stack.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Grid1 | 4.62e-05 s |
| test2_Grid2 | 3.83e-05 s |
| test3_Grid3 | 4.07e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Grid1 | 2.63e-04 s |
| test2_Grid2 | 4.33e-04 s |
| test2_Grid3 | 3.15e-05 s |

