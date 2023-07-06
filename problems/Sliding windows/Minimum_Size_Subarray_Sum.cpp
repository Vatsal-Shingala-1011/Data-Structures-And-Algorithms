// // //leetcode
// // Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// // subarray
// //  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// // Example 1:
// // Input: target = 7, nums = [2,3,1,2,4,3]
// // Output: 2
// // Explanation: The subarray [4,3] has the minimal length under the problem constraint.


// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n=nums.size();
//         int ans=0,count=0;
//         int k=0;
//         int sum=0;
//         while(k<n && sum<target){
//             sum+=nums[k++];
//             count++;
//         }
//         if(sum>=target) ans=count;
//         int j=0,i=count;
//         while(sum>=target && j<=i){
//             sum=sum-nums[j++];
//             count--;
//             while(i<n && j<=i && sum<target){
//                 sum+=nums[i++];
//                 count++;
//             }
//             if(sum>=target) ans=min(ans,count);
//         }
//         return ans;
//     }
// };

// //     for(int i=0 ; i<nums.size() ; i++)
// //     {
// //         sum = sum + nums[i];
// //         while(sum >= target)
// //         {
// //             window = min(window,i-start+1);
// //             sum = sum - nums[start];
// //             start++;
// //         }
// //     }
// //     return window == INT_MAX ? 0 : window;
// // }