# Problem

## Statement
You are given a list of equivalent string pairs `synonyms` where `synonyms[i] = [s<sub>i<sub>, t<sub>i<sub>]` indicates that `s<sub>i<sub>` and `t<sub>i<sub>` are equivalent strings. You are also given a sentence `text`.

Return _all possible synonymous sentences **sorted lexicographically**_.


### Examples
Example 1: \
Input: synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]], text = "I am happy today but was sad yesterday" \
Output: ["I am cheerful today but was sad yesterday","I am cheerful today but was sorrow yesterday","I am happy today but was sad yesterday","I am happy today but was sorrow yesterday","I am joy today but was sad yesterday","I am joy today but was sorrow yesterday"]

Example 2: \
Input: synonyms = [["happy","joy"],["cheerful","glad"]], text = "I am happy today but was sad yesterday" \
Output: ["I am happy today but was sad yesterday","I am joy today but was sad yesterday"]


### Constraints
- `0 <= synonyms.length <= 10`
- `synonyms[i].length == 2`
- `1 <= s<sub>i<sub>.length, t<sub>i<sub>.length <= 10`
- `s<sub>i<sub> != t<sub>i<sub>`
- `text` consists of at most `10` words.
- All the pairs of `synonyms` are __unique__.
- The words of `text` are separated by single spaces.

# Solution

## Approach
__Union-Find for Grouping Synonyms__:
- Iterate through each pair of synonyms and union them, ensuring that all synonyms in a group are linked to a common representative (root).
- Time Complexity: Typically near-constant due to path compression and union by rank optimizations, usually `O(α(N))`, where `α(N)` is the inverse Ackermann function, which grows very slowly and is practically constant for most practical purposes.
__Grouping Synonyms__:
- Iterate through each pair of synonyms, find their root, and add them to the set corresponding to that root in a dictionary.
- Time Complexity: `O(N)`, where `N` is the number of synonym pairs, as each pair is processed once.
__Recursive Sentence Generation__:
- Generate all sentence combinations by recursively replacing words with their synonyms.
- Time Complexity: Potentially exponential, `O(M^L)`, where `M` is the max number of synonyms for a word, and `L` is the sentence length.
__Sorting the Results (Python Only)__:
- Sort in lexicographical order the list of generated sentences.
- Time Complexity: `O(S log S)`, where `S` is the number of sentences generated. This is the complexity of the sorting algorithm (typically Timsort in Python).


### Complexity
- __Time__: `O(M^L + S log S)`, dominated by the recursive sentence generation.
- __Memory__: `O(N + S)`, mainly for storing synonym sets `N` and recursive calls `S`.

## Test Results

### C++ Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_two_synonyms | 1.00e-04 s |
| test2_one_synonym | 4.89e-05 s |

### Python Test Times
| Test Name | Time Spent |
| --- | --- |
| test1_two_synonyms | 5.77e-05 s |
| test2_one_synonym | 3.05e-05 s |

