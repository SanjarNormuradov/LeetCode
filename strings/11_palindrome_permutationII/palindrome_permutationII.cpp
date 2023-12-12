#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstdint>
#include <array>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<string> generatePalindromes(string s) {
        if (!checkConstraints(s)) {
            throw std::runtime_error("Constraints violated");
        }
        array<uint8_t, 26> _map{};
        vector<char> st(s.size() / 2);
        if (!canPermutePalindrome(s, _map)) {
            return vector<string>();
        }
        char ch = 0;
        int k = 0;
        for (int i = 0; i < 26; i++) {
            if (_map[i] % 2 == 1) {
                ch = static_cast<char>(i + 'a');
            }
            for (int j = 0; j < _map[i] / 2; j++) {
                st[k++] = static_cast<char>(i + 'a');
            }
        }
        permute(st, 0, ch);
        return vector<string>(_set.begin(), _set.end());
    }

private:
    unordered_set<string> _set;
    bool checkConstraints(const string& s) {
        if (s.size() < 1 || s.size() > 16) return false;
        for (const char& ch : s) {
            int ascii = static_cast<int>(ch);
            if (!(ascii >= static_cast<int>('a') && ascii < static_cast<int>('a') + 26)) return false;
        }
        return true;
    }
    bool canPermutePalindrome(string& s, array<uint8_t, 26>& _map) {
        int odd_cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            _map[s[i] - 'a']++;
            if (_map[s[i] - 'a'] % 2 == 0) {
                odd_cnt--;
            } else odd_cnt++;
        }
        // the number of characters with odd number of occurrences can't exceed 1
        // (1 in case of odd s_length and 0 in case of even s_length).
        return odd_cnt <= 1;
    }
    void permute(vector<char>& st, int l, char ch) {
        if (l == st.size()) {
            _set.insert(string(st.begin(), st.end()) + (ch == 0 ? "" : string(1, ch)) + string(st.rbegin(), st.rend()));
        }
        for (int r = l; r < st.size(); r++) {
            if (st[r] != st[l] || r == l) { 
                // filter duplicates which might arise when swaping two same characters, except the same element chosen twice
                swap(st[l], st[r]);
                permute(st, l + 1, ch);
                swap(st[l], st[r]);
            }
        }
    }
};