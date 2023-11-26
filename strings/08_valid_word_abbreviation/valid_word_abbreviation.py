class Solution:
    def valid_word_abbreviation(self, word: str, abbr: str) -> bool:
        if not self._check_constraints(word, abbr):
            raise ValueError("Constraints violated")

        cnt_id = -1
        int_ch = -1

        for i in range(len(abbr)):
            ascii = ord(abbr[i])
            if (ascii >= 48 and ascii <= 57):
                # If there is a leading 0 anywhere in 'abbr', return False
                if int_ch == -1 and (ascii - 48) == 0:
                    return False
                int_ch *= 0 if int_ch == -1 else 10
                int_ch += ascii - 48
                # If a number in 'abbr' is greater than the length of 'word', return False
                if int_ch > len(word):
                    return False
            else:
                cnt_id += 0 if int_ch == -1 else int_ch
                int_ch = -1
                cnt_id += 1
                if word[cnt_id] != abbr[i]:
                    return False
            if i == len(abbr) - 1:
                cnt_id += 0 if int_ch == -1 else int_ch
                if cnt_id != len(word) - 1:
                    return False

        return True

    # Helper function to check the constraints
    def _check_constraints(self, w: str, a: str) -> bool:
        if len(w) < 1 or len(w) > 20:
            return False
        if len(a) < 1 or len(a) > 20:
            return False
        _int = 0
        for ch in a:
            ascii = ord(ch)
            if not ((ascii >= 97 and ascii <= 122) or (ascii >= 48 and ascii <= 57)):
                return False
            else:
                if (ascii >= 48 and ascii <= 57):
                    _int *= 10
                    _int += ascii
                    if _int > 2**16 - 1:
                        return False
                else:
                    if _int > 2**16 - 1:
                        return False
                    _int = 0

        return True
