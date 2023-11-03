#include <iostream>
#include <string>
#include <algorithm>
#include <map>


int min_horses(const std::string& sound) {
    using namespace std;

    map<char, int> counts{{'n', 0}, {'e', 0}, {'i', 0}, {'g', 0}, {'h', 0}};
    int max_horses = 0;
    
    for (char ch : sound) {
        // Increment the counter for the current character
        if (counts.find(ch) != counts.end()) {
            counts[ch]++;
            
            // If the current character is 'n', check if we can decrement all counters
            if (ch == 'n' && all_of(counts.begin(), counts.end(), 
                [&](const pair<char, int>& p) { return p.second >= counts['n']; })) {
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


int main() {
    using namespace std;

    cout << min_horses("nneigheigh") << endl;
    cout << min_horses("neighneigh") << endl;
    
    return 0;
}
