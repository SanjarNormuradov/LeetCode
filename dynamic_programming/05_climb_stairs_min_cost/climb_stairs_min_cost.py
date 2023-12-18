from typing import List


class Solution:
    def min_cost_climbing_stairs(self, cost: List[int]) -> int:
        if not self._check_constraints(cost):
            raise ValueError('Constraints violated')
        n = len(cost)
        # Break optimal solution to the problem into optimal solutions to subproblems
        # 1st method: backward memoization
        memo: List[int] = [-1] * (n + 1)
        return self._backward_memo(0, n, memo, cost)

        # 2nd method: forward dynamic programming
        dp: List[int] = [0] * (n + 1)
        dp[0] = cost[1]
        dp[1] = cost[2]
        for i in range(2, n + 1):
            dp[i] = cost[i] if i < n else 0
            dp[i] += min(dp[i - 1], dp[i - 2])
        return dp[n]

    def _check_constraints(self, cost: List[int]) -> bool:
        if len(cost) < 2 or len(cost) > 1000:
            return False
        for c in cost:
            if c < 0 or c > 999:
                return False
        return True

    def _backward_memo(self, i: int, n: int, memo: List[int], cost: List[int]) -> int:
        if i > n:  # overshoot
            return 0
        if memo[i] > -1:  # computed before
            return memo[i]
        memo[i] = cost[i - 1] if i > 0 else 0
        memo[i] += min(self._backward_memo(i + 1, n, memo, cost), self._backward_memo(i + 2, n, memo, cost))  # forward step of size 1 and 2
        return memo[i]
