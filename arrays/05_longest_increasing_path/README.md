## Problem Statement
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down.\
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

### Examples
Example 1:\
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]\
Output: 4\
Explanation: The longest increasing path is [1, 2, 6, 9].\

Example 2:\
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]\
Output: 4\
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.\

Example 3:\
Input: matrix = [[1]]\
Output: 1\

### Constraints
`m == matrix.length`\
`n == matrix[i].length`\
`1 <= m, n <= 200`\
`0 <= matrix[i][j] <= 231 - 1`\


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
