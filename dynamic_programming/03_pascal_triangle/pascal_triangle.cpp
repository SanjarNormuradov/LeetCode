#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int n) {
        if (!checkConstraints(n)) {
            throw std::runtime_error("Constraints violated");
        }
        vector<vector<int>> ans;
        vector<int> dp(1, 1);
        ans.push_back(dp);
        if (n > 1) {
            dp.push_back(1);
            ans.push_back(dp);
        }
        if (n > 2) {
            for (int j = 2; j < n; j++) {
                for (int i = j - 1; i > 0; i--) {
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
