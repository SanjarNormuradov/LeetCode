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


### Complexity


## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Len12 | 7.94e-06 s |
| test2_Len32 | 3.14e-06 s |
| test3_Len43 | 2.97e-06 s |
| test4_Len53 | 2.68e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_Len12 | 6.87e-05 s |
| test2_Len32 | 3.62e-05 s |
| test3_Len43 | 3.10e-05 s |
| test4_Len53 | 1.65e-04 s |

