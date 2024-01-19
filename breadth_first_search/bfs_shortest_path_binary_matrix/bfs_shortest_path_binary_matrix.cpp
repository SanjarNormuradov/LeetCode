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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (!checkConstraints(grid)) {
            throw std::runtime_error("Constraints violated");
        }
        return 0;
    }

private:
    bool checkConstraints(const vector<vector<int>>& grid) {
        int n = grid.size();
        if (n < 1 || n > 100) return false;
        for (int i = 0; i < n; i++) {
            int m = grid[i].size();
            if (m < 1 || m > 100) return false;
            if (!all_of(grid[i].begin(), grid[i].end(), [](int cell) {
                return cell == 0 || cell == 1;
            })) return false;
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
