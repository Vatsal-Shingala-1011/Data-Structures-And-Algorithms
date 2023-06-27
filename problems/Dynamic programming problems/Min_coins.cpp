// // problem : 
// // You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// // Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// // You may assume that you have an infinite number of each kind of coin.

// class Solution {
// public:
//     int solveRec(vector<int>& coins, int n) //100% done
//     {                                   //only one case other rec will do
//         if(n==0)
//             return 0;
//         if(n<0)
//             return INT_MAX;
//         int mini=INT_MAX;
//         for(int i=0;i<coins.size();i++){
//             int ans=solveRec(coins,n-coins[i]);
//             if(ans!= INT_MAX)
//                 mini=min(mini,ans+1);
//         }
//         return mini;
//     }
//     int solvememo(vector<int>& coins, int n,vector<int>& memo)
//     {
//         if(n==0)
//             return 0;
//         if(n<0)
//             return INT_MAX;
//         if(memo[n]!=-1)
//             return memo[n];
//         int mini=INT_MAX;
//         for(int i=0;i<coins.size();i++){
//             int ans=solvememo(coins,n-coins[i],memo);
//             if(ans!= INT_MAX)
//                 mini=min(mini,ans+1);
//         }
//         memo[n]=mini;
//         return mini;
//     }
//     int solvetab(vector<int>& coins, int n)//100% self freecodecamp method
//     {
//         vector<int> memo(n+1,INT_MAX);
//         int size=coins.size();
//         memo[0]=0;
//         for(int i=0;i<=n;i++){
//             if(memo[i]!=INT_MAX){
//                 for(int j=0;j<size;j++){
//                     int k=coins[j];
//                     if(i-n+k<=0)
//                     {
//                         memo[i+k]=min(memo[i+k],memo[i]+1);
//                     }
//                 }
//             }   
//         }
//         return memo[n];
//     }int solvetab2(vector<int>& coins, int n)//2nd method
//     {
//         vector<int> memo(n+1,INT_MAX);
//         int size=coins.size();
//         memo[0]=0;
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<size;j++)
//             {
//                 if(i-coins[j]>=0 && memo[i-coins[j]]!= INT_MAX)
//                 {
//                     memo[i]=min(memo[i],memo[i-coins[j]]+1);
//                 }
//             }
//         }
//         return memo[n];
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> memo(amount+1,-1);
//         int ans = solvetab2(coins,amount);
//         if(ans==INT_MAX) 
//             return -1;
//         return ans;
//     }
// };