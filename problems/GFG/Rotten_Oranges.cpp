// class Solution 
// {
//     public:
//     //Function to find minimum time required to rot all oranges. 
//     int orangesRotting(vector<vector<int>>& grid) {
//        queue<pair<int,int>> q;
//        int n=grid.size();
//        int m=grid[0].size();
//        vector<vector<bool>> visited(n,vector<bool>(m,false));
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                if(grid[i][j]==2){
//                    q.push({i,j});
//                }
//            }
//        }
//         int t=-1;
//         while(!q.empty()){
//             t++;
//             int nn=q.size();
//             while(nn--){
//                 int row=q.front().first,col=q.front().second;
//                 q.pop();
//                 visited[row][col]=true;
//                 if(row-1>=0 &&visited[row-1][col]==false&& grid[row-1][col]==1){//up row
//                     grid[row-1][col]=2;
//                     q.push({row-1,col});
//                 }
//                 if(row+1<n &&visited[row+1][col]==false&& grid[row+1][col]==1){//down row
//                     grid[row+1][col]=2;
//                     q.push({row+1,col});
//                 }
//                 if(col-1>=0 &&visited[row][col-1]==false&& grid[row][col-1]==1){//left row
//                     grid[row][col-1]=2;
//                     q.push({row,col-1});
//                 }
//                 if(col+1<m &&visited[row][col+1]==false&& grid[row][col+1]==1){//right row
//                     grid[row][col+1]=2;
//                     q.push({row,col+1});
//                 }
//           }
//         }
      
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1){
//                     return -1;
//                 }
//           }
//       }
//        return t;
//     }
// };






// // Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// // 0 : Empty cell
// // 1 : Cells have fresh oranges
// // 2 : Cells have rotten oranges

// // We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

// // Example 1:

// // Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
// // Output: 1
// // Explanation: The grid is-
// // 0 1 2
// // 0 1 2
// // 2 1 1
// // Oranges at positions (0,2), (1,2), (2,0)
// // will rot oranges at (0,1), (1,1), (2,2) and 
// // (2,1) in unit time.
// // Example 2:

// // Input: grid = {{2,2,0,1}}
// // Output: -1
// // Explanation: The grid is-
// // 2 2 0 1
// // Oranges at (0,0) and (0,1) can't rot orange at
// // (0,3).