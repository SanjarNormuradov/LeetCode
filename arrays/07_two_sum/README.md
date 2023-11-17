# Problem

## Statement
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to target.

You may assume that each input would have _exactly one solution_, and you may not use the _same_ element twice.

You can return the answer in any order.

### Examples
Example 1:\
Input: nums = [2,7,11,15], target = 9\
Output: [0,1]\
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:\
Input: nums = [3,2,4], target = 6\
Output: [1,2]

Example 3:\
Input: nums = [3,3], target = 6\
Output: [0,1]

### Constraints
- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`

# Solution

## Approach
To solve the problem of finding two numbers in an array that add up to a given target, a hash table (unordered_map, dictionary) is used for efficient lookups. The algorithm iterates through the array, calculating the complement of each number by subtracting it from the target. It then checks if this complement already exists in the hash table. If it does, the indices of the current number and its complement are returned as the solution. If not, the current number and its index are stored in the hash table for future reference. This approach ensures that each element is checked only once, leading to an efficient solution.

### Complexity
- __Time__: O(n). The algorithm iterates through the array once. The time complexity for each lookup and insertion operation in the hash table is O(1).
- __Memory__: O(n). In the worst case, the hash table may store an entry for each element in the array.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_2_7_11_15 | 2.96e-05 s |
| test2_3_2_4 | 6.10e-06 s |
| test3_3_3 | 4.85e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_2_7_11_15 | 1.04e-04 s |
| test2_3_2_4 | 3.48e-05 s |
| test3_3_3 | 2.74e-05 s |
