#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <stdexcept>
#include <cstdint>

using namespace std;


class Solution {
public:
    int romanToInt(const string& s) {
        if (!checkConstraints(s)) {
            throw std::runtime_error("Constraints violated");
        }
        map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int total = 0;

        for (int i = 0; i < s.length(); i++) {
            // If the current value is less than the next value, subtract it
            if (i < s.length() - 1 && roman[s[i]] < roman[s[i + 1]]) {
                total += roman[s[i + 1]] - roman[s[i]];
                i++; // Skip the next character
            } else {
                total += roman[s[i]];
            }
        }

    return total;
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const string& s) {
        if (s.size() < 1 || s.size() > 15) return false;
        
        return true;
    }
};
