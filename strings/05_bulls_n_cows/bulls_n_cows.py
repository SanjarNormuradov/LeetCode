from typing import Dict


class Solution:
    def get_hint(self, secret: str, guess: str) -> str:
        if not self._check_constraints(secret, guess):
            raise ValueError("Constraints violated")

        g = list(guess)
        bulls, cows = 0, 0
        digit_freq: Dict[str, int] = {}
        # First pass to find bulls
        for i in range(len(secret)):
            if secret[i] == g[i]:
                bulls += 1
                g[i] = '#'
            else:
                digit_freq[secret[i]] += 1
        # Second pass to find cows
        for i in range(len(g)):
            if (g[i] != '#') and (g[i] in digit_freq.keys()) and (digit_freq[g[i]] != 0):
                cows += 1
                digit_freq[g[i]] -= 1

        return f"{bulls}A{cows}B"

    def _check_constraints(self, s: str, g: str) -> bool:
        n = len(s)
        m = len(g)
        if n < 1 or n > 10**3:
            return False
        if m < 1 or m > 10**3:
            return False
        if n != m:
            return False

        for i in range(n):
            s_digit = int(s[i])
            g_digit = int(g[i])
            if not ((s_digit >= 0 and s_digit <= 9) or (g_digit >= 0 and g_digit <= 9)):
                return False

        return True
