// class Solution {
//   public:
//     int kadans(vector<int>& sum){
//         int n=sum.size();
//         int max_so_far=INT_MIN,max_ending_here=0;
//         for(int i=0;i<n;i++){
//             max_ending_here+=sum[i];
//             if(max_so_far<max_ending_here) max_so_far=max_ending_here;
//             if(max_ending_here<0) max_ending_here=0;
//         }
//         return max_so_far;
//     }
//     int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
//         int maxsum=INT_MIN;
//         for(int cstart=0;cstart<C;cstart++){
//             vector<int> sum(R,0);
//             for(int cend=cstart;cend<C;cend++){
//                 for(int row=0;row<R;row++){
//                     sum[row]+=M[row][cend];
//                 }
//                 maxsum=max(maxsum,kadans(sum));
//             }
//         }
//         return maxsum;
//     }
// };






// // Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.

// // Example 1:

// // Input:
// // R=4
// // C=5
// // M=[[1,2,-1,-4,-20],
// // [-8,-3,4,2,1],
// // [3,8,10,1,3],
// // [-4,-1,1,7,-6]]
// // Output:
// // 29
// // Explanation:
// // The matrix is as follows and the
// // blue rectangle denotes the maximum sum
// // rectangle.
// // Thumbnail
// // Example 2:

// // Input:
// // R=2
// // C=2
// // M=[[-1,-2],[-3,-4]]
// // Output:
// // -1
// // Explanation:
// // Taking only the first cell is the 
// // optimal choice.