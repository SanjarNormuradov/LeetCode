#include <iostream>
#include <stdexcept>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (!checkConstraints(grid)) {
            throw std::runtime_error("Constraints violated");
        }
        int row = grid.size(), col = grid[0].size();
        if (grid[0][0] == 1 || grid[row-1][col-1] == 1) return -1;
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        // 1st method: distance grid & index queue
        // vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        // queue<pair<int, int>> q;
        // dist[0][0] = 1;
        // q.push({0, 0});
        // while (!q.empty()) {
        //     auto id = q.front();
        //     q.pop();
        //     for (auto dir : dirs) {
        //         int x = id.first + dir.first, y = id.second + dir.second;
        //         if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 0) {
        //             if (dist[id.first][id.second] + 1 < dist[x][y]) {
        //                 dist[x][y] = dist[id.first][id.second] + 1;
        //                 if (x == row - 1 && y == col - 1) return dist[x][y];
        //                 q.push({x, y});
        //             }
        //         }
        //     }
        // }
        // return -1;

        // 2nd method: visited set & index+distance queue
        unordered_set<int> visited;
        queue<tuple<int, int, int>> que;
        visited.insert(0 * col + 0);
        que.push({0, 0, 1});
        while (!que.empty()) {
            auto [i, j, dist] = que.front();
            que.pop();
            if (i == row - 1 && j == col - 1) return dist;
            for (auto dir : dirs) {
                int x = i + dir.first, y = j + dir.second;
                if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 0) {
                    if (visited.find(x * col + y) == visited.end()) {
                        visited.insert(x * col + y);
                        que.push({x, y, dist + 1});
                    }
                }
            }
        }
        return -1;
    }

private:
    bool checkConstraints(const vector<vector<int>>& grid) {
        int n = grid.size();
        if (n < 1 || n > 100) return false;
        for (int i = 0; i < n; i++) {
            int m = grid[i].size();
            if (m < 1 || m > 100) return false;
            if (!all_of(grid[i].begin(), grid[i].end(), [](int cell) {
                return cell == 0 || cell == 1;
            })) return false;
        }
        return true;
    }
};

int main() {
    Solution* solution;
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    cout << solution->shortestPathBinaryMatrix(grid) << endl;
    grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << solution->shortestPathBinaryMatrix(grid) << endl;
    grid = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << solution->shortestPathBinaryMatrix(grid) << endl;
    return 0;
}
