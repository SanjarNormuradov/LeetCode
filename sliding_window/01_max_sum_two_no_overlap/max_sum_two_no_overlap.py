from typing import List


class Solution:
    def max_sum_two_no_overlap(self, nums: List[int], first_len: int, second_len: int) -> int:
        if not self._check_constraints(nums, first_len, second_len):
            raise ValueError('Constraints violated')
        return max(self._slider(nums, first_len, second_len), self._slider(nums, second_len, first_len))

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

    def _slider(self, nums: List[int], len1: int, len2: int) -> int:
        n = len(nums)
        dp1, dp2 = [0] * n, [0] * n
        sum = 0
        # prefix sum for a window of size len1
        for i in range(n):
            if i < len1:  # prefix sum for a subarray of size < len1
                sum += nums[i]
                dp1[i] = sum
            else:  # max sum of the subarray of size == len1, a window slides from left to right
                sum += nums[i] - nums[i - len1]
                dp1[i] = max(dp1[i - 1], sum)
        sum = 0
        # suffix sum for a window of size len2
        for i in range(n - 1, -1, -1):
            if i > n - 1 - len2:  # suffix sum for a subarray of size < len2
                sum += nums[i]
                dp2[i] = sum
            else:  # max sum of the subarray of size == len2, a window slides from right to left
                sum += nums[i] - nums[i + len2]
                dp2[i] = max(dp2[i - 1], sum)
        ans = 0
        for i in range(len1 - 1, n - len2):
            ans = max(ans, dp1[i] + dp2[i + 1])

        return ans
