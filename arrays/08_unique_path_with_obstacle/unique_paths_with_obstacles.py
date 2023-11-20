import numpy as np


class Solution:
    def unique_paths_with_obstacles(self, obstacle_grid: np.ndarray) -> int:
        if not self._check_constraints(obstacle_grid):
            raise ValueError('Constraints violated')

        row, col = obstacle_grid.shape
        #   dp[i][j] = num paths to get to (i, j) from (0, 0)
        #            = dp[i - 1][j] (move down) + dp[i][j - 1] (move right)
        #  But we need only one container to store # paths as it can execute ONLY one action (move down/right) at a time
        dp = np.zeros(col, dtype=np.uint32)
        dp[0] = 1 if obstacle_grid[0][0] == 0 else 0  # Top-right cell (not) in collision

        for i in range(0, row):
            if obstacle_grid[i][0]:  # Firt column in collision
                dp[0] = 0
            for j in range(1, col):
                if obstacle_grid[i, j]:
                    dp[j] = 0
                else:
                    dp[j] += dp[j]

        return dp[col - 1]

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
