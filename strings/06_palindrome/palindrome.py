class Solution:
    def is_palindrome(self, x: int) -> bool:
        if not self._check_constraints(x):
            raise ValueError("Constraints violated")
        if x < 0:
            return False

        x_reversed = 0
        tmp = x
        while tmp != 0:
            digit = tmp % 10
            x_reversed = x_reversed * 10 + digit
            tmp //= 10

        return x_reversed == x

    def _check_constraints(self, x: int) -> bool:
        if x < -2**31 or x > 2**31 - 1:
            return False

        return True
