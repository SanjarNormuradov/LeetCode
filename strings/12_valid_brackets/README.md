# Problem

## Statement
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.


### Examples
Example 1: \
Input: s = "()" \
Output: true

Example 2: \
Input: s = "()[]{}" \
Output: true

Example 3: \
Input: s = "(]" \
Output: false

### Constraints
- `1 <= s.lenght <= 10^4`
- `s` consists of parentheses only `'()[]{}'`.

# Solution

## Approach
Follow the next steps:
- __Check string length:__ If string length is odd, no way there could be valid parentheses.
- __Keep opening brackets in stack:__ Iterate through the string, and push character into stack if it's an opening bracket.
- __Handle closing bracket and empty stack:__ If the stack is empty and the current character is a closing bracket, return False.
- __Compare closing bracket with the top element of the stack__: If the stack is not empty and the current character is a closing bracket, compare it with the top element of the stack. If they form a valid pair, pop the top element of the stack. Otherwise, return False.
- __Final check for empty stack__: If the string contains valid brackets, the stack should be empty at the end. Otherwise, return False.

### Complexity
- __Time__: `O(n)` - iterate through each element of the string if it contains valid bracket pairs.
- __Memory__: `O(n)` - in worst case scenario when all brackets are opening, the length of the stack == input string length.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_parentheses | 2.86e-05 s |
| test2_trio | 2.87e-06 s |
| test3_roundCurly | 2.18e-06 s |
| test4_doubleRound | 2.20e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_parentheses | 2.60e-05 s |
| test2_trio | 1.50e-05 s |
| test3_roundCurly | 1.10e-05 s |
| test4_doubleRound | 1.03e-05 s |

