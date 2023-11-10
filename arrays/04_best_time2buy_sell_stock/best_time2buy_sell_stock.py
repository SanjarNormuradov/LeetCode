from typing import List


class Solution:
    def max_profit(self, prices: List[int]) -> int:
        if not self._check_constraints(prices):
            raise ValueError("Constraints violated")

        min_price, max_profit = 10**4, 0
        for price in prices:
            min_price = min(min_price, price)
            max_profit = max(max_profit, price - min_price)

        return max_profit

    def _check_constraints(self, prices: List[int]) -> bool:
        n = len(prices)
        if n < 1 or n > 10**5:
            return False

        for price in prices:
            if price < 0 or price > 10**4:
                return False

        return True
