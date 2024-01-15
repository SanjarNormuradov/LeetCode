# Problem

## Statement
Given an `m x n` binary matrix `mat`, return the distance of the nearest `0` for each cell.

The distance between two adjacent cells is `1`.

### Examples
Example 1: \
Input: mat = [[0,0,0],[0,1,0],[0,0,0]] \
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2: \
Input: mat = [[0,0,0],[0,1,0],[1,1,1]] \
Output: [[0,0,0],[0,1,0],[1,2,1]]


### Constraints
- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 10^4`
- `1 <= m * n <= 10^4`
- `mat[i][j]` is `0` or `1`
- There is at least one `0` in `mat`.


# Solution

## Approach
The BFS approach efficiently computes the shortest distance to the nearest '0' for all cells in a binary matrix. It guarantees that each cell's distance is updated correctly by using a queue to process cells in a FIFO (First-In-First-Out) manner, ensuring that closer cells are processed before further ones. The algorithm is straightforward and runs in linear time and space relative to the size of the input matrix.
__Initialization__:
- A `dist` matrix of the same dimensions as the input matrix is created, initialized with `INT32_MAX` to represent infinity, as the initial distance to a `0` cell is unknown.
- A queue `q` is used to perform the BFS.
__Identifying Starting Points__:
- The matrix is traversed, and every cell containing `0` is added to the queue `q`, and its corresponding distance in `dist` is set to `0`. These cells are the starting points for the BFS.
__Breadth-First Search__:
- Perform BFS starting from each `0` cell added to the queue.
- For each cell dequeued, its adjacent cells (up, down, left, right) are examined. If an adjacent cell has a greater distance value in `dist`, it is updated to the current cell's distance plus one, and this adjacent cell is added to the queue for further exploration.
- This process continues until the queue is empty, ensuring that each cell's distance is updated to reflect the shortest distance to the nearest `0`.

### Complexity
- __Time__: `O(m * n)`, as each cell in the `m x n` mat is processed once, and queue `q` can also hold the same number of elements in the worst case.
- __Memory__: `O(m * n)` for the `dist` array storing distances of each cell from the nearest `0`.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Matrix1 | 3.70e-05 s |
| test2_Matrix2 | 4.56e-05 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Matrix1 | 6.20e-03 s |
| test2_Matrix2 | 1.50e-04 s |

