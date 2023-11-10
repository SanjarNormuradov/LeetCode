from typing import List
from collections import defaultdict


class Solution:
    def restore_from_adjacent_pairs(self, adjacent_pairs: List[List[int]]) -> List[int]:
        if not self._check_constraints(adjacent_pairs):
            raise ValueError("Constraints violated")

        adjacency_list = defaultdict(list)
        for u, v in adjacent_pairs:
            adjacency_list[u].append(v)
            adjacency_list[v].append(u)

        nums: List[int] = list()
        for key, value in adjacency_list.items():
            if len(value) == 1:
                nums.append(key)
                nums.append(value[0])
                break

        while len(nums) < len(adjacency_list):
            last = nums[-1]
            next = adjacency_list[last][0] if adjacency_list[last][0] != nums[-2] else adjacency_list[last][1]
            nums.append(next)

        return nums

    def _check_constraints(self, adjacent_pairs: List[List[int]]) -> bool:
        n = len(adjacent_pairs) + 1
        if n < 2 or n > 10**5:
            return False

        for i in range(n):
            if len(adjacent_pairs[i]) != 2:
                return False
            if adjacent_pairs[i][0] < -10**5 or adjacent_pairs[i][0] > 10**5:
                return False
            if adjacent_pairs[i][1] < -10**5 or adjacent_pairs[i][1] > 10**5:
                return False

        return True
