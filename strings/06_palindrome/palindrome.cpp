#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <cstdint>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if (!checkConstraints(x)) {
            throw std::runtime_error("Constraints violated");
        }
        if (x < 0) return false;

        int reversed = 0;
        int tmp = x;
        while (tmp != 0) {
            int digit = tmp % 10;
            reversed = reversed * 10 + digit;
            tmp = tmp / 10;
        }
        return (reversed == x);
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const int& x) {
        if (x < pow(-2, 31) || x > pow(2, 31) - 1) return false;

        return true;
    }
};
