
// class Solution{
// public:
//     int isStackPermutation(int N,vector<int> &A,vector<int> &B){ //100% self
//         stack<int> s;
//         int j=0;
//         for(int i=0;i<N+1;i++){
//             while(!s.empty()&&s.top()==B[j]){
//                 s.pop();
//                 j++;
//             }
//             if(i<N)s.push(A[i]);
//         }
//         if(s.empty())return 1;
//         return 0;
//     }
// };


// // You are given two arrays A and B of unique elements of size N. Check if array B is a stack permutation of the array A or not.
// // Stack permutation means that array B can be created from array A using a stack and stack operations.

 

// // Example 1:

// // Input:
// // N = 3
// // A = {1,2,3}
// // B = {2,1,3}
// // Output:
// // 1
// // Explanation:
// // 1. push 1 from A to stack
// // 2. push 2 from A to stack
// // 3. pop 2 from stack to B
// // 4. pop 1 from stack to B
// // 5. push 3 from A to stack
// // 6. pop 3 from stack to B
 

// // Example 2:

// // Input:
// // N = 3
// // A = {1,2,3}
// // B = {3,1,2}
// // Output:
// // 0
// // Explanation:
// // Not Possible
 

// // Your Task:

// // You don't need to read input or print anything. Your task is to complete the function isStackPermutation() which takes two arrays A and B as inputs and returns 1 if it is a stack permutation otherwise returns 0.

 

// // Expected Time Complexity: O(N)
// // Expected Auxiliary Space: O(N)

 

// // Constraints:
// // 1 <= N <= 105
// // 0 <= A[i], B[i] <= 2*105
// // Sum of N over all test cases doesn't exceeds 106