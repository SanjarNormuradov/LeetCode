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
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        // Fill the first row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }
        // Fill the first column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }
        // Fill the rest of the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }

        return dp[m - 1][n - 1];
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
