import sys
from typing import List


class Solution:
    def longest_common_prefix(self, strs: List[str]) -> str:
        if not self._check_constraints(strs):
            raise ValueError('Constraints violated')
        min_len = sys.maxsize
        for i in range(len(strs)):
            min_len = min(len(strs[i]), min_len)
        low, high = 1, len(strs)
        while low <= high:
            mid = (low + high) // 2
            if self._is_common_prefix(strs, mid):
                low = mid + 1
            else:
                high = mid - 1
        return strs[0][:(low + high) // 2]

    def _check_constraints(self, strs: List[str]) -> bool:
        if len(strs) < 1 or len(strs) > 200:
            return False
        for i in range(len(strs)):
            if len(strs[i]) < 0 or len(strs[i]) > 200:
                return False
            for ch in strs[i]:
                if ch < 'A' or (ch > 'Z' and ch < 'a') or ch > 'z':
                    return False
        return True

    def _is_common_prefix(self, strs: List[str], len: int) -> bool:
        min_str = strs[0][:len]
        if not all(s.startswith(min_str) for s in strs[1:]):
            return False
        return True
