#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        if (!checkConstraints(nums, firstLen, secondLen)) {
            throw std::runtime_error("Constraints violated");
        }
        // Prefix Sum vector with additional 0 at the front
        vector<int> prefixSum(nums.size() + 1, 0);
        for (int i = 1; i < nums.size() + 1; i++) {
            prefixSum[i] += nums[i - 1] + prefixSum[i - 1];
        }
        int maxSum = 0;
        for (int l = 0; l < nums.size() + 1 - firstLen; l++) {
            int lr = l + firstLen;
            int lsum = prefixSum[lr] - prefixSum[l];
            for (int r = nums.size(); r > secondLen - 1; r--) {
                int rl = r - secondLen;
                if (!((lr > rl && lr <= r) || (l >= rl && l < r) || (rl >= l && r <= lr))) {
                    int rsum = prefixSum[r] - prefixSum[rl];
                    maxSum = max((lsum) + (rsum), maxSum);
                }
            }
        }
        return maxSum;
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const vector<int>& nums, int firstLen, int secondLen) {
        if (firstLen < 1 || firstLen > 1000 || secondLen < 1 || secondLen > 1000) return false;
        if (firstLen + secondLen < 2 || firstLen + secondLen > 1000) return false;
        int len = nums.size();
        if (firstLen + secondLen > len || len > 1000) return false;
        for (const auto& num : nums) {
            if (num < 0 || num > 1000) return false;
        }
        return true;
    }
};