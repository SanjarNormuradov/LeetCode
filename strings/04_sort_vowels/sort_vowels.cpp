#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <stdexcept>

using namespace std;


class Solution {
public:
    string sortVowels(const string& s) {
        if (!checkConstraints(s)) {
            throw std::runtime_error("Constraints violated");
        }

        string t(s);
        vector<int> vowel_idx;
        map<char, int> vowel_qnt;

        for (int i = 0; i < s.size(); i++) {
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') || 
                (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')) {
                vowel_idx.push_back(i);
                vowel_qnt[s[i]]++;
            }
        }
        if (vowel_idx.size() != 0) {
            int id = 0;
            for (auto& p : vowel_qnt) {
                for (int i = 0; i < p.second; i++) {
                    t[vowel_idx[id]] = p.first;
                    id++;
                }
            }
        } else {
            return s;
        }
        return t;
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const string& s) {
        if (s.size() < 1 || s.size() > pow(10, 5)) return false;

        int A_dec = 65;
        int a_dec = 97;
        int alpha_len = 26;
        for (const char& ch : s) {
            int ascii = static_cast<int>(ch);
            if (!((ascii >= A_dec && ascii < A_dec + alpha_len) || (ascii >= a_dec && ascii < a_dec + alpha_len))) {
                return false;
            }
        }
        return true;
    }
};
