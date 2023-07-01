////leet code
// class Solution {
// public:
//     bool ispossible(int row,int col,int n,vector<string>& str){
//         int x=row;
//         int y=col;
//         // check for same row
//         while(y>=0)
//         {
//             if(str[x][y]=='Q')
//                 return false;
//             y--;
//         }
        
//         x=row;
//         y=col;
        
//         // check for upper diagonaal
//         while(x>=0 && y>=0)
//         {
//             if(str[x][y]=='Q')
//                 return false;
//             x--;
//             y--;
//         }   
//         x=row;
//         y=col; 
//         // check for lower diagonaal
//         while(x<n && y>=0)
//         {
//             if(str[x][y]=='Q')
//                 return false;
//             x++;
//             y--;
//         }    
//         return true;
//     }
//     void solve(int col,int n,vector<string>& str,vector<vector<string>>& ans){
//         if(col==n){
//             ans.push_back(str);
//             return ;
//         }
//         for(int i=0;i<n;i++){ //row        
//             if(ispossible(i,col,n,str)){
//                 str[i][col]='Q';
//                 solve(col+1,n,str,ans);
//                 str[i][col]='.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> str;
//         string curr(n,'.');
//         for(int i=0;i<n;i++){
//             str.push_back(curr);
//         }
//         solve(0,n,str,ans);
//         return ans;
//     }
// };

// // //done 
// // class Solution {
// // public:
// // void solve(int col,int n,vector<vector<string>>&ans,vector<string>&board,                vector<int>&leftrow,vector<int>&lowerdiag,vector<int>&upperdiag)
// // {
// //       if(col==n)
// //       {
// //       ans.push_back(board);
// //       return;
// //       }

// //       for(int row=0;row<n;row++)
// //       {
// //          if(leftrow[row]==0 && lowerdiag[row+col]==0 && upperdiag[n-1+col-row]==0)
// //          {
// //              board[row][col]='Q';
// //              leftrow[row]=1;
// //              lowerdiag[row+col]=1;
// //              upperdiag[n-1+col-row]=1;
// //              solve(col+1,n,ans,board,leftrow,lowerdiag,upperdiag);
// //              board[row][col]='.';
// //              leftrow[row]=0;
// //              lowerdiag[row+col]=0;
// //              upperdiag[n-1+col-row]=0;
             
// //          }
// //       }

// // }
// //     vector<vector<string>> solveNQueens(int n) {
// //         vector<vector<string>>ans;
// //         vector<string>board(n);
// //         string s(n,'.');
// //         for(int i=0;i<n;i++)
// //         {
// //             board[i]=s;
// //         }
// //         vector<int>leftrow(n,0);        //row
// //         vector<int>lowerdiag(2*n-1,0);  // row+col
// //         vector<int>upperdiag(2*n-1,0);  // (n-1)+(col-row)
// //         solve(0,n,ans,board,leftrow,lowerdiag,upperdiag);
// //         return ans;
// //     }
// // };



// // //Bit masking
// // class Solution {
// // public:
// //     vector <vector <string>> ans;
// //     void solve(int n, int row, int colMask, int leftDiagMask, int rightDiagMask, vector <string> &board) {
// //         if (row == n) {
// //             ans.push_back(board);
// //             return;
// //         }
// //         int rowState = (colMask | leftDiagMask | rightDiagMask) & ((1 << n) - 1);
// //         int safePos = rowState ^ ((1 << n) - 1);
// //         while (safePos) {
// //             int queenPos = safePos & (-safePos);
// //             safePos -= queenPos;
// //             if (!(queenPos & rowState)) {
// //                 board[row][log2(queenPos)] = 'Q';
// //                 solve(n, row + 1, colMask | queenPos, (leftDiagMask | queenPos) << 1, (rightDiagMask | queenPos) >> 1, board);
// //                 board[row][log2(queenPos)] = '.';
// //             }
// //         }
// //     }
// //     vector<vector<string>> solveNQueens(int n) {
// //         vector <string> board(n, string (n, '.'));
// //         solve(n, 0, 0, 0, 0, board);
// //         return ans;
// //     }
// // };