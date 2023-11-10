#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stdexcept>

using namespace std;


class Solution {
public:
    int minNumberOfFrogs(const string& croakOfFrogs) {
        if (!checkConstraints(croakOfFrogs)) {
            throw std::runtime_error("Constraints violated");
        }

        vector<int> cnts(5, 0);
        int maxFrogs, curFrogs = 0;

        for (auto& ch : croakOfFrogs) {
            if (ch == 'c') {
                cnts[0]++;
                curFrogs++;
                maxFrogs = max(maxFrogs, curFrogs);
            } else {
                if (ch == 'r') {
                    if (cnts[0] <= cnts[1]) return -1;
                    cnts[1]++;
                } else if (ch == 'o') {
                    if (cnts[1] <= cnts[2]) return -1;
                    cnts[2]++;
                } else if (ch == 'a') {
                    if (cnts[2] <= cnts[3]) return -1;
                    cnts[3]++;
                } else if (ch == 'k') {
                    if (cnts[3] <= cnts[4]) return -1;
                    cnts[4]++;
                    curFrogs--;
                }
            }
        }
        int maxCnt = cnts[0];
        // Check for complete 'croak's
        for (int i = 1; i < 5; i++) {
            if (cnts[i] != maxCnt) return -1;
        }

        return maxFrogs;
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const string& croakOfFrogs) {
        if (croakOfFrogs.size() < 1 || croakOfFrogs.size() > pow(10, 5)) return false;

        vector<char> legits = {'c', 'r', 'o', 'a', 'k'};
        for (const char& ch : croakOfFrogs) {
            if (find(legits.begin(), legits.end(), ch) == legits.end()) return false;
        }

        return true;
    }
};
