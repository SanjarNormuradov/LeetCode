#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (!checkConstraints(cost)) {
            throw std::runtime_error("Constraints violated");
        }
        int n = cost.size();
        // Break optimal solution to the problem into optimal solutions to subproblems
        // 1st method: backward memoization
        // vector<int> memo(n + 1, -1);
        // return backward_memo(0, n, memo, cost);
        // 2nd method: forward dynamic programming 
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = i < n ? cost[i] : 0;
            dp[i] += min(dp[i - 1], dp[i - 2]);
        }
        return dp[n];
    }

private:
    bool checkConstraints(vector<int>& cost) {
        if (cost.size() < 2 || cost.size() > 1000) return false;
        for (int c : cost) {
            if (c < 0 || c > 999) return false;
        }
        return true;
    }
    int backward_memo(int i, int n, vector<int>& memo, vector<int> cost) {
        if (i > n) return 0; // overshoot
        if (memo[i] > -1) return memo[i]; // computed before
        memo[i] = i > 0 ? cost[i - 1] : 0;
        memo[i] += min(backward_memo(i + 1, n, memo, cost), backward_memo(i + 2, n, memo, cost)); // forward step of size 1 and 2
        return memo[i];
    }
};
