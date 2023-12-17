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
        return max(_slider(nums, firstLen, secondLen), _slider(nums, secondLen, firstLen));
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
    int _slider(const vector<int>& nums, int len1, int len2) {
        int n = nums.size();
        vector<int> dp1(n, 0), dp2(n, 0);
        int sum = 0;
        // prefix sum for a window of size len1
        for (int i = 0; i < n; i++) {
            if (i < len1) { // prefix sum for a subarray of size < len1
                sum += nums[i];
                dp1[i] = sum;
            } else { // max sum of the subarray of size == len1, a window slides from left to right
                sum += nums[i] - nums[i - len1];
                dp1[i] = max(dp1[i - 1], sum);
            }
        }
        sum = 0;
        // suffix sum for a window of size len2
        for (int i = n - 1; i >= 0; i--) {
            if (i > n - 1 - len2) { // suffix sum for a subarray of size < len2
                sum += nums[i];
                dp2[i] = sum;
            } else { // max sum of the subarray of size == len2, a window slides from right to left
                sum += nums[i] - nums[i + len2];
                dp2[i] = max(dp2[i - 1], sum);
            }
        }
        int ans = 0;
        for (int i = len1 - 1; i < n - len2; i++) {
            ans = max(ans, dp1[i] + dp2[i + 1]);
        }
        return ans;
    }
};