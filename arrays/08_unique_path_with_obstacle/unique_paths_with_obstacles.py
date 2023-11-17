import numpy as np


class Solution:
    def unique_paths_with_obstacles(self, obstacle_grid: np.ndarray) -> int:
        if not self._check_constraints(obstacle_grid):
            raise ValueError('Constraints violated')

        dp = np.ones_like(obstacle_grid, dtype=np.uint32)
        m, n = obstacle_grid.shape
        dp[0, 0] = 1
        # Fill the first row
        for j in range(1, n):
            if obstacle_grid[0, j] == 0:
                dp[0, j] = dp[0, j - 1]
        # Fill the first column
        for i in range(1, m):
            if obstacle_grid[i, 0] == 0:
                dp[i, 0] = dp[i - 1, 0]
        # Fill the rest
        for i in range(1, m):
            for j in range(1, n):
                if obstacle_grid[i, j] == 0:
                    dp[i, j] = dp[i - 1, j] + dp[i, j - 1]

        return dp[m - 1, n - 1]

    def _check_constraints(self, grid: np.ndarray) -> bool:
        m = grid.shape[0]
        if m == 0 or m > 100:
            return False

        for row in grid:
            if row.shape[0] == 0 or row.shape[0] > 100:
                return False
            for num in row:
                if not (num == 0 or num == 1):
                    return False

        return True
