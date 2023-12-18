from typing import List
from copy import copy


class Solution:
    def generate(self, n: int) -> List[List[int]]:
        if not self._check_constraints(n):
            raise ValueError('Constraints violated')
        ans: List[List[int]] = []
        dp = [1]
        ans.append(copy(dp))
        if n > 1:
            dp.append(1)
            ans.append(copy(dp))
        if n > 2:
            for j in range(2, n):
                for i in range(j - 1, 0, -1):
                    dp[i] += dp[i - 1]
                dp.append(1)
                ans.append(copy(dp))

        return ans

    def _check_constraints(self, n: int) -> bool:
        if n < 1 or n > 30:
            return False
        return True
