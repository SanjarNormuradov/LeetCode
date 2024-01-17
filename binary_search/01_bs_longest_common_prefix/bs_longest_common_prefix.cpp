#include <iostream>
#include <stdexcept>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!checkConstraints(strs)) {
            throw std::runtime_error("Constraints violated");
        }
        int minLen = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            minLen = min(static_cast<int>(strs[i].size()), minLen);
        }
        if (all_of(strs.begin(), strs.end(), [&minLen](const string& str) {
            return minLen == str.size();
        })) {
            if (all_of(strs.begin() + 1, strs.end(), [&strs](const string& str) {
                return strs[0].find(str, 0) == 0;
            })) return strs[0];
        }
        int low = 1, high = strs.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommonPrefix(strs, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return strs[0].substr(0, (low + high) / 2);
    }

private:
    bool checkConstraints(const vector<string>& strs) {
        if (strs.size() < 1 || strs.size() > 200) return false;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < 0 || strs[i].size() > 200) return false;
        }
        return true;
    }
    bool isCommonPrefix(const vector<string>& strs, int len) {
        string minStr = strs[0].substr(0, len);
        if (!all_of(strs.begin() + 1, strs.end(), [&minStr](const string& str) {
            return str.find(minStr, 0) == 0;
        })) return false;
        return true;
    }
};
