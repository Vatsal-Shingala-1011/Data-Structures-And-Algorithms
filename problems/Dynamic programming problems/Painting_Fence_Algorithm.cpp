// #include <bits/stdc++.h> 
// #define MOD 1000000007

// int add(int a,int b){
//     return ((a%MOD)+(b%MOD))%MOD;
// }
// int mul(int a,int b){
//     return ((a%MOD)*1LL*(b%MOD))%MOD;
// }
// int solve(int n,int k,vector<int>& memo)//done
// {
//     if(n==1)
//         return k;
//     if(n==2)
//         return add(k,mul(k,k-1));
//     if(memo[n]!=-1)
//         return memo[n];
    
//     memo[n]=mul(add(solve(n-2,k,memo),solve(n-1,k,memo)),k-1);
//     return memo[n];
// }
// int solvetab(int n,int k){ //tab
//     int prev2=0;
//     int prev1=k;
//     for(int i=2;i<=n;i++){
//         int same=prev1;
//         int diff=mul( (add(prev1,prev2)),(k-1));
//         prev2=same;
//         prev1=diff;
//     }
//     return add(prev1,prev2);
// }

// int numberOfWays(int n, int k) { //can do optimum memo and tabu
//     vector<int> memo(n+1,-1);
//     return solvetab(n,k);
// }
