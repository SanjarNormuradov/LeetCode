#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>

using namespace std;


class Solution {
public:
    int countPaths(const vector<vector<int>>& grid) {
        if (!checkConstraints(grid)) {
            throw std::runtime_error("Constraints violated");
        }
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> memo(m, vector<int> (n, -1));
        int max_cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (memo[i][j] == -1) {
                    max_cnt = (depthFirstSearch(grid, i, j, memo, -1) + max_cnt) % 1000000007;
                } else {
                    max_cnt = (memo[i][j] + max_cnt) % 1000000007;
                } 
            }
        }
        return max_cnt;
    }

private:
    int depthFirstSearch(const vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo, int prev) {
        if (i < 0 || i > grid.size() || j < 0 || grid[0].size() || prev > grid[i][j]) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int top    = depthFirstSearch(grid, i-1, j, memo, grid[i][j]);
        int bottom = depthFirstSearch(grid, i+1, j, memo, grid[i][j]);
        int right  = depthFirstSearch(grid, i, j+1, memo, grid[i][j]);
        int left   = depthFirstSearch(grid, i, j-1, memo, grid[i][j]);

        memo[i][j] = (1 + top + bottom + right + left) % 1000000007;
        return memo[i][j];
    }

    // Helper function to check the constraints
    bool checkConstraints(const vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0 || m > 1000) return false;

        for (const auto& row : grid) {
            if (row.size()     == 0 || row.size()     > 1000      ) return false;
            if (row.size() * m == 0 || row.size() * m > pow(10, 5)) return false;

            for (int num : row) {
                if (num < 0 || num > pow(10, 5)) return false;
            }
        }
        return true;
    }
};
