// // Given a string s, find the length of the longest 
// // substring
// //  without repeating characters.

// // Example 1:
// // Input: s = "abcabcbb"
// // Output: 3
// // Explanation: The answer is "abc", with the length of 3.

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n=s.length();
//         if(n==0) return 0;
//         int ans=0,left=0;
//         unordered_map<char,int> map;
//         for(int right=0;right<n;right++){
//            if(map.count(s[right])>0){//found
//                left=max(left,map[s[right]]+1); //can store map[s[right]]=right so no need to use max and statement become left=map[s[right]]+1;
//            }
//            map[s[right]]=right;
//            ans=max(ans,right-left+1);
//         }
//         return ans;
//     }
// };
