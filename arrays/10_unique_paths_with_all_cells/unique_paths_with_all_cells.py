import numpy as np


class Solution:
    def unique_paths_III(self, grid: np.ndarray) -> int:
        if not self._check_constraints(grid):
            raise ValueError('Constraints violated')
        non_obstacle = 0
        row, col = grid.shape
        for i in range(row):
            for j in range(col):
                if grid[i, j] >= 0:
                    non_obstacle += 1
                if grid[i, j] == 1:
                    start_x, start_y = i, j

        return self._backtrack(grid, start_x, start_y, non_obstacle)

    def _backtrack(self, grid: np.ndarray, x: int, y: int, remain: int) -> int:
        if (x < 0 or x >= grid.shape[0]) or (y < 0 or y >= grid.shape[1]) or grid[x, y] == -1:
            return 0
        if grid[x, y] == 2:
            return 1 if remain == 1 else 0

        # Mark the square as visited -> unreachable just like obstacle
        grid[x, y] = -1
        remain -= 1

        paths = self._backtrack(grid, x - 1, y, remain) + self._backtrack(grid, x + 1, y, remain) + self._backtrack(grid, x, y + 1, remain) + self._backtrack(grid, x, y - 1, remain)

        # Mark the square as unvisited to be considered by other possible paths
        grid[x, y] = 0
        remain += 1

        return paths

    def _check_constraints(self, grid: np.ndarray) -> bool:
        m = grid.shape[0]
        if m == 0 or m > 20:
            return False

        for i in range(m):
            n = grid[i].shape[0]
            if n == 0 or n > 20:
                return False
            if m * n == 0 or m * n > 20:
                return False
            for j in range(n):
                if grid[i, j] < -1 or grid[i, j] > 2:
                    return False

        return True
