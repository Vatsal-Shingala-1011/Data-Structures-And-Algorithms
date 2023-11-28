#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, grid[0][0]));//initialize dp
    // initialize the first row and first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for (int i = 1; i < m; ++i) { //traverse matrix and choose optimum solution
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

int main() {
    int m, n;
    cout << "Enter the number of rows ";
    cin >> m;
    cout << "Enter the number of column ";
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the grid values " << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << "Minimum path sum: " << minPathSum(grid) << endl;
    return 0;
}

/* 
Time Complexity : O(m*n) Each cell in the grid is processed exactly once. The processing involves constant-time operations.
Space Complexity: O(m*n)  
*/