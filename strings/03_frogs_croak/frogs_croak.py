import numpy as np


class Solution:
    def min_number_of_frogs(self, croaks_of_frogs: str) -> int:
        if not self._check_constraints(croaks_of_frogs):
            raise ValueError("Constraints violated")

        max_frogs, cur_frogs = 0, 0
        cnts = np.zeros(5, dtype=np.uint8)

        for ch in croaks_of_frogs:
            if ch == 'c':
                cnts[0] += 1
                cur_frogs += 1
                max_frogs = max(max_frogs, cur_frogs)
            else:
                if ch == 'r':
                    if cnts[0] <= cnts[1]:
                        return -1
                    cnts[1] += 1
                elif ch == 'o':
                    if cnts[1] <= cnts[2]:
                        return -1
                    cnts[2] += 1
                elif ch == 'a':
                    if cnts[2] <= cnts[3]:
                        return -1
                    cnts[3] += 1
                elif ch == 'k':
                    if cnts[3] <= cnts[4]:
                        return -1
                    cnts[4] += 1
                    cur_frogs -= 1

        max_cnt = cnts[0]
        for i in range(1, 5):
            if cnts[i] != max_cnt:
                return -1

        return max_frogs

    def _check_constraints(self, croaks_of_frogs: str) -> bool:
        n = len(croaks_of_frogs)
        if n < 1 or n > 10**5:
            return False

        legits = ['c', 'r', 'o', 'a', 'k']
        for ch in croaks_of_frogs:
            if ch not in legits:
                return False

        return True
