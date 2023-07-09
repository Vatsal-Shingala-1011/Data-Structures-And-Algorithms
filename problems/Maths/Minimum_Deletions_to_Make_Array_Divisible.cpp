// class Solution {
// public:
// long long lcm(long long a, long long b) {
//     return (a * b) / gcd(a, b);
// }
// int minOperations(vector<int>& nums, vector<int>& numsDivide) {//100% self
//         sort(nums.begin(),nums.end()); //can also do without sortion so time com O(n) instead of O(nlogn)
//         sort(numsDivide.begin(),numsDivide.end());
//         int n=nums.size(),m=numsDivide.size();   
//         long long num=0; //nums=gcd of numsDivide
//         for(int i=0;i<m;i++){
//             num=gcd(num,(long long)numsDivide[i]);
//         }
//         for(int i=0;i<n;i++){
//             if(nums[i]<=num && lcm(num,(long long)nums[i])==num){//nums[i]<=num to avoid not required calculation
//                 return i;
//             }
//         }
//         return -1;
//     }
// };