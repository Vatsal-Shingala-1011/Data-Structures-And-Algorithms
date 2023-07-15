// // O(nlogn), O(n)
// class Solution {
//   public:
//     long long solve(int N, vector<int> &A, vector<int> &B) {
//     long long sum = 0;
//     vector<int> x[2], y[2]; //array of vector
//     for(int i=0;i<2;i++) {
//         x[i]=vector<int>();
//         y[i]=vector<int>();
//     }
//     for(int i = 0; i < N; i++) {
//         sum += A[i] - B[i];
//         if(A[i]%2==0)  //even element in A
//             x[0].push_back(A[i]);
//         else 
//             x[1].push_back(A[i]);

//         if(B[i]%2==0) // odd element in B
//             y[0].push_back(B[i]);
//         else 
//             y[1].push_back(B[i]);
//     }

//     if(sum != 0 || x[0].size() != y[0].size()) //if even(and odd) number is not same in both array return -1
//         return -1;
    
//     long long ans = 0;
    
//     for(int i = 0; i < 2; i++) {
//         sort(x[i].begin(), x[i].end());
//         sort(y[i].begin(), y[i].end());//by sorting we choose mini diff between two 
    
//         for(int j = 0; j < (int)x[i].size(); j++) 
//             ans += abs(x[i][j] - y[i][j]) / 2;
//     }
//     return ans/2 ;


// //     You are given two arrays A and B each of length N. You can perform the following operation on array A zero or more times. 

// // Select any two indices i and j, 1 <= i , j <= N and i != j
// // Set A[i] = A[i] + 2 and A[j] = A[j]-2
// // Find the minimum number of operations required to make A and B equal.

// // Note :

// // Two arrays are said to be equal if the frequency of each element is equal in both of them.
// // Arrays may contain duplicate elements.
// // Example 1:

// // Input:
// // N = 3
// // A[] = {2, 5, 6}
// // B[] = {1, 2, 10}
// // Output: 2
// // Explanation: 
// // Select i = 3, j = 2, A[3] = 6 + 2 = 8 and A[2] = 5 - 2 = 3
// // Select i = 3, j = 2, A[3] = 8 + 2 = 10 and A[2] = 3 - 2 = 1
// // Now A = {2, 1, 10} and B = {1, 2, 10}
// // Example 2:

// // Input:
// // N = 2
// // A[] = {3, 3}
// // B[] = {9, 8}
// // Output: -1
// // Explanation: 
// // It can be shown that A cannot be made equal to B.