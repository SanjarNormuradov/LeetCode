# Problem

## Statement
Given a string `s`, return _all the palindromic permutations (without duplicates)_ of it.
You may return the answer in __any order__. If `s` has no palindromic permutation, return an empty list.

### Examples
Example 1: \
Input: s = "aabb" \
Output: ["abba","baab"]

Example 2: \
Input: s = "aabbc" \
Output: ["abcba","bacab"]

Example 3: \
Input: s = "abc" \
Output: []

### Constraints
- `1 <= s.lenght <= 16`
- `s` consists of only lowercase English letters.

# Solution

## Approach
To generate palindromes of the given string `s`, we need to follow the next steps:
- __Palindrome Permutation Feasibility:__ Checks if a palindromic permutation is possible by ensuring at most one character has an odd count.
- __Preparing for Permutations:__ Initializes a vector with half the occurrences of each character, storing any character with an odd count separately.
- __Generating Permutations:__ Recursively generates permutations of the half-string, concatenates them with the middle character (if any), and their mirror image to form palindromes.

### Complexity
- __Time__: `O((n/2)!)` - Factorial time, due to permutation generation.
- __Memory__: `O(n * (n/2)!)` - Primarily due to the storage of all unique permutations.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_aabb | 2.54e-05 s |
| test2_aabbc | 9.99e-06 s |
| test3_abc | 2.85e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_aabb | 3.77e-05 s |
| test2_aabbc | 2.72e-05 s |
| test3_abc | 1.31e-05 s |

