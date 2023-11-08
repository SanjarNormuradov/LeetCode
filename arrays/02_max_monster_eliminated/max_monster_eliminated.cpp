#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;


class Solution {
public:
    int maxMonsterEliminated(const vector<int>& dist, const vector<int>& speed) {
        if (!checkConstraints(dist, speed)) {
            throw std::runtime_error("Constraints violated");
        }
        int n = dist.size();
        // Calculate time to reach the city for each monster
        vector<double> timeToCity(n);
        for (int i = 0; i < n; ++i) {
            timeToCity[i] = static_cast<double>(dist[i]) / speed[i];
        }
        // Sort the times to eliminate those monsters posing the immediate threats
        sort(timeToCity.begin(), timeToCity.end());

        int monstersEliminated = 0;
        for (int i = 0; i < n; ++i) {
            if (timeToCity[i] <= i) {
                return monstersEliminated;
            }
            monstersEliminated++;
        }

        return n;
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const vector<int>& dist, const vector<int>& speed) {
        int n = dist.size(); 
        int m = speed.size();
        if (m != n) return false;

        if (n < 1 || n > pow(10, 5)) return false;

        for (int i = 0; i < n; ++i) {
            if (dist[i] < 1 || dist[i] > pow(10, 5)) return false;
            if (speed[i] < 1 || speed[i] > pow(10, 5)) return false;
        }

        return true;
    }
};
