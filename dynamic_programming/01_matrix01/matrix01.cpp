#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {
        if (!checkConstraints(mat)) {
            throw std::runtime_error("Constraints violated");
        }
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> dist(row, vector<int> (col, INT32_MAX));
        queue<pair<int, int>> q;
        // Init as a root for BFS every cell that is 0
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // BFS
        while (!q.empty()) {
            auto id = q.front();
            q.pop();
            for (auto& dir : dirs) {
                int x = id.first + dir.first, y = id.second + dir.second;
                if (x >= 0 && x < row && y >= 0 && y < col) {
                    if (dist[x][y] > dist[id.first][id.second] + 1) {
                        dist[x][y] = dist[id.first][id.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
        return dist;
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0 || m > pow(10, 4)) return false;
        int zeroCnt = 0;
        for (const auto& row : mat) {
            if (row.size() == 0 || row.size() > pow(10, 4)) return false;
            if (row.size() * m == 0 || row.size() * m > pow(10, 4)) return false;
            for (int num : row) {
                if (num == 0) {
                    zeroCnt++;
                }
                if (num != 0 && num != 1) return false;
            }
        }
        if (!zeroCnt) return false;

        return true;
    }
};
