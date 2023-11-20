#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        if (!checkConstraints(m, n)) {
            throw std::runtime_error("Constraints violated");
        }
        // dp[i][j] = num paths to get to (i, j) from (0, 0)
        //          = dp[i - 1][j] (move down) + dp[i][j - 1] (move right)
        // But we need only one container to store # paths as it can execute ONLY one action (move down/right) at a time
        vector<int> dp(n, 0);
        dp[0] = 1; // Exactly only one path to get from (0, 0) to (0, 0)

        for (int i = 0; i < m; i++) {
            dp[0] = 1; // Exactly only one path to get from (0, 0) to (i, 0) by moving downwards
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(int m, int n) {
        if (m == 0 || m > 100) return false;
        if (n == 0 || n > 100) return false;

        return true;
    }
};
