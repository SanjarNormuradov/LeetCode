# Problem

## Statement
Given an `m x n` integers `matrix`, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. \
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

### Examples
Example 1:\
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]\
Output: 4\
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:\
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]\
Output: 4\
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:\
Input: matrix = [[1]]\
Output: 1

### Constraints
- `m == matrix.length`\
- `n == matrix[i].length`\
- `1 <= m, n <= 200`\
- `0 <= matrix[i][j] <= 231 - 1`\

# Solution

## Approach
To find the longest increasing path in a matrix, a __Depth-First Search (DFS)__ algorithm combined with memoization is used. Starting from each cell, the algorithm explores all possible paths that can be taken by moving up, down, left, or right to adjacent cells with higher values. This exploration is recursive, following the DFS pattern. To improve efficiency, the length of the longest path from each cell is stored (memoized) after its first computation. This prevents redundant recalculations for cells already visited. The final answer is the maximum length found among all starting cells, representing the longest increasing path in the matrix.

### Complexity
- __Time__: O(m * n). Each cell in the m x n matrix is visited once for the Depth-First Search (DFS), with memoization ensuring no repeated calculations.
- __Memory__: O(m * n). The memoization table, which stores the longest path from each cell, occupies space proportional to the matrix size.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Path1 | 3.24e-05 s |
| test2_Path2 | 9.74e-06 s |
| test3_Path3 | 3.67e-06 s |
| test4_Path4 | 3.98e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Path1 | 1.92e-04 s |
| test2_Path2 | 1.31e-04 s |
| test3_Path3 | 4.12e-05 s |
| test4_Path4 | 4.74e-05 s |
