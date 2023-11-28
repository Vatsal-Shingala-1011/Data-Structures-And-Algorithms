#include <iostream>
using namespace std;

void dfs(char** grid, int m, int n, int i, int j) {//Function for DFS
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
        return; // return if out of bounds or water
    }

    grid[i][j] = '0'; // mark as visited

    // Explore all adjacent cells
    dfs(grid, m, n, i + 1, j);
    dfs(grid, m, n, i - 1, j);
    dfs(grid, m, n, i, j + 1);
    dfs(grid, m, n, i, j - 1);
}

int numIslands(char** grid, int m, int n) {
    int num_islands = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                ++num_islands;
                dfs(grid, m, n, i, j); // perform DFS to mark all parts of the island
            }
        }
    }

    return num_islands;
}

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    // allocation of the 2D grid
    char** grid = new char*[m];
    for (int i = 0; i < m; ++i) {
        grid[i] = new char[n];
    }

    cout << "Enter the grid (only '1's and '0's):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << "Number of islands: " << numIslands(grid, m, n) << endl;

    return 0;
}

/* 
m = number of row
n= number of column
m*n = total number of grid
Time Complexity:O(m*n)
Space Complexity:O(m*n)

*/
 