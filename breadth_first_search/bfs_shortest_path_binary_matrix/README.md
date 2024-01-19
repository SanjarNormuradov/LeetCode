# Problem

## Statement
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

### Examples
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2: \
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Example 3: \
Input: strs = ["flower","flower","flower","flower"]
Output: "flower"

Example 4: \
Input: strs = [""]
Output: ""

Example 5: \
Input: strs = ["abca","abc"]
Output: "abc"

### Constraints
- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`


# Solution

## Approach
The idea is to apply binary search method to find the string with maximum value minLen, which is minimum string length and the maximum possible common prefix of all of the strings. The algorithm search space is the interval (0…minLen). Each time search space is divided in two equal parts, one of them is discarded, because it is sure that it doesn't contain the solution.\
There are two possible cases:
- `S[1...mid]` is not a common string. This means that for each `j > i` `S[1..j]` is not a common string and we discard the second half of the search space.
- `S[1...mid]` is common string. This means that for for each `i < j` `S[1..i]` is a common string and we discard the first half of the search space, because we try to find longer common prefix.


### Complexity
In the worst case we have `n` equal strings with length `m` with `S = n⋅m`.
- __Time__: `O(S⋅log m)`, the algorithm makes `log m` iterations with `S` comparisons.
- __Memory__: `O(1)`, constant extra space.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_fl | 9.20e-06 s |
| test2_dogcar | 2.97e-06 s |
| test3_flower | 3.68e-06 s |
| test4_empty | 1.82e-06 s |
| test5_abc | 2.74e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_fl | 4.67e-05 s |
| test2_dogcar | 1.86e-05 s |
| test3_flower | 1.72e-05 s |
| test4_empty | 1.22e-05 s |
| test5_abc | 1.38e-05 s |

