// // You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// // You can either start from the step with index 0, or the step with index 1.

// // Return the minimum cost to reach the top of the floor.



// class Solution {
// public:
//     int solve(vector<int>& cost,int n,vector<int>& memo) //top down (recu+memo)
//     {
//         if(n==0)
//             return cost[0];
//         if(n==1)
//             return cost[1];
//         if(memo[n]!=-1)
//             return memo[n];
//         memo[n]=cost[n] + min(solve(cost,n-1,memo),solve(cost,n-2,memo));
//         return memo[n]; 
//     }

//     int solve2(vector<int>& cost,int n) //bottom up (tabulation)
//     {
//         // step1: creation of memo array
//         vector<int> memo(n+1);
//         // step2: base case analyse
//         memo[0]=cost[0];
//         memo[1]=cost[1];
//         //step3: 
//         for(int i=2;i<n;i++)
//         {
//             memo[i]=cost[i]+min(memo[i-1],memo[i-2]);
//         }
//         return min(memo[n-1],memo[n-2]);
//     }
    
//     int solve3(vector<int>& cost,int n) //bottom up (tabulation) space optimization
//     {
//         int prev2=cost[0];
//         int prev1=cost[1];
//         for(int i=2;i<n;i++)
//         {
//             int curr=cost[i]+ min(prev1,prev2);
//             prev2=prev1;
//             prev1=curr;
//         }
//         return min(prev1,prev2);
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         // int n=cost.size();
//         // vector<int> memo(n+1,-1);
//         // return min(solve(cost,n-1,memo),solve(cost,n-2,memo));

//         int n=cost.size();
//         // return solve2(cost,n);

//         return solve3(cost,n);
//     }
// };