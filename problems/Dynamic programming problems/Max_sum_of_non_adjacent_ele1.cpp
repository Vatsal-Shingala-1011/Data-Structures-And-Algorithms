// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         class Solution {
// public:
    
// int solvememo(vector<int> &nums,vector<int>& memo,int n,int i) //memo
// {
//     if(i>=n){
//         return 0;
//     }
//     if(i==n-1){
//         return nums[n-1];
//     }
//     if(memo[i]!=-1)
//     {
//         return memo[i];
//     }
//     int include=solvememo(nums,memo,n,i+2) + nums[i];
//     int exclude=solvememo(nums,memo,n,i+1);

//     memo[i]=max(include,exclude);
//     return memo[i];

// }
// int solvetab(vector<int> &nums) //self
// {
//     int n=nums.size();
//     vector<int> memo(n,-1);
//     memo[0]=nums[0];
//     memo[1]=max(nums[0],nums[1]); //for size=1 also valid 
//     for(int i=2;i<n;i++)
//     {
//         int inc=memo[i-2]+nums[i];
//         int exc=memo[i-1];
//         memo[i]=max(inc,exc);
//     }
//     return memo[n-1];
// }

// int solvetab_spaceoptimum(vector<int> &nums) //self
// {
//     int n=nums.size();
//     int prev1=nums[0]; //this work for size 1 also
//     int prev2=0;
//     for(int i=1;i<n;i++)
//     {
//         int inc=prev2+nums[i];
//         int exc=prev1;
//         int curr=max(inc,exc);
//         prev2=prev1;
//         prev1=curr;
//     }
//     return prev1;
// }
//     int rob(vector<int>& nums) {
//     // int n=nums.size(); //memo
//     // vector<int> memo(n,-1);
//     // return solvememo(nums,memo,n,0);

//     // solvetab(nums);
//     return solvetab_spaceoptimum(nums);
//     }
// };


//     }
// };