#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstdint>
#include <array>
#include <string>

using namespace std;


class Solution {
public:
    bool canPermutePalindrome(string s) {
        if (!checkConstraints(s)) {
            throw std::runtime_error("Constraints violated");
        }
        array<uint8_t, 26> _map{};

        int odd_cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            _map[s[i] - 'a']++;
            if (_map[s[i] - 'a'] % 2 == 0) {
                odd_cnt--;
            } else odd_cnt++;
            cout << "diff: " << s[i] - 'a' << endl;
            cout << "map: " << _map[s[i] - 'a'] << endl;
            cout << "odd_cnt: " << odd_cnt << endl;
        }
        // the number of characters with odd number of occurrences can't exceed 1
        // (1 in case of odd s_length and 0 in case of even s_length).
        return odd_cnt <= 1;
    }

private:
    bool checkConstraints(const string& s) {
        if (s.size() < 1 || s.size() > 5000) return false;
        for (const char& ch : s) {
            int ascii = static_cast<int>(ch);
            if (!(ascii >= static_cast<int>('a') && ascii < static_cast<int>('a') + 26)) return false;
        }
        return true;
    }
};