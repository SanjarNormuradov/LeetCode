#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <stdexcept>

using namespace std;


class Solution {
public:
    string getHint(const string& secret, string guess) {
        if (!checkConstraints(secret, guess)) {
            throw std::runtime_error("Constraints violated");
        }
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> digit_freq;
        // First pass to find bulls
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                guess[i] = '#';  // Mark this position as visited
            } else {
                digit_freq[secret[i]]++;
            }
        }
        // Second pass to find cows
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] != '#' && digit_freq.find(guess[i]) != digit_freq.end() && digit_freq[guess[i]] != 0) {
                cows++;
                digit_freq[guess[i]]--;  // Decrease the count of matched digits
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const string& s, const string& g) {
        if (s.size() < 1 || s.size() > pow(10, 3)) return false;
        if (g.size() < 1 || g.size() > pow(10, 3)) return false;
        if (g.size() != s.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            int s_digit = s[i] - '0';
            int g_digit = g[i] - '0';
            if (!((s_digit >= 0 && s_digit <= 9) && (g_digit >= 0 && g_digit <= 9))) {
                return false;
            }
        }
        return true;
    }
};
