//leet code

// class Solution {//self
// public:
//     bool solvememo(vector<int>& nums,int index,int target,vector<vector<int>>& memo){//done
//         if(index<0)//till index=0 not made target 
//             return false;
//         if(target<0)
//             return false;
//         if(target==0) 
//             return true;
        
//         if(memo[index][target]!=-1){
//             return memo[index][target];}
//         bool inc=solvememo(nums,index-1,target-nums[index],memo);
//         bool exc=solvememo(nums,index-1,target,memo);
//         memo[index][target]=(inc||exc);
//         return memo[index][target];
//     }
//     bool solvetab(vector<int>& nums,int target){
//         int n=nums.size(); //
//         vector<bool> prev(target+1, 0), cur(target+1, 0);
//         prev[0]=true;
//         cur[0]=true;
//         for(int i=0;i<n;i++){
//             for(int j=1;j<=target;j++){
//                 bool inc=false;
//                 if(nums[i]<=j){
//                     inc=prev[j-nums[i]];
//                 }
//                 bool exc=prev[j];
//                 cur[j]=(inc||exc);  
//             }
//             prev=cur;
//         }
//         return cur[target];
//     }
    
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int sum=0;
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//         }
//         if(sum&1)
//             return false;
//         vector<vector<int>> memo(n+1,vector<int>((sum/2 + 1),-1));
//         // return solvememo(nums,n-1,sum/2,memo);
//         return solvetab(nums,sum/2);
//     }
// };
