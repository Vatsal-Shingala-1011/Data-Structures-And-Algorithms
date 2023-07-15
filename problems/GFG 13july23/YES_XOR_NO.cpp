// class Solution {
//   public:
//     string yesXorNo(int N, long long A[], long long B[]) {
//         return "Yes";
//     }
// };





// // You are given two arrays A[] and B[], each of size N, where each element Ai and Bj are distinct. Let's consider an integer X is the count of all different pairs of Ai and Bj, such that Ai XOR Bj is present in any of the two arrays. Return "Yes" (case-sensitive) if X is even, else return "No".

// // Example 1:

// // Input:
// // N =  3
// // A[] = {1, 5, 7}
// // B[] = {2, 4, 8}
// // Output:
// // Yes
// // Explanation:
// // XOR(1,2)=3
// // XOR(1,4) = 5 is present in A[]
// // XOR(1,8) = 9
// // XOR(5,2) = 7 is present in A[]
// // XOR(5,4) = 1 is present in A[]
// // XOR(5,8) = 13
// // XOR(7,2) = 5 is present in A[]
// // XOR(7,4) = 3
// // XOR(7,8)=15
// // Out of all these XOR operations, 
// // 5,7,1,5 are present, so count of X = 4 
// // which is even. Hence the output is "Yes".
// // Example 2:

// // Input:
// // N =  2
// // A[] = {1, 5}
// // B[] = {2, 4}
// // Output:
// // Yes
// // Explanation:
// // XOR(1,2) = 3
// // XOR(1,4) = 5 is present in A[]
// // XOR(5,2)=7
// // XOR(5,4)=1 is present in A[]
// // Out of all these XOR operations,
// // 1,5 are present,
// // So count of X = 2 which is even.
// // Hence the output is "Yes".