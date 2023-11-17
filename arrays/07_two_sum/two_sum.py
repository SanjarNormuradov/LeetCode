from typing import List, Dict


class Solution:
    def count_paths(self, nums: List[int], target: int) -> List[int]:
        if not self._check_constraints(nums, target):
            raise ValueError('Constraints violated')

        inds: Dict[int, int] = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in inds.keys():
                return [inds[complement], i]
            inds[nums[i]] = i

        return []

    def _check_constraints(self, nums: List[int], t: int) -> bool:
        n = len(nums)
        if n < 2 or n > 10**4:
            return False
        if t < -10**9 or t > 10**9:
            return False

        for num in nums:
            if num < -10**9 or num > 10**9:
                return False

        return True
