#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int min_horses(const string& sound) {
        map<char, int> counts{{'n', 0}, {'e', 0}, {'i', 0}, {'g', 0}, {'h', 0}};
        int max_horses = 0;
        
        for (char ch : sound) {
            if (counts.find(ch) != counts.end()) {
                counts[ch]++;
                
                // If the current character is 'n', check if we can decrement all counters
                if (ch == 'n' && all_of(counts.begin(), counts.end(), [&](const pair<char, int>& p) { return p.second >= 1; })) {
                    for (auto& count : counts) {
                        count.second--;
                    }
                }
                // Update the maximum number of horses needed
                max_horses = max(max_horses, counts['n']);
            }
        }
        
        return max_horses;
    }
};
