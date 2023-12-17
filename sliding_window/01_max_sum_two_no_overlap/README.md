# Problem

## Statement
Given an integer array `nums` and two integers `firstLen` and `secondLen`, return _the maximum sum of elements in two non-overlapping subarrays with lengths_ `firstLen` _and_ `secondLen`.

The array with length `firstLen` could occur before or after the array with length `secondLen`, but they have to be non-overlapping.

A __subarray__ is a contiguous part of an array.

### Examples
Example 1: \
Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2 \
Output: 20 \
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.

Example 2: \
Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2 \
Output: 29 \
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.

Example 3: \
Input: nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3 \
Output: 31 \
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3.

Example 4: \
Input: nums = [4,5,14,16,16,20,7,13,8,15], firstLen = 5, secondLen = 3
Output: 109
Explanation: One choice of subarrays is [14,16,16,20,7] with length 5, and [13,8,15] with length 3.

### Constraints
- `1 <= firstLen, secondLen <= 1000`
- `2 <= firstLen + secondLen <= 1000`
- `firstLen + secondLen <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`


# Solution

## Approach
__Create containers__: Create two list of size nums.size() to store max prefix and suffix sums. 
__Iterate through the array__: Slide a window of size firstLen from left to right, computing max prefix sum of the subarray within the window at each step. Do the same for a window of size secondLen from right to left, computing the max suffix sum.
__Find the max subarray sum__: Go through [firstLen - 1, nums.size() - secondLen] indices of the prefix list, and [firstLen, nums.size() - secondLen - 1] of the suffix list to compute the max possible sum.
__Repeat with swapped lengths__: Repeat the process for swapped lenghts firstLen -> secondLen and vice versa.

### Complexity
- __Time__: `O(n)`, where n is the length of nums.
- __Memory__: `O(n)`, for two new lists dp1/dp2 created to store prefix/suffix sums.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Len12 | 4.88e-06 s |
| test2_Len32 | 1.60e-06 s |
| test3_Len43 | 1.55e-06 s |
| test4_Len53 | 1.53e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Len12 | 5.29e-05 s |
| test2_Len32 | 3.43e-05 s |
| test3_Len43 | 3.43e-05 s |
| test4_Len53 | 3.05e-05 s |

