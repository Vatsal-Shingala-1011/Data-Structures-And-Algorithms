// //GFG
// //{ Driver Code Starts
// // Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// // User function Template for C++

// class Solution{
// public:
//     int solve(vector<vector<int>>& mat,int i,int j,int& maxi){
//         if(i>=mat.size() || j>=mat[0].size())
//             return 0;
//         int right=solve(mat,i,j+1,maxi);
//         int left=solve(mat,i+1,j,maxi);
//         int dia=solve(mat,i+1,j+1,maxi);
        
//         if(mat[i][j]==1)
//         {
//             int ans=1+min(left,min(right,dia));
//             maxi=max(maxi,ans);
//             return ans;
//         }
//         else{
//             return 0;
//         }
//     }
//     int solvememo(vector<vector<int>>& mat,int n,int m,int i,int j,int& maxi,vector<vector<int>>& memo){
//         if(i>=n || j>=m)
//             return 0;
//         if(memo[i][j]!=-1)
//             return memo[i][j];
//         int right=solvememo(mat,n,m,i,j+1,maxi,memo);
//         int dia=solvememo(mat,n,m,i+1,j+1,maxi,memo);
//         int down=solvememo(mat,n,m,i+1,j,maxi,memo);
//         if(mat[i][j]==1)
//         {
//             memo[i][j]=1+ min(down, min(right, dia));
//             maxi=max(maxi,memo[i][j]);
//             return memo[i][j];
//         }
//         else{
//             return memo[i][j]=0;
//         }
//     }

//     int solvetab(vector<vector<int>> &mat,int row,int col,int& maxi){ //done
//         vector<vector<int>> memo(row+1,vector<int>(col+1,0));
//         for(int i=row-1;i>=0;i--)
//         {
//             for(int j=col-1;j>=0;j--)
//             {
//                 int right=memo[i][j+1];
//                 int dia=memo[i+1][j+1];
//                 int left=memo[i+1][j];
//                 if(mat[i][j]==1)
//                 {
//                     memo[i][j]=1+min(left,min(right,dia));
//                     maxi=max(maxi,memo[i][j]);
//                 }
//                 else{
//                     memo[i][j]=0;
//                 }
                
//             }
//         }
//         return 0;
//     }
//     int maxSquare(int n, int m, vector<vector<int>> mat){
//         int maxi=0;
//         vector<vector<int>> memo(n,vector<int>(m,-1));
//         // solve(mat,0,0,maxi);
//         solvememo(mat,n,m,0,0,maxi,memo);
//         // solvetab(mat,n,m,maxi);
//         return maxi;
//     }
// };

// //{ Driver Code Starts.

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n, m;
//         cin>>n>>m;
//         vector<vector<int>> mat(n, vector<int>(m, 0));
//         for(int i = 0;i < n*m;i++)
//             cin>>mat[i/m][i%m];
        
//         Solution ob;
//         cout<<ob.maxSquare(n, m, mat)<<"\n";
//     }
//     return 0;
// }
// // } Driver Code Ends