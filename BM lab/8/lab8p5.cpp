#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));//2D dp array
    int maxSize = 0;

    // Filling the dp matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] = 1;
                if (i > 0 && j > 0) {
                    dp[i][j] += min(min(dp[i-1][j], dp[i][j-1]) , dp[i-1][j-1]);//check all direction for square
                }
                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }
    return maxSize * maxSize; //area of the square
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    cout << "Enter the eles of the matrix " << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << "Maximum area of a square filled with 1's: " << maximalSquare(grid) << endl;

    return 0;
}

/*
n: rows
m: columns
Time Complexity :O(n*m) iteration of matrix take n*m time 
Space Complexity: O(n*m) size of dp matrix

*/