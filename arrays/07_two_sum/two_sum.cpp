#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;


class Solution {
public:
    vector<uint16_t> twoSum(const vector<int>& nums, int& target) {
        if (!checkConstraints(nums, target)) {
            throw std::runtime_error("Constraints violated");
        }
        unordered_map<uint16_t, uint16_t> inds;
        for (uint16_t i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (inds.find(complement) != inds.end()) {
                return {inds[complement], i};
            }
            inds[nums[i]] = i;
        }
        return {};
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const vector<int>& nums, int& t) {
        int n = nums.size();
        if (n < 2 || n > pow(10, 4)) return false;
        if (t < -pow(10, 9) || t > pow(10, 9)) return false;

        for (auto& num : nums) {
            if (num < -pow(10, 9) || num > pow(10, 9)) return false;
        }
        return true;
    }
};
