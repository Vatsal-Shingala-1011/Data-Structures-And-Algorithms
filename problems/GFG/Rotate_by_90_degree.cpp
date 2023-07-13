
// approch1:
// class Solution{   
//     public:
//  void rotateby90(vector<vector<int> >& m, int n) 
//     { 
//         //rotate matrix by 90 degree
//         for(int i = 0;i<n;i++)
//             for(int j = i+1;j<n;j++)
//                 swap(m[i][j],m[j][i]);
                
//                 // for(int i = 0;i<n;i++)
//                 reverse(m.begin(),m.end());
//     } 
// };

// approch2:
// class Solution{   
//     public:
//     //Function to rotate matrix anticlockwise by 90 degrees.
//     void rotateby90(vector<vector<int> >& matrix, int n) { 
//         // code here 
//         for(int i=0;i<n;++i){
//             int s = 0,e = n-1;
//             while(s < e){
//                 swap(matrix[i][s++],matrix[i][e--]);
//             }
//         }
//         vector<vector<int> > temp = matrix;
//         for(int i=0;i<n;++i){
//             for(int j=0;j<n;++j){
//                 matrix[i][j] = temp[j][i];
//             }
//         }
//     } 
// };





// // Given a square matrix of size N x N. The task is to rotate it by 90 degrees in anti-clockwise direction without using any extra space. 

// // Example 1:

// // Input:
// // N = 3 
// // matrix[][] = {{1, 2, 3},
// //               {4, 5, 6}
// //               {7, 8, 9}}
// // Output: 
// // Rotated Matrix:
// // 3 6 9
// // 2 5 8
// // 1 4 7
// // Example 2:

// // Input:
// // N = 2
// // matrix[][] = {{1, 2},
// //               {3, 4}}
// // Output: 
// // Rotated Matrix:
// // 2 4
// // 1 3

// // Your Task:
// // You dont need to read input or print anything. Complete the function rotateby90() which takes the matrix as input parameter and rotates it by 90 degrees in anti-clockwise direction without using any extra space. You have to modify the input matrix in-place. 

// // Expected Time Complexity: O(N2)
// // Expected Auxiliary Space: O(1)

// // Constraints:
// // 1 ≤ N ≤ 100
// // 1 <= matrix[][] <= 1000