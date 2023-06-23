// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {//You must solve it in O(n) time complexity.
//         priority_queue<int,vector<int>,greater<int>> q;
//         for(int i=0;i<k;i++)
//         {
//             q.push(nums[i]);
//         }
//         int n=nums.size();
//         for(int i=k;i<n;i++)
//         {
//             if(nums[i]>q.top()){
//             q.pop();
//             q.push(nums[i]);
//             }
//         }
//         return q.top();
//     }
// };