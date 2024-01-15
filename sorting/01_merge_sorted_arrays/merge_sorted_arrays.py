from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        if not self._check_constraints(nums1, m, nums2, n):
            raise ValueError('Constraints violated')
        p1 = m - 1
        p2 = n - 1
        for p in range(m + n - 1, -1, -1):
            if p2 < 0:
                break
            if p1 > -1 and nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1

    def _check_constraints(self, nums1: List[int], m: int, nums2: List[int], n: int) -> bool:
        if len(nums1) != m + n:
            return False
        if len(nums2) != n:
            return False
        if n < 0 or n > 200 or m < 0 or m > 200:
            return False
        if (m + n) < 1 or (m + n) > 200:
            return False
        for i in range(m):
            if nums1[i] < -10**9 or nums1[i] > 10**9:
                return False
        for j in range(n):
            if nums2[j] < -10**9 or nums2[j] > 10**9:
                return False
        return True
