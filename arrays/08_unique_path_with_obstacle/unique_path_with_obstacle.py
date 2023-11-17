import numpy as np


class Solution:
    def count_paths(self, grid: np.ndarray) -> int:
        if not self._check_constraints(grid):
            raise ValueError('Constraints violated')

        self.memo = -1 * np.ones_like(grid, dtype=np.uint16)
        self.grid = grid
        m, n = grid.shape
        max_cnt = 0
        # Update path grid with all possible paths
        for i in range(m):
            for j in range(n):
                if self.memo[i][j] == -1:
                    max_cnt = (max_cnt + self._depth_first_search(i, j, -1)) % 1000000007
                else:
                    max_cnt = (max_cnt + self.memo[i][j]) % 1000000007

        return max_cnt

    def _depth_first_search(self, i: int, j: int, prev: int) -> int:
        if (i < 0 or i >= self.grid.shape[0]) or (j < 0 or j >= self.grid.shape[1]) or prev > self.grid[i, j]:
            return 0
        if self.memo[i, j] != -1:
            return self.memo[i, j]

        top = self._depth_first_search(i - 1, j, self.grid[i][j])
        bottom = self._depth_first_search(i + 1, j, self.grid[i][j])
        right = self._depth_first_search(i, j + 1, self.grid[i][j])
        left = self._depth_first_search(i, j - 1, self.grid[i][j])
        self.memo[i, j] = (1 + top + bottom + right + left) % 1000000007

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
