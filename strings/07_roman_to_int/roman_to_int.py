class Solution:
    def roman_to_int(self, s: str) -> int:
        if not self._check_constraints(s):
            raise ValueError("Constraints violated")

        roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        total = 0

        for i in range(len(s)):
            # If the current value is less than the next value, subtract it
            if i < len(s) - 1 and roman[s[i]] < roman[s[i + 1]]:
                total -= roman[s[i]]
            else:
                total += roman[s[i]]

        if (total < 1) or (total > 3999):
            raise ValueError("Constraints violated")

        return total

    def _check_constraints(self, s: str) -> bool:
        if len(s) < 1 or len(s) > 15:
            return False
        roman = set(['I', 'V', 'X', 'L', 'C', 'D', 'M'])
        for ch in s:
            if ch not in roman:
                return False

        return True
