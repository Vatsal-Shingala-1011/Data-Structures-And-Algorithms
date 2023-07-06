// // Given a binary array nums, you should delete one element from it.

// // Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

// // Example 1:

// // Input: nums = [1,1,0,1]
// // Output: 3
// // Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.


// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {//self 100%
//         int ans=0;
//         int res=0;
//         bool cnt=false;
//         int prev=0;
//         bool dele=false;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int temp=ans+nums[i];
//             if(temp==ans && cnt==false){
//                 ans=ans-prev;
//                 prev=ans;
//                 dele=true;
//                 cnt=true;
//             }
//             else if(temp==ans && cnt==true){
//                 ans=ans-prev;
//                 prev=ans;
//                 cnt=false;   
//             }
//             else{
//                 ans=temp;
//                 res=max(ans,res);
//             }
//         }
//         if(dele==false && res==0) return 0;
//         if(dele==false) return res-1;
//         return res;
//     }
// };
