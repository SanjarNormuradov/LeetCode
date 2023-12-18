from typing import List


class Solution:
    def climb_stairs(self, n: int) -> int:
        if not self._check_constraints(n):
            raise ValueError('Constraints violated')
        # Break optimal solution to the problem into optimal solutions to subproblems
        # 1st method: backward memoization
        # memo: List[int] = [0] * (n + 1)
        # return self._backward_memo(0, n, memo)

        # 2nd method: forward dynamic programming
        dp: List[int] = [0] * (n + 1)
        dp[1] = 1
        if n > 1:
            dp[2] = 2
            for i in range(3, n + 1):
                dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]

    def _check_constraints(self, n: int) -> bool:
        if n < 1 or n > 45:
            return False
        return True

    def _backward_memo(self, i: int, n: int, memo: List[int]) -> int:
        if i > n:  # overshoot
            return 0
        if i == n:  # reached the end
            return 1
        if memo[i] > 0:  # computed before
            return memo[i]
        memo[i] = self._backward_memo(i + 1, n, memo) + self._backward_memo(i + 2, n, memo)  # forward step of size 1 and 2
        return memo[i]
