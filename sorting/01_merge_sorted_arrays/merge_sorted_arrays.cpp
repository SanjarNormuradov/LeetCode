#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!checkConstraints(nums1, m, nums2, n)) {
            throw std::runtime_error("Constraints violated");
        }
        int p1 = m - 1;
        int p2 = n - 1;
        for (int p = m + n - 1; p > -1; p--) {
            if (p2 < 0) break;
            if ((p1 >= 0) && (nums1[p1] > nums2[p2])) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
        }
    }

private:
    bool checkConstraints(vector<int> nums1, int m, vector<int> nums2, int n) {
        if (nums1.size() != m + n) return false;
        if (nums2.size() != n) return false;
        if (n < 0 || n > 200 || m < 0 || m > 200) return false;
        if ((m + n) < 1 || (m + n) > 200) return false;
        for (int i = 0; i < m; i++) {
            if (nums1[i] < -pow(10, 9) || nums1[i] > pow(10, 9)) return false;
        }
        for (int j = 0; j < n; j++) {
            if (nums2[j] < -pow(10, 9) || nums2[j] > pow(10, 9)) return false;
        }
        return true;
    }
};
