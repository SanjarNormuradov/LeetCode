#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdint>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int fib(int n) {
        if (!checkConstraints(n)) {
            throw std::runtime_error("Constraints violated");
        }
        // 1st method: bottom-up
        if (n <= 1) return n;
        vector<int> cache(n + 1, 0);
        cache[1] = 1;
        for (int i = 2; i <= n; i++) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
        return cache[n];

        // 2nd method: top-down
        // return F(n);
    }

private:
    unordered_map<int, int> cache = {{0, 0}, {1, 1}};
    bool checkConstraints(int n) {
        if (n < 0 || n > 30) return false;
        return true;
    }
    int F(int n) {
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }
        cache[n] = F(n - 1) + F(n - 2);
        return cache[n];
    }
};
