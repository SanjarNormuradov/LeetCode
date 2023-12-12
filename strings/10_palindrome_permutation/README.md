# Problem

## Statement
Given a string `s`, return `true` _if a permutation of the string could form a palindrome_ and `false` otherwise.

### Examples
Example 1: \
Input: s = "code" \
Output: false

Example 2: \
Input: s = "aab" \
Output: true

Example 3: \
Input: s = "carerac" \
Output: true

### Constraints
- `1 <= s.lenght <= 5000`
- `s` consists of only lowercase English letters.

# Solution

## Approach
To determine if a string's characters can be permuted to form a palindrome:
- For even-length strings, every character must occur an even number of times.
- For odd-length strings, one character can occur an odd number of times, while the rest must occur an even number of times.
This rule is based on the symmetry required for a palindrome, where characters must pair up, with at most one unpaired character in the center for odd-length strings.

### Complexity
- __Time__: `O(n)`, we traverse over the string `s` of length `n` once only.
- __Memory__: `O(1)`, a `map` of constant size (26) for lowercase English letters is used.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_code | 1.95e-05 s |
| test2_aab | 9.07e-06 s |
| test3_cerarec | 1.88e-05 s |
| test1_aabb | 2.36e-05 s |
| test2_aabbc | 8.51e-06 s |
| test3_abc | 2.39e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_code | 2.91e-05 s |
| test2_aab | 1.57e-05 s |
| test3_cerarec | 1.29e-05 s |

