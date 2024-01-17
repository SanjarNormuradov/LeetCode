# Problem

## Statement
You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

__Merge__ `nums1` and `nums2` into a single array sorted in __non-decreasing order__.

The final sorted array should not be returned by the function, but instead be _stored inside_ the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

### Examples
Example 1: \
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 \
Output: [1,2,2,3,5,6] \
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2: \
Input: nums1 = [1], m = 1, nums2 = [], n = 0 \
Output: [1] \
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3: \
Input: nums1 = [0], m = 0, nums2 = [1], n = 1 \
Output: [1] \
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


### Constraints
- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- `-10^9 <= nums1[i], nums2[j] <= 10^9`


# Solution

## Approach
Start fillig `nums1` from the end by comparing elements in `nums1` and `nums2` also from the end, i.e. `p = m + n - 1`, `p1 = m - 1` and `p2 = n - 1` respectively.
It's guaranteed that 'overtake' wouldn't happen becuase:
1. `p` is ahead of `p1` by `n` steps
2. If `p1` is decremented by `1`, `p` decreases by `1` too, keeping the constant gap.
3. If `p2` is decremented by `1`, `p` decreases by `1` too, shrinking the gap by `1`.
4. The maximum gap shrinkage might be `n`, but once it happens there is no element in `nums2` to iterate over -> `nums1` is sorted.


### Complexity
- __Time__: `O(n + m)`, iterate over each element of `nums1` and `nums2`.
- __Memory__: `O(1)`, indices to keep track of last checked elements in `nums1` and `nums2`.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_m3n3 | 2.18e-05 s |
| test2_m1n0 | 2.65e-06 s |
| test3_m0n1 | 2.80e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_m3n3 | 2.74e-05 s |
| test2_m1n0 | 1.38e-05 s |
| test3_m0n1 | 1.19e-05 s |

