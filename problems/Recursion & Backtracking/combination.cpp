// ////leetcode
// //// problem: Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// // You may return the answer in any order.


// class Solution {
// public: 
//     void solve(int start,int n,int k,vector<vector<int>>& ans,vector<int> v){//100% se
//         if(v.size()==k){
//             ans.push_back(v);
//             return;
//         }
//         for(int i=start;i<=n;i++){
//             v.push_back(i);
//             solve(i+1,n,k,ans,v);
//             v.pop_back();
//         }
//     }
//     vector<vector<int>> combine(int n, int k) {
//         vector<vector<int>> ans;
//         vector<int> v;
//         solve(1,n,k,ans,v);
//         return ans;
//     }
// };

// // class Solution {
// // public: // [1,2,3,4,5,6,7,8,9] n=9 k=4
// //     void solve(int last,int n,int k,vector<vector<int>>& ans,vector<int> v){
// //         if(last=)
// //     //     ans.push_back(v);
// //     //     v.pop();
// //     //     for(int i=last+1;i<k;i++){
// //     //         v.push_back(i);
// //     //         ans.push_back(v);
// //     //         v.pop_back();
// //     //     }
// //     //     last=last-1;
// //     // }
// //     // vector<vector<int>> combine(int n, int k) {//self code
// //     //     vector<vector<int>> ans;
// //     //     vector<int> v;
// //     //     for(int i=1;i<=n;i++){
// //     //         v.push_back(i);
// //     //     }
// //     //     solve(v.size()-1,n,k,ans,v);
// //     //     return ans;
//     // }
// };

// // other method 
// // Intuition
// // if n = 4 and k=2 then
// // [1,2,3,4]
// // first array temp
// // [1,2]
// // create temp array that store 1 to k element values.
// // min = n-k //4-2 = 2
// // increment end when temp[0] == min
// // increment last index value of temp array and push into final ans array. when it's value == n then increment last-1 and set last value temp[last] = temp[last-1] + 1;