from typing import List


class Solution:
    def fib(self, n: int) -> int:
        if not self._check_constraints(n):
            raise ValueError('Constraints violated')
        self.cache = {0: 0, 1: 1}
        # 1st method: bottom-up
        if n <= 1:
            return n
        cache: List[int] = [0] * (n + 1)
        cache[1] = 1
        for i in range(2, n + 1):
            cache[i] = cache[i - 1] + cache[i - 2]
        return cache[n]

        # 2nd method: top-down
        return self._F(n)

    def _check_constraints(self, n: int) -> bool:
        if n < 0 or n > 30:
            return False
        return True

    def _F(self, i: int) -> int:
        if self.cache.get(i):
            return i
        self.cache[i] = self._F(i - 1) + self._F(i - 2)
        return self.cache[i]
