# Problem

## Statement
Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`. \
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`. \

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:
- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

### Examples
Example 1: \
Input: s = "III" \
Output: 3 \
Explanation: III = 3.

Example 2: \
Input: s = "LVIII" \
Output: 58 \
Explanation: L = 50, V= 5, III = 3.

Example 3: \
Input: s = "MCMXCIV" \
Output: 1994 \
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


### Constraints
- `1 <= s.length <= 15`
- `s` contains only the characters `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.
- It is guaranteed that `s` is a valid roman numeral in the range `[1, 3999]`.

# Solution

## Approach
__Map Roman Symbols to Values__: Create a map that associates each Roman symbol with its integer value.
__Iterate through the Roman Numeral__: Go through each character of the string.
__Handle Subtraction Cases__: If a smaller value symbol is followed by a larger value symbol, subtract the smaller from the larger and add the result to the total.
__Add Regular Cases__: If a symbol is not followed by a larger symbol, simply add its value to the total.
__Return the Total__: After processing all symbols, return the total value.

### Complexity
- __Time__: `O(len(s))`, This reflects the worst case when all characters in s are non-increasing.
- __Memory__: `O(1)`, as the space used is constant (map or dict with 7 key-value pairs) and independent of the input size.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_III | 2.39e-05 s |
| test2_LVIII | 1.24e-05 s |
| test3_MCMXCIV | 1.19e-05 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_III | 1.21e-04 s |
| test2_LVIII | 3.77e-05 s |
| test3_MCMXCIV | 3.48e-05 s |

