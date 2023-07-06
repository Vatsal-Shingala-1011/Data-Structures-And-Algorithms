// // Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// // The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



// class Solution {
// public:
//     bool solve(bool& flag,int row,int col,int n,int m,int curr,int l,vector<vector<char>>& board, string word,vector<vector<bool>>& visited){
//         if(curr==l){// length of word
//             flag=true;
//             return true;
//         } 
//         //right
//         if(col+1<m && visited[row][col+1]==false &&board[row][col+1]==word[curr]){
//             visited[row][col+1]=true;
//             if(solve(flag,row,col+1,n,m,curr+1,l,board,word,visited)) return true; 
//             visited[row][col+1]=false;
//         }
//         //left
//         if(col-1>=0 && visited[row][col-1]==false &&board[row][col-1]==word[curr]){
//             visited[row][col-1]=true;
//             if(solve(flag,row,col-1,n,m,curr+1,l,board,word,visited)) return true;  
//             visited[row][col-1]=false;
//         }
//         //up
//         if(row-1>=0 && visited[row-1][col]==false &&board[row-1][col]==word[curr]){
//             visited[row-1][col]=true;
//             if(solve(flag,row-1,col,n,m,curr+1,l,board,word,visited)) return true; ; 
//             visited[row-1][col]=false;
//         }
//         //down
//         if(row+1<n && visited[row+1][col]==false &&board[row+1][col]==word[curr]){
//             visited[row+1][col]=true;
//             if(solve(flag,row+1,col,n,m,curr+1,l,board,word,visited)) return true; 
//             visited[row+1][col]=false;
//         }
//         return false;
//     }
//     bool exist(vector<vector<char>>& board, string word) {//100% self
//         int n=board.size();
//         int m=board[0].size();
//         int l=word.length();
//         int curr=0;
//         bool flag=false;
//         vector<vector<bool>> visited(n,vector<bool>(m,false));  
//         for(int row=0;row<n;row++){
//             for(int col=0;col<m;col++){
//                 if(board[row][col]==word[curr]){
//                     visited[row][col]=true;
//                     if(solve(flag,row,col,n,m,curr+1,l,board,word,visited)) return true;  
//                     visited[row][col]=false;
//                 }
//             }
//         }
//         return false;
//     }
// };