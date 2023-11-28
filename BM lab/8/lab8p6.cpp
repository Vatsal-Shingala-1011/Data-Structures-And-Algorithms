#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int n) {
    vector<int> row(n + 1, 1);  // Initialize row with 1's

    for (int i = 1; i < n; ++i) {
        // Calculate next element from the previous one
        row[i] = ((long long)row[i - 1] * (n - i + 1)) / i;
    }
    return row;
}

int main() {
    int n;
    cout << "Enter the row index: ";
    cin >> n;

    vector<int> result = getRow(n);
    cout << "Row " << n << " of Pascal's Triangle: ";
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
/*
Time Complexity :O(n) iteration of matrix once 
Space Complexity: O(n) size of row matrix

*/