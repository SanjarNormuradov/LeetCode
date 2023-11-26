# Problem

## Statement
A string can be __abbreviated__ by replacing any number of __non-adjacent__, __non-empty__ substrings with their lengths. The lengths __should not__ have leading zeros.

For example, a string such as `"substitution"` could be abbreviated as (but not limited to):
- `"s10n"` ("s _ubstitutio_ n")
- `"sub4u4"` ("sub _stit_ u _tion_")
- `"12"` ("substitution")
- `"su3i1u2on"` ("su _bst_ i _t_ u _ti_ on")
- `"substitution"` (no substrings replaced)

The following are __not valid__ abbreviations:
- `"s55n"` ("s _ubsti_ _tutio_ n", the replaced substrings are adjacent)
- `"s010n"` (has leading zeros)
- `"s0ubstitution"` (replaces an empty substring)

Given a string `word` and an abbreviation `abbr`, return _whether the string matches the given abbreviation_.

A __substring__ is a contiguous __non-empty__ sequence of characters within a string.


### Examples
Example 1: \
Input: word = "internationalization", abbr = "i12iz4n" \
Output: true \
Explanation: The word "internationalization" can be abbreviated as "i12iz4n" ("i nternational iz atio n").

Example 2: \
Input: word = "apple", abbr = "a2e" \
Output: false \
Explanation: The word "apple" cannot be abbreviated as "a2e".

Example 3: \
Input: word = "hi", abbr = "hi1" \
Output: false \
Explanation: The word "hi" cannot be abbreviated as "hi1".

Example 4: \
Input: word = "hi", abbr = "1" \
Output: false \
Explanation: The word "hi" cannot be abbreviated as "1".

Example 5: \
Input: word = "a", abbr = "2" \
Output: false \
Explanation: The word "a" cannot be abbreviated as "2".


### Constraints
- `1 <= word.length <= 20`
- `word` consists of only lowercase English letters.
- `1 <= abbr.length <= 20`
- `abbr` consists of lowercase English letters and digits.
- All the integers in `abbr` will fit in a 32-bit integer.

# Solution

## Approach
__Initialize Variables__:
- `cnt_id` is initialized to `-1`, and tracks the current position in `word`
- `int_ch` is initialized to `-1`, and accumulates an int number in the current part of `abbr`
__Iterate through Abbreviation__:
- If the character is a digit (0-9):
  - Check for leading zeros. If found, return `False`.
  - Update `int_ch` to accumulate the numeric value.
  - Check if the accumulated number exceeds the length of `word`. If so, return `False`.
- If the character is an English letter:
  - Update `cnt_id` by adding `int_ch` (if `int_ch` is not `-1`) and then increment `cnt_id`.
  - Compare the character at `cnt_id` in word with the current character in `abbr`. If they don't match, return `False`.
__Final Check__:
- After the loop, update `cnt_id` for the last numeric part in `abbr` (if any).
- Check if `cnt_id` equals `len(word) - 1`. If not, return `False`.

### Complexity
- __Time__: `O(len(abbr))`, iterate through `abbr`
- __Memory__: `O(1)`, fixed amount of memory for cnt_id/int_ch.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_i12iz4n | 6.27e-06 s |
| test2_a2e | 2.18e-06 s |
| test3_a | 1.69e-06 s |
| test4_s10n | 2.30e-06 s |
| test5_sub4u4 | 2.27e-06 s |
| test6_12 | 2.02e-06 s |
| test7_su3i1u2on | 2.30e-06 s |
| test8_substitution | 2.42e-06 s |
| test9_s55n | 2.34e-06 s |
| test10_s010n | 1.86e-06 s |
| test11_s0ubstitution | 1.84e-06 s |
| test12_hi1 | 1.74e-06 s |
| test13_1 | 1.57e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test10_s010n | 3.19e-05 s |
| test11_s0ubstitution | 1.53e-05 s |
| test12_hi1 | 1.24e-05 s |
| test13_1 | 1.12e-05 s |
| test1_i12iz4n | 1.50e-05 s |
| test2_a2e | 1.14e-05 s |
| test3_a | 1.03e-05 s |
| test4_s10n | 1.17e-05 s |
| test5_sub4u4 | 1.19e-05 s |
| test6_12 | 1.07e-05 s |
| test8_substitution | 1.31e-05 s |
| test9_s55n | 1.12e-05 s |

