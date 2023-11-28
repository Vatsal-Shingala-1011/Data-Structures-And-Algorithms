#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestPalindromicSubstringUtil(const string &s, int start, int end, vector<vector<int>>& dp) {
    if (start > end) return 0; //if start pointer is greater than end pointer
    if (start == end) return 1; // when start pointer is same as end pointer return size of pallindrom is 1
    if (dp[start][end] != -1) return dp[start][end];

    if (s[start] == s[end]) {//if palindrom condition satisfy then...
        int remainingLength = end - start - 1;
        if (remainingLength == longestPalindromicSubstringUtil(s, start + 1, end - 1, dp)) {
            dp[start][end] = remainingLength + 2;
            return dp[start][end];
        }
    }

    dp[start][end] = max(longestPalindromicSubstringUtil(s, start + 1, end, dp), longestPalindromicSubstringUtil(s, start, end - 1, dp));//when palindrom condition is not satisfy then check for start+1 position and end-1 position
    return dp[start][end];
}

int longestPalindromicSubstring(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));//dp vector
    return longestPalindromicSubstringUtil(s, 0, n - 1, dp);
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int length = longestPalindromicSubstring(s);
    cout << "Length of the longest palindromic substring: " << length << endl;

    return 0;
}

/*
Time Complexity :O(n^2)
The function explores each substring once due to memoization. There are O(n^2) substrings for a string of length n.

Space Complexity: O(n^2)
dp size is n*n
*/