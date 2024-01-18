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
The idea of the algorithm comes from the associative property of longest common prefix (LCP) operation. We notice that :
`LCP(S1…Sn) = LCP(LCP(S1…Sk), LCP(Sk+1…Sn))`, where `LCP(S1…Sn)` is the longest common prefix in set of strings `[S1…Sn]`, `1 < k < n`

To apply the observation above, we use divide and conquer technique, where we split the `LCP(Si…Sj)` problem into two subproblems `LCP(Si…Smid)` and `LCP(Smid+1…Sj)`, where `mid` is `\frac{i + j}{2}`​. We use their solutions `lcpLeft` and `lcpRight` to construct the solution of the main problem `LCP(Si…Sj)`. To accomplish this we compare one by one the characters of `lcpLeft` and `lcpRight` till there is no character match. The found common prefix of `lcpLeft` and `lcpRight` is the solution of the `LCP(Si…Sj)`.

### Complexity
In the worst case we have `n` equal strings with length `m` with `S = n * m`.
- __Time__: `O(S⋅log n)`. The number of levels in a binary recursion is `log⁡ n`, as each step halves the problem size. Since each level deals with all `n` strings (albeit in halves, quarters, etc.) to compare `m`-length strings. So,`O([n/2 + n/4 + ... 1] ⋅ m)` = `O([(n/2 + 1)/2 ⋅ log n] ⋅ m)` = `O(n⋅m ⋅ log n)` = `O(S⋅log n)`.
- __Memory__: `O(m⋅log n)`, There is a memory overhead since we store recursive calls in the execution stack. There are `log⁡ n` recursive calls, each store need `m` space to store the result.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_fl | 7.96e-06 s |
| test2_dogcar | 2.99e-06 s |
| test3_flower | 3.66e-06 s |
| test4_empty | 1.83e-06 s |
| test5_abc | 2.44e-06 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_fl | 3.27e-05 s |
| test2_dogcar | 1.91e-05 s |
| test3_flower | 1.80e-04 s |
| test4_empty | 1.84e-05 s |
| test5_abc | 8.70e-05 s |

