#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>

using namespace std;


class Solution {
public:
    int longestIncreasingPath(const vector<vector<int>>& matrix) {
        if (!checkConstraints(matrix)) {
            throw std::runtime_error("Constraints violated");
        }
        m = matrix.size();
        n = matrix[0].size();

        path.resize(m);
        for (auto& row : path) {
            row.assign(n, 0);
        }
        int max_path = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max_path = max(max_path, depth_search_first(i, j, matrix));
            }
        }
        return max_path;
    }

private:
    vector<vector<int>> path;
    int m, n;

    int depth_search_first(int i, int j, const vector<vector<int>>& mat) {
        if (path[i][j] > 0) return path[i][j];
        vector<pair<int, int>> steps = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto& step : steps) {
            int x = i + step.first;
            int y = j + step.second;
            if ((x >= 0 && x < m) && (y >= 0 && y < n) && (mat[x][y] > mat[i][j])) {
                path[i][j] = max(path[i][j], depth_search_first(x, y, mat));
            }
        }
        return ++path[i][j];
    }

    // Helper function to check the constraints
    bool checkConstraints(const vector<vector<int>>& mat) {
        if (mat.size() == 0 || mat.size() > 200) return false;

        for (const auto& row : mat) {
            if (row.size() == 0 || row.size() > 200) return false;

            for (int num : row) {
                if (num < 0 || num > pow(2, 32) - 1) return false;
            }
        }
        return true;
    }
};
