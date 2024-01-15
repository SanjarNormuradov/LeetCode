#include <vector>
#include <cassert>
#include <cmath>

using namespace std;


class Solution {
public:
    void floodFillUtil(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
        // Check for out-of-bounds or if the color is already the new color or not the old color
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[sr].size() || 
            image[sr][sc] != oldColor || image[sr][sc] == newColor) {
            return;
        }

        // Fill the color
        image[sr][sc] = newColor;

        // Recursively call function for the surrounding pixels (up, down, left, right)
        floodFillUtil(image, sr + 1, sc, newColor, oldColor);
        floodFillUtil(image, sr - 1, sc, newColor, oldColor);
        floodFillUtil(image, sr, sc + 1, newColor, oldColor);
        floodFillUtil(image, sr, sc - 1, newColor, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        assert(checkConstraints(image, sr, sc, newColor));

        int oldColor = image[sr][sc];
        floodFillUtil(image, sr, sc, newColor, oldColor);
        return image;
    }

private:
    // Helper function to check the constraints
    bool checkConstraints(const vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(); 
        if (m == 0 || m > 50) return false;
        for (const auto& row : image) {
            int n = row.size();
            if (n == 0 || n > 50) return false;
            for (int color : row) {
                if (color < 0 || color >= pow(2, 16)) return false;
            }
        }
        if (newColor < 0 || newColor >= pow(2, 16)) return false;
        if (sr < 0 || sr >= m || sc < 0 || sc >= image[0].size()) return false;
        
        return true;
    }
};
