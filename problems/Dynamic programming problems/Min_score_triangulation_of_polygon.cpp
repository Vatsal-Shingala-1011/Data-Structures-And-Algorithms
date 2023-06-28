// class Solution {
// public: //explore--gap method
// //               -- MCM
//     int solve(vector<int>& values,int i,int j){ //recursin will ....
//         if(i+1==j){
//             return 0;
//         }
//         int ans=INT_MAX;
//         for(int k=i+1;k<j;k++){
//             ans=min(ans,(values[i]*values[j]*values[k])+solve(values,i,k)+solve(values,k,j));
//         }
//         return ans;
//     }
//     int solvememo(vector<int>& values,int i,int j,vector<vector<int>>& memo){ 
//         if(i+1==j)
//             return 0;
//         if(memo[i][j]!=-1)
//             return memo[i][j];
//         int ans=INT_MAX;
//         for(int k=i+1;k<j;k++){
//             ans=min(ans,(values[i]*values[j]*values[k])+solvememo(values,i,k,memo)+solvememo(values,k,j,memo));
//         }
//         memo[i][j]=ans;
//         return ans;
//     }
//     int solvetab(vector<int>& values){
//         int n=values.size();
//         vector<vector<int>> memo(n,vector<int>(n,0));
//         for(int i=n-1;i>=0;i--){
//             for(int j=i+2;j<n;j++){
//                 int ans=INT_MAX;
//                 for(int k=i+1;k<j;k++){
//                     ans=min(ans,(values[i]*values[j]*values[k])+memo[i][k]+memo[k][j]);
//                     memo[i][j]=ans;
//                 }
//             }
//         }
//         return memo[0][n-1];
//     }
//     int minScoreTriangulation(vector<int>& values) { //self
//         int n=values.size();
//         // vector<vector<int>> memo(n,vector<int>(n,-1));
//         // return solvememo(values,0,n-1,memo);
//         return solvetab(values);
//     }
// };