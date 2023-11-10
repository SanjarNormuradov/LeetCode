#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;


class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        if (!checkConstraints(prices)) {
            throw std::runtime_error("Constraints violated");
        }
        
        int minPrice = pow(10, 4);
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const vector<int>& prices) {
        int n = prices.size() + 1; 
        if (n < 1 || n > pow(10, 5)) return false;

        for (auto& price : prices) {
            if (price < 0 || price > pow(10, 4)) return false;
        }

        return true;
    }
};
