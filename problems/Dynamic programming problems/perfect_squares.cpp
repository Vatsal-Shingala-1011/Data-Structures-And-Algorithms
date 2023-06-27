//leet code

// class Solution {
// public:
//     int solve(int n)
//     {
//         if(n==0)
//             return 0;
//         int ans=0;
//         for(int i=1;i*i<=n;i++)
//         {
//             ans=min(ans,solve(n-(i*i))+1);
//         }
//         return ans;
//     }

//     int solvememo(int n,vector<int>& memo)
//     {
//         if(n==0)
//             return 0;
//         if(memo[n]!=-1)
//             return memo[n];
//         int ans=INT_MAX;
//         for(int i=1;i*i<=n;i++)
//         {
//             ans=min(ans,solvememo(n-(i*i),memo)+1);
//         }
//         memo[n]=ans;
//         return memo[n];
//     }
//     int solvetab(int n)
//     {
//         vector<int> memo(n+1,INT_MAX); //100% self
//         memo[0]=0;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j*j<=n;j++){
//                 if(i-(j*j)>=0 && memo[i-(j*j)]!=INT_MAX){
//                     memo[i]=min(memo[i],1+memo[i-(j*j)]);
//                 }
//             }
//         }
//         return memo[n];
//     }
//     int numSquares(int n) { 
//         // vector<int> memo(n+1,-1);
//         // return solvememo(n,memo);
//         return solvetab(n);
//     }
// };