// Given an array arr[] of n positive integers. The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].

// Example 1:

// Input:
// n = 9
// arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output: 
// 6
// Explanation: 
// In the given array arr[1] < arr[7]  satisfying 
// the required condition (arr[i] <= arr[j])  thus 
// giving the maximum difference of j - i which is
// 6(7-1).
// Example 2:

// Input:
// N = 2
// arr[] = {18, 17}
// Output: 
// 0
// Explanation: 
// We can either take i and j as 0 and 0 
// or we cantake 1 and 1 both give the same result 0.
// Your Task:
// Complete the function maxIndexDiff() which takes array arr and size n, as input parameters and returns an integer representing the answer. You don't to print answer or take inputs. 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 106
// 0 ≤ Arr[i] ≤ 109



//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
// //self//correct code but TLE
//     int solve(int arr[], int n,int s,int e,vector<vector<int>>& memo){
//         if(s>=e) return 0;
//         if(arr[s]<=arr[e]) return e-s;
//         if(memo[s][e]!=-1) return memo[s][e];
//         return memo[s][e]=max(solve(arr,n,s+1,e,memo),solve(arr,n,s,e-1,memo));
//     }
//     int maxIndexDiff(int arr[], int n) {
//         vector<vector<int>> memo(n,vector<int>(n,-1));
//         return solve(arr,n,0,n-1,memo);
//     }

public:
    int solve(int arr[], int n) {
    int leftMin[n], rightMax[n];
    rightMax[n - 1] = arr[n - 1];
    for (int j = n - 2; j >= 0; j--)
        rightMax[j] = max(arr[j], rightMax[j + 1]);
    int i = 0, j = 0;
    int maxDiff = -1;
    // Traverse arr[] and rightMax[] arrays
    while (i < n && j < n) {
        if (arr[i] <= rightMax[j]) {
            maxDiff = max(maxDiff, j - i);
            j++;
        } else {
            i++;
        }
    }
    return maxDiff;
}
    int maxIndexDiff(int arr[], int n) {
        return solve(arr,n);
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends