#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (!checkConstraints(numRows)) {
            throw std::runtime_error("Constraints violated");
        }
        vector<vector<int>> ans;
        vector<int> dp(1, 1);
        ans.push_back(dp);
        if (numRows > 1) {
            dp.push_back(1);
            ans.push_back(dp);
            for (int j = 1; j < numRows - 1; j++) {
                for (int i = j; i > 0; i--) {
                    dp[i] += dp[i - 1];
                }
                dp.push_back(1);
                ans.push_back(dp);
            }
        }
        return ans;
    }

private:
    bool checkConstraints(int n) {
        if (n < 1 || n > 30) return false;
        return true;
    }
};
