#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int submatrixMaxSize(vector<vector<int>> mat) {
    /*Find the max size of square submatrix of 1s in the given matrix of 0s and 1s.*/
    if (!mat.size() || !mat[0].size()) {
        return 0;
    }
    int n = mat.size();
    vector<vector<int>> dp(n, vector<int> (n));
    int max_size = 0;
    // Copy the first row and column
    for (int i = 0; i < n; i++) {
        dp[i][0] = mat[i][0];
        dp[0][i] = mat[0][i];
        max_size = max({max_size, dp[i][0], dp[0][i]});
    }
    // Dynamic programming to find the largest square matrix of ones
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (mat[i][j]) {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                max_size = max({max_size, dp[i][j]});
            }
        }
    }
    return max_size;
}


int main(int argc, char **argv) {
    vector<vector<int>> mat = {
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 0}
    };
    cout << "submatrix_max_size: " << submatrixMaxSize(mat) << endl;
}