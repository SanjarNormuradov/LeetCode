#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (!checkConstraints(rowIndex)) {
            throw std::runtime_error("Constraints violated");
        }
        vector<int> dp(1, 1);
        if (rowIndex > 0) {
            dp.push_back(1);
            for (int j = 1; j < rowIndex; j++) {
                for (int i = j; i > 0; i--) {
                    dp[i] += dp[i - 1];
                }
                dp.push_back(1);
            }
        }
        return dp;
    }

private:
    bool checkConstraints(int n) {
        if (n < 0 || n > 33) return false;
        return true;
    }
};
