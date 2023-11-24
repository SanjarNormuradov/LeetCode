#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (!checkConstraints(grid)) {
            throw std::runtime_error("Constraints violated");
        }
        int zeroCount = 0, startX = 0, startY = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] >= 0) zeroCount++;
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        return backtrack(grid, startX, startY, zeroCount);
    }

private:
    int backtrack(vector<vector<int>>& grid, int x, int y, int remain) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) {
            return 0;
        }
        if (grid[x][y] == 2) {
            return remain == 1 ? 1 : 0;
        }
        // Mark the square as visited -> unreachable just like obstacle
        grid[x][y] = -1;
        remain--;

        int totalPaths = backtrack(grid, x + 1, y, remain) +
                         backtrack(grid, x - 1, y, remain) +
                         backtrack(grid, x, y + 1, remain) +
                         backtrack(grid, x, y - 1, remain);

        // Mark the square as unvisited to be considered by other possible paths
        grid[x][y] = 0;
        remain++;

        return totalPaths;
    }

    // Helper function to check the constraints
    bool checkConstraints(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || m > 20) return false;
        if (n == 0 || n > 20) return false;

        for (auto& row : grid) {
            for (auto& cell : row) {
                if (cell < -1 || cell > 2) {
                    return false;
                }
            }
        }
        return true;
    }
};
