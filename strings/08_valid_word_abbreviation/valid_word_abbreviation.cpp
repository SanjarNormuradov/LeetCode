#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <cstdint>

using namespace std;


class Solution {
public:
    bool validWordAbbreviation(const string& word, const string& abbr) {
        if (!checkConstraints(word, abbr)) {
            throw std::runtime_error("Constraints violated");
        }
        int cnt_id = -1;
        int int_ch = -1;

        for (int i = 0; i < abbr.size(); ++i) {
            int ascii = static_cast<int>(abbr[i]);
            if (ascii >= 48 && ascii <= 57) {
                // If there is a leading 0 anywhere in 'abbr', return false
                if (int_ch == -1 && (ascii - 48) == 0) return false;
                int_ch *= int_ch == -1 ? 0 : 10;
                int_ch += ascii - 48;
                // If a number in 'abbr' is greater than the length of 'word', return false
                if (int_ch > word.size()) return false;
            } else {
                cnt_id += int_ch == -1 ? 0 : int_ch;
                int_ch = -1;
                cnt_id++;
                if (word[cnt_id] != abbr[i]) return false;
            }
            if (i == abbr.size() - 1) {
                cnt_id += int_ch == -1 ? 0 : int_ch;
                if (cnt_id != word.size() - 1) return false;
            }  
        }
    return true;
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const string& w, const string& a) {
        if (w.size() < 1 || w.size() > 20) return false;
        if (a.size() < 1 || a.size() > 20) return false;

        for (auto& ch : w) {
            int ascii = static_cast<int>(ch);
            if (ch < 97 || ch > 122) {
                return false;
            }
        }
        int _int = 0;
        for (auto& ch : a) {
            int ascii = static_cast<int>(ch);
            if (!((ascii >= 97 && ascii <= 122) || (ascii >= 48 && ascii <= 57))) {
                return false;
            } else {
                if (ascii >= 48 && ascii <= 57) {
                    _int *= 10;
                    _int += ascii;
                    if (_int > INT32_MAX) {
                        return false;
                    }
                } else {
                    if (_int > INT32_MAX) {
                        return false;
                    }
                    _int = 0;
                }
            }
        }
        return true;
    }
};
