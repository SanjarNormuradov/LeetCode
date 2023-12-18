from typing import List


class Solution:
    def is_valid(self, s: str) -> bool:
        if not self._check_constraints(s):
            raise ValueError("Constraints violated")
        if len(s) % 2 != 0:
            return False
        stck: List[str] = []
        for ch in s:
            if ch == '(' or ch == '{' or ch == '[':
                stck.append(ch)
            else:
                if len(stck) == 0:
                    return False
                if ch == ')' and not stck.pop() == '(':
                    return False
                elif ch == ']' and not stck.pop() == '[':
                    return False
                elif ch == '}' and not stck.pop() == '{':
                    return False

        return True if len(stck) == 0 else False

    def _check_constraints(self, s: str) -> bool:
        if len(s) < 1 or len(s) > 10**4:
            return False
        for ch in s:
            if not (ch == '(' or ch == ')' or ch == '[' or ch == ']' or ch == '{' or ch == '}'):
                return False
        return True
