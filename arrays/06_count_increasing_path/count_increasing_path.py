import numpy as np


class Solution:
    def count_paths(self, grid: np.ndarray) -> int:
        self.MOD = 10**9 + 7
        if not self._check_constraints(grid):
            raise ValueError('Constraints violated')

        self.memo = -1 * np.ones_like(grid, dtype=np.uint16)
        self.grid = grid
        self.m, self.n = grid.shape
        max_cnt = 0
        # Update path grid with all possible paths
        for i in range(self.m):
            for j in range(self.n):
                max_cnt += self._depth_first_search(i, j)
                max_cnt %= self.MOD

        return max_cnt

    def _depth_first_search(self, i: int, j: int) -> int:
        if self.memo[i, j] != -1:
            return self.memo[i, j]

        num_paths = 1  # Start with a path in the current cell
        steps = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dx, dy in steps:
            x, y = i + dx, j + dy
            if (0 <= x < self.m) and (0 <= y < self.n) and (self.grid[x, y] > self.grid[i, j]):
                num_paths += self._depth_first_search(x, y)

        self.memo[i, j] = num_paths % self.MOD
        return self.memo[i, j]

    def _check_constraints(self, grid: np.ndarray) -> bool:
        m = grid.shape[0]
        if m == 0 or m > 1000:
            return False

        for row in grid:
            if row.shape[0] == 0 or row.shape[0] > 1000:
                return False
            if row.shape[0] * m == 0 or row.shape[0] * m > 10**5:
                return False

            for num in row:
                if num < 1 or num > 10**5:
                    return False

        return True
