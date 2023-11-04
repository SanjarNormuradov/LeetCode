#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        assert(n >= 1 && n <= 100);
        assert(target.size() >= 1 && target.size() <= 100);
        assert(is_sorted(target.begin(), target.end()));

        vector<string> stack;
        int target_cnt = 0;

        for (int stream_num = 1; stream_num <= n; ++stream_num) {
            stack.push_back("Push");
            if (stream_num == target[target_cnt]) {
                target_cnt++;
                if (target_cnt == target.size()) {
                    return stack;
                }
            } else {
                stack.push_back("Pop");
            }
        }

        return stack;
    }
};
