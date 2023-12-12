class Solution:
    def is_palindrome(self, s: str) -> bool:
        if not self._check_constraints(s):
            raise ValueError("Constraints violated")
        odd_cnt = 0
        _map = [0] * 26
        for ch in s:
            _map[ord(ch) - ord('a')] += 1
            if _map[ord(ch) - ord('a')] % 2 == 0:
                odd_cnt -= 1
            else:
                odd_cnt += 1
        # the number of characters with odd number of occurrences can't exceed 1
        # (1 in case of odd s_length and 0 in case of even s_length).
        return odd_cnt <= 1

    def _check_constraints(self, s: str) -> bool:
        if len(s) < 1 or len(s) > 5000:
            return False

        for ch in s:
            if not (ord(ch) >= ord('a') and ord(ch) < ord('a') + 26):
                return False

        return True
