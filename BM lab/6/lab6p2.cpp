#include <iostream>
using namespace std;

void printBoard(int n, char board[10][10], int solutionNum) {
    cout << "Solution " << solutionNum << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool isSafe(int n, char board[10][10], int row, int col) {
    // Check the left side of the current row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 'Q') {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check lower-left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int n, char board[10][10], int col, int& solutionNum) {
    if (col == n) {
        printBoard(n, board, solutionNum++);
        return true;
    }

    bool result = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(n, board, i, col)) {
            board[i][col] = 'Q';
            result = solveNQueensUtil(n, board, col + 1, solutionNum) || result;
            board[i][col] = '.';
        }
    }
    return result;
}

void solveNQueens(int n) {
    char board[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    int solutionNum = 1;
    if (!solveNQueensUtil(n, board, 0, solutionNum)) {
        cout << "No solutions found.\n";
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    solveNQueens(n);
    return 0;
}
 /*
Time complexity	
isSafe() = O(1)	
solveNQueensUtil() = O(2^n)
solveNQueens() = O(2^n)	

Space complexity
isSafe() = O(1)	
solveNQueensUtil() = O(n)
solveNQueens() = O(n^2)
 */