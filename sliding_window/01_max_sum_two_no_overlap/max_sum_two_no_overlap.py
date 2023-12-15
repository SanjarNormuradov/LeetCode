from typing import List


class Solution:
    def max_sum_two_no_overlap(self, nums: List[int], first_len: int, second_len: int) -> int:
        if not self._check_constraints(nums, first_len, second_len):
            raise ValueError('Constraints violated')
        # prefix sum with extra 0 at the front
        n = len(nums)
        prefix_sum = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix_sum[i] += nums[i - 1] + prefix_sum[i - 1]

        max_sum = 0
        for l_id in range(0, n + 1 - first_len):
            lr_id = l_id + first_len
            lsum = prefix_sum[lr_id] - prefix_sum[l_id]
            for r_id in range(n, second_len - 1, -1):
                rl_id = r_id - second_len
                if not ((lr_id > rl_id and lr_id <= r_id) or (l_id >= rl_id and l_id < r_id) or (rl_id >= l_id and r_id <= lr_id)):
                    rsum = prefix_sum[r_id] - prefix_sum[rl_id]
                    max_sum = max(lsum + rsum, max_sum)

        return max_sum

    def _check_constraints(self, nums: List[int], first_len: int, second_len: int) -> bool:
        if first_len < 1 or first_len > 10**3 or second_len < 1 or second_len > 10**3:
            return False
        if first_len + second_len < 2 or first_len + second_len > 10**3:
            return False
        _len = len(nums)
        if first_len + second_len > _len or _len > 10**3:
            return False
        for num in nums:
            if num < 0 or num > 10**3:
                return False
        return True
