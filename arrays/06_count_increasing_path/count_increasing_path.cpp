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
        m = grid.size();
        n = grid[0].size();

        memo.resize(m);
        for (auto& row : memo) {
            row.assign(n, -1);
        }
        int max_cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max_cnt = depthFirstSearch(i, j, grid) + max_cnt;
                max_cnt = max_cnt % MOD;
            }
        }
        return max_cnt;
    }

private:
    vector<vector<int>> memo;
    int m, n;
    long long MOD = pow(10, 9) + 7;

    int depthFirstSearch(int i, int j, const vector<vector<int>>& grid) {
        if (memo[i][j] != -1) return memo[i][j];

        int num_paths = 1; // Start with a path in the current cell
        vector<pair<int, int>> steps = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto& step : steps) {
            int x = i + step.first;
            int y = j + step.second;
            if ((x >= 0 && x < m) && (y >= 0 && y < n) && (grid[x][y] > grid[i][j])) {
                num_paths = depthFirstSearch(x, y, grid) + num_paths;
                num_paths = num_paths % MOD;
            }
        }
        memo[i][j] = num_paths;
        return memo[i][j];
    }

    // Helper function to check the constraints
    bool checkConstraints(const vector<vector<int>>& grid) {
        m = grid.size();
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
