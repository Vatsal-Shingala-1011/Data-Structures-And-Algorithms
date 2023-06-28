// class Solution {//Russian Doll  optimize in one array
// public:
//     int solvememo(int n,vector<int>& nums,int curr,int prev,vector<vector<int>>& memo){
//         if(curr==n)
//             return 0;
//         if(memo[curr][prev+1]!=-1) //perv+1 because in next if there is prev=-1
//             return memo[curr][prev+1]; //so we shift cordinate by 1
//         int take=0;
//         if(prev==-1 || nums[curr]>nums[prev])
//             take=1+solvememo(n,nums,curr+1,curr,memo);
//         int nottake=solvememo(n,nums,curr+1,prev,memo);
//         return memo[curr][prev+1]=max(take,nottake);
//     }
//     int solvetab(int n,vector<int>& nums){
//         vector<vector<int>> memo(n+1,vector<int>(n+1,0));
//         for(int curr=n-1;curr>=0;curr--){
//             for(int prev=curr-1;prev>=-1;prev--){//shifted by 1 (prev only curr is same)
//                 int take=0;
//                 if(prev==-1 || nums[curr]>nums[prev])
//                     take=1+memo[curr+1][curr+1]; 
//                 int nottake=memo[curr+1][prev+1];
//                 memo[curr][prev+1]=max(take,nottake);
//             }
//         }
        
//         return memo[0][0];
//     }

//     int solve(vector<int>& nums){
//         int n=nums.size();
//         if(n==0) return 0;
//         vector<int> ans;
//         ans.push_back(nums[0]);
//         for(int i=1;i<n;i++)
//         {
//             if(nums[i]>ans.back())
//                 ans.push_back(nums[i]);
//             else{
//                 int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin(); //index
//                 ans[index]=nums[i];
//             }
//         }
//         return ans.size();
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> memo(n,vector<int>(n+1,-1));
//         // return solvememo(n,nums,0,-1,memo); 
//         // return solvetab(n,nums);
//         return solve(nums);
//     }
// };