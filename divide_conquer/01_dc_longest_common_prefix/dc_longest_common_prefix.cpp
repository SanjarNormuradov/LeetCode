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
        return lcp(strs, 0, strs.size() - 1);
    }

private:
    bool checkConstraints(const vector<string>& strs) {
        if (strs.size() < 1 || strs.size() > 200) return false;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < 0 || strs[i].size() > 200) return false;
            for (auto& ch : strs[i]) {
                if (ch < 'A' || (ch > 'Z' && ch < 'a') || ch > 'z') return false;
            }
        }
        return true;
    }
    string lcp(vector<string>& strs, int left, int right) {
        if (left == right) {
            // conquer
            return strs[left];
        } else {
            // divide
            int mid = (left + right) / 2;
            string lcpLeft = lcp(strs, left, mid);
            string lcpRight = lcp(strs, mid + 1, right);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }
    string commonPrefix(const string& left, const string& right) {
        auto pair = mismatch(left.begin(), left.end(), right.begin(), right.end());
        int minLen = pair.first - left.begin();
        return left.substr(0, minLen);
    }
};

// int main(int argc, char **argv) {
//     Solution* solution;
//     return 0;
// }
