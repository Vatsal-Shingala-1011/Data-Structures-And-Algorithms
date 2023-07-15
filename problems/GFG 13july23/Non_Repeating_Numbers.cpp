// class Solution
// {
// public:
//     vector<int> singleNumber(vector<int> nums) 
//     {
//         int xorans=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             xorans^=nums[i];
//         }
//         xorans=xorans & ~(xorans-1); //right most bit
//         //set1 and set2
//         int set1=0,set2=0;
//         for(int i=0;i<n;i++){
//             if(xorans & nums[i])
//                 set1^=nums[i];
//             else set2^=nums[i];
//         }
//         if(set1<set2) return {set1,set2};
//         else return {set2,set1};
//     }
// };




// // Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.


// // Example 1:

// // Input: 
// // N = 2
// // arr[] = {1, 2, 3, 2, 1, 4}
// // Output:
// // 3 4 
// // Explanation:
// // 3 and 4 occur exactly once.
// // Example 2:

// // Input:
// // N = 1
// // arr[] = {2, 1, 3, 2}
// // Output:
// // 1 3
// // Explanation:
// // 1 3 occur exactly once.

// // Your Task:
// // You do not need to read or print anything. Your task is to complete the function singleNumber() which takes the array as input parameter and returns a list of two numbers which occur exactly once in the array. The list must be in ascending order.


// // Expected Time Complexity: O(N)
// // Expected Space Complexity: O(1)


// // Constraints:
// // 1 <= length of array <= 106 
// // 1 <= Elements in array <= 5 * 106