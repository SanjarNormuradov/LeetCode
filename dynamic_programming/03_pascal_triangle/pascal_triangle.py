from typing import List
from copy import copy


class Solution:
    def generate(self, num_rows: int) -> List[List[int]]:
        if not self._check_constraints(num_rows):
            raise ValueError('Constraints violated')
        ans: List[List[int]] = []
        dp = [1]
        ans.append(copy(dp))
        if num_rows > 1:
            dp.append(1)
            ans.append(copy(dp))
        if num_rows > 2:
            for j in range(2, num_rows):
                for i in range(j - 1, 0, -1):
                    dp[i] += dp[i - 1]
                dp.append(1)
                ans.append(copy(dp))

        return ans

    def _check_constraints(self, n: int) -> bool:
        if n < 1 or n > 30:
            return False
        return True
