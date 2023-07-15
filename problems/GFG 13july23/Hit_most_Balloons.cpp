
// class Solution {
//   public:
//     int mostBalloons(int N, pair<int, int> a[]) {
//         int ans=0;
//         // cout<<(double)(1)/0; inf
//         for(int i=0;i<N;i++){
//             int x1=a[i].first;
//             int y1=a[i].second;
//             unordered_map<double,int> m;
//             int cnt=0;
//             for(int j=0;j<N;j++){
//                 int x2=a[j].first;
//                 int y2=a[j].second;
//                 if(x1==x2 and y1==y2){
//                     cnt++;
//                     continue;  
//                 } 
//                 double nume=(double)(y2-y1);
//                 double deno=(double)(x2-x1);
//                 double slope=nume/deno;
//                 m[slope]++;
//             }
//             for(auto x:m){
//                 ans=max(ans,x.second+cnt);
//             }
//         }
//         return ans;
//     }
// };





// // You are given an infinite two-dimensional grid. There are N balloons placed at certain coordinates of the grid. You have an arrow with yourself, which you will be using to shoot the balloons. You can select any point on the grid as your starting point and any point on the grid as the target point. When you fire the arrow, all ballons lying on the shortest path between the starting point and target point will be burst. Given the coordinates of the N ballons in an array arr, your task is to find out the maximum number of balloons that you can fire in one arrow shot.

// // Example 1:

// // Input:
// // N = 3
// // arr[] = {{1, 2}, {2, 3}, {3, 4}}
// // Output:
// // 3
// // Explanation:
// // If you position yourself at point (1,2)
// // and fire the arrow aiming at the point (3,4).
// // Then all the balloons will burst.
// // Example 2:

// // Input: 
// // N = 3
// // arr[] = {{2,2}, {0,0}, {1,2}} 
// // Output:
// // 2
// // Explanation: 
// // If you position yourself at point (2,2)
// // and fire the arrow aiming at the point (0,0).
// // Then the two balloons present at the two points
// // will burst.
// // Your Task:
// // Complete the function mostBalloons() which takes the integers N and the array arr as the input parameters, and returns the maximum number of balloons that can be burst using one arrow.

// // Expected Time Complexity: O(N2)
// // Expected Auxiliary Space: O(N)

// // Constraints:
// // 1 ≤ N ≤ 103
// // -109 ≤ arr[i][j] ≤ 109

