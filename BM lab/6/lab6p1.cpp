#include <iostream>
using namespace std;
//Function for check curr possition is possible or not
bool issafe(int m[][10], int visited[][10], int n, int r, int c) {
  if (r < n && r >= 0 && c < n && c >= 0 && m[r][c] == 1 && visited[r][c] == 0) {
    return true;
  } else {
    return false;
  }
}

void backtrack(int m[][10], int n, string v[], string op, int r, int c, int visited[][10], int &pathCount) {
  if (r == n - 1 && c == n - 1) {
    v[pathCount] = op;
    pathCount++;
    return;
  }

  if (issafe(m, visited, n, r + 1, c)) {
    visited[r + 1][c] = 1;
    backtrack(m, n, v, op + 'D', r + 1, c, visited, pathCount);
    visited[r + 1][c] = 0;
  }
  if (issafe(m, visited, n, r, c + 1)) {
    visited[r][c + 1] = 1;
    backtrack(m, n, v, op + 'R', r, c + 1, visited, pathCount);
    visited[r][c + 1] = 0;
  }
  if (issafe(m, visited, n, r - 1, c)) {
    visited[r - 1][c] = 1;
    backtrack(m, n, v, op + 'U', r - 1, c, visited, pathCount);
    visited[r - 1][c] = 0;
  }
  if (issafe(m, visited, n, r, c - 1)) {
    visited[r][c - 1] = 1;
    backtrack(m, n, v, op + 'L', r, c - 1, visited, pathCount);
    visited[r][c - 1] = 0;
  }
}

void readMatrix(int m[][10], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }
}

string* findPath(int m[][10], int n) {
  string* v = new string[10000]; // Here Assuming max 10000 paths
  int visited[10][10] = {0};
  int pathCount = 0;
  if (m[0][0] == 0 || m[n - 1][n - 1] == 0) {
    v[0] = "No path found.";
    return v;
  }
  string op = "";
  visited[0][0] = 1;
  backtrack(m, n, v, op, 0, 0, visited, pathCount);
  return v;
}

int main() {
  int n; //Matrix size

  cout << "Enter the size of the matrix: ";
  cin >> n;

  int matrix[10][10];

  cout << "Enter the matrix: ";
  readMatrix(matrix, n);

  string* path = findPath(matrix, n);

  for (int i = 0; !path[i].empty(); i++) {
    cout << "Path " << i + 1 << ": " << path[i] << endl;
  }

  return 0;
}
/*
Time complexity
issafe() = O(1)
backtrack() = O(2^n)
readMatrix() = O(n^2)
findPath() = O(2^n)

Space Complexity
issafe() = O(1)
backtrack() = O(n)
readMatrix() = O(1)
findPath() = O(n)
*/