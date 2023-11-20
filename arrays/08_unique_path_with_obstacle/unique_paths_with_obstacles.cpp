#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
        if (!checkConstraints(obstacleGrid)) {
            throw std::runtime_error("Constraints violated");
        }
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        // dp[i][j] = num paths to get to (i, j) from (0, 0)
        //          = dp[i - 1][j] (move down) + dp[i][j - 1] (move right)
        // But we need only one container to store # paths as it can execute ONLY one action (move down/right) at a time
        vector<int> dp(col, 0);
        dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;

        for (int i = 0; i < row; i++) {
            if (obstacleGrid[i][0]) {
                dp[0] = 0;
            }
            for (int j = 1; j < col; j++) {
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                } else {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[col - 1];
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0 || m > 100) return false;

        for (const auto& row : grid) {
            if (row.size() == 0 || row.size() > 100) return false;

            for (int num : row) {
                if (num != 0 && num != 1) return false;
            }
        }
        return true;
    }
};
