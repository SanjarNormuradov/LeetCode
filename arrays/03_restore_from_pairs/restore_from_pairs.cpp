#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <stdexcept>

using namespace std;


class Solution {
public:
    vector<int> restoreFromAdjacentPairs(const vector<vector<int>>& adjacentPairs) {
        if (!checkConstraints(adjacentPairs)) {
            throw std::runtime_error("Constraints violated");
        }

        unordered_map<int, vector<int>> adjacencyList;
        for (const auto& p : adjacentPairs) {
            adjacencyList[p[0]].push_back(p[1]);
            adjacencyList[p[1]].push_back(p[0]);
        }

        vector<int> nums;
        for (const auto& p : adjacencyList) {
            if (p.second.size() == 1) {
                nums.push_back(p.first);
                break;
            }
        }
        nums.push_back(adjacencyList[nums[0]][0]);

        while (nums.size() < adjacencyList.size()) {
            int last = nums.back();
            int next = (adjacencyList[last][0] != nums[nums.size() - 2]) ? adjacencyList[last][0] : adjacencyList[last][1];
            nums.push_back(next);
        }

        return nums;
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1; 

        if (n < 2 || n > pow(10, 5)) return false;

        for (int i = 0; i < n - 1; ++i) {
            if (adjacentPairs[i].size() != 2) return false;
            if (adjacentPairs[i][0] < pow(-10, 5) || adjacentPairs[i][0] > pow(10, 5)) return false;
            if (adjacentPairs[i][1] < pow(-10, 5) || adjacentPairs[i][1] > pow(10, 5)) return false;
        }

        return true;
    }
};
