#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if (!checkConstraints(n)) {
            throw std::runtime_error("Constraints violated");
        }
        // Break optimal solution to the problem into optimal solutions to subproblems
        // 1st method: backward memoization
        // vector<int> memo(n + 1, 0);
        // return backward_memo(0, n, memo);
        // 2nd method: forward dynamic programming 
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        if (n > 1) {
            dp[2] = 2;
            for (int i = 3; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        return dp[n];
    }

private:
    bool checkConstraints(int n) {
        if (n < 1 || n > 45) return false;
        return true;
    }
    int backward_memo(int i, int n, vector<int> memo) {
        if (i > n) return 0; // overshoot
        else if (i == n) return 1; // reached the end
        if (memo[i] > 0) return memo[i]; // computed before
        memo[i] = backward_memo(i + 1, n, memo) + backward_memo(i + 2, n, memo); // forward step of size 1 and 2
        return memo[i];
    }
};

