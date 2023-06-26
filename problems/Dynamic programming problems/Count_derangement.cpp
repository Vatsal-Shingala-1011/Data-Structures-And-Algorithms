// #define MOD 1000000007
// #include <vector>
// long long int solveRec(int n){
//     if(n==1)
//         return 0;
//     if(n==2)
//         return 1;

//     return ( ((n-1)%MOD) * ( (solveRec(n-1)%MOD) + (solveRec(n-2)%MOD) ) %MOD);
// }                                //not swap   +   swap

// long long int solvememo(int n,vector<long long int> & memo ){
//     if(n==1)
//         return 0;
//     if(n==2)
//         return 1;
//     if(memo[n]!=-1)
//         return memo[n];
//     memo[n]=( ((n-1)%MOD) * ( (solvememo(n-1,memo)%MOD) + (solvememo(n-2,memo)%MOD) ) %MOD);
//     return memo[n];
// }    


// long long int solvetab(int n)
// {
//     vector<long long int> memo(n+1);
//     memo[1]=0;
//     memo[2]=1;
//     for(int i=3;i<=n;i++){
//         long long int first=memo[i-1]%MOD;
//         long long int second=memo[i-2]%MOD;
//         long long int sum=(first+second)%MOD;
//         long long int ans=( ((i-1)%MOD)*sum ) %MOD;
//         memo[i]=ans;
//     }
//     return memo[n];
// }
// long long int solvetab_optimum(int n)
// {
//     vector<long long int> memo(n+1);
//     int prev2=0;
//     int prev1=1;
//     for(int i=3;i<=n;i++){
//         long long int first=prev1%MOD;
//         long long int second=prev2%MOD;
//         long long int sum=(prev1+prev2)%MOD;
//         long long int ans=( ((i-1)%MOD)*sum ) %MOD;
//         prev2=prev1;
//         prev1=ans;
//     }
//     return prev1;
// }

// long long int countDerangements(int n) {
//     vector<long long int> memo(n+1,-1);  //must be n+1 because we start with index 1
//     return solvetab_optimum(n);

// }