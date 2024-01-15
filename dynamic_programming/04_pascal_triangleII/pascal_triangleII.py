from typing import List


class Solution:
    def get_row(self, row_index: int) -> List[int]:
        if not self._check_constraints(row_index):
            raise ValueError('Constraints violated')
        dp = [1]
        if row_index > 0:
            dp.append(1)
            for j in range(1, row_index):
                for i in range(j, 0, -1):
                    dp[i] += dp[i - 1]
                dp.append(1)

        return dp

    def _check_constraints(self, n: int) -> bool:
        if n < 0 or n > 33:
            return False
        return True
