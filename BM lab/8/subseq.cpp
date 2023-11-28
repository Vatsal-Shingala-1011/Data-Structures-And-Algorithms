#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reverseString(string& str) { //function for reverse string
    int n = str.length();
    for (int i = 0; i < n / 2; ++i) {
        swap(str[i], str[n - i - 1]);
    }
}
int solve(string str1, string str2, int i, int j, vector<vector<int>>& memo) {
    if (i == str1.length() || j == str2.length()) return 0; //end of string 
    if (memo[i][j] != -1) return memo[i][j];
    if (str1[i] == str2[j]) return memo[i][j] = 1 + solve(str1, str2, i + 1, j + 1, memo); //if same word then move forword
    else return memo[i][j] = max(solve(str1, str2, i + 1, j, memo), solve(str1, str2, i, j + 1, memo));
}

int longestPalindromeSubseq(string str) {
    int n = str.length();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    string str2 = str;
    reverseString(str2); 
    return solve(str, str2, 0, 0, memo);
}

int main() {
    string s;
    cout << "Enter the string ";
    cin >> s;

    int length = longestPalindromeSubseq(s);
    cout << "Length of the longest palindromic subsequence: " << length << endl;

    return 0;
}
/*
Time Complexity :O(n^2)
Each pair of indices (i, j) is solved once and stored in memo. Since there are n^2 such pairs for a string of length n, the time complexity is O(n^2)

Space Complexity: O(n^2)
The space complexity is dominated by the memo matrix, which is of size n x n
*/