from sortedcontainers import SortedDict


class Solution:
    def sort_vowels(self, s: str) -> str:
        if not self._check_constraints(s):
            raise ValueError("Constraints violated")

        t = list(s)
        vowel_idx = []
        vowel_qnt = SortedDict()
        for i in range(len(s)):
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') or (s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'):
                vowel_idx.append(i)
                vowel_qnt[s[i]] += 1

        if len(vowel_idx) != 0:
            id = 0
            for key, value in vowel_qnt.items():
                for i in range(value):
                    t[vowel_idx[id]] = key
                    id += 1
            else:
                return s
        return ''.join(t)

    def _check_constraints(self, s: str) -> bool:
        n = len(s)
        if n < 1 or n > 10**5:
            return False

        A_dec = 65
        a_dec = 97
        alpha_len = 26
        for c in s:
            ascii = int(c)
            if not ((ascii >= A_dec and ascii < A_dec + alpha_len) or (ascii >= a_dec and ascii < a_dec + alpha_len)):
                return False

        return True
