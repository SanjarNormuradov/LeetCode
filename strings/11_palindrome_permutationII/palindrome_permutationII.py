from typing import List, Set, Union


class Solution:
    def generate_palindromes(self, s: str) -> List[str]:
        if not self._check_constraints(s):
            raise ValueError("Constraints violated")
        self.set: Set[str] = set()
        _map = [0] * 26
        st: List[str] = []
        if not self._can_permute_palindrome(s, _map):
            return []
        ch = None
        for i in range(26):
            if _map[i] % 2 == 1:
                ch = chr(i + ord('a'))
            for j in range(_map[i] // 2):
                st.append(chr(i + ord('a')))
        self._permute(st, 0, ch)
        return list(self.set)

    def _can_permute_palindrome(self, s: str, _map: List[int]) -> bool:
        odd_cnt = 0
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
        if len(s) < 1 or len(s) > 16:
            return False
        for ch in s:
            if not (ord(ch) >= ord('a') and ord(ch) < ord('a') + 26):
                return False
        return True

    def _permute(self, st: List[str], left_id: int, ch: Union[str, None]) -> None:
        if left_id == len(st):
            self.set.add("".join(st) + ("" if ch is None else ch) + "".join(st[::-1]))
        for right_id in range(left_id, len(st)):
            if st[right_id] != st[left_id] or right_id == left_id:
                # filter duplicates which might arise when swaping two same characters, except the same element chosen twice
                st[right_id], st[left_id] = st[left_id], st[right_id]
                self._permute(st, left_id + 1, ch)
                st[right_id], st[left_id] = st[left_id], st[right_id]
