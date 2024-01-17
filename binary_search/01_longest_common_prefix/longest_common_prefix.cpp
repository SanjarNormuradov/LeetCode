#include <iostream>
#include <stdexcept>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>

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
        int low = 1, high = strs.size();
        for 
        return "";
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
        string minStr =  
        return true;
    }
};
