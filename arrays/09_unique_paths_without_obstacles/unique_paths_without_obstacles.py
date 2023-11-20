import numpy as np


class Solution:
    def unique_paths(self, m: int, n: int) -> int:
        if not self._check_constraints(m, n):
            raise ValueError('Constraints violated')

        #   dp[i][j] = num paths to get to (i, j) from (0, 0)
        #            = dp[i - 1][j] (move down) + dp[i][j - 1] (move right)
        #  But we need only one container to store # paths as it can execute ONLY one action (move down/right) at a time
        dp = np.zeros(n, dtype=np.uint32)
        dp[0] = 1  # Exactly one paths to get from (0, 0) to (0, 0)

        for i in range(0, m):
            dp[0] = 1  # Exactly one paths to get from (0, 0) to (i, 0) is by moving downwards
            for j in range(1, n):
                dp[j] += dp[j]

        return dp[n - 1]

    def _check_constraints(self, m: int, n: int) -> bool:
        if m == 0 or m > 100:
            return False
        if n == 0 or n > 100:
            return False

        return True
