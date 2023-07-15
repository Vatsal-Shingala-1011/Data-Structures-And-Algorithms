
// /**
//     * 1. get the distinct characters in str using set 
//     * 2. expand the window from 0 to str.length() store element in map and increase the count
//     * 3. if map size equals to set size store the min len, decrease the window until map size get reduced from set size 
//     * while shrinking decrease the count of char present in map and if 
//     * count is 0 remove the element from map
// * **/
// class Solution{
//     public:
//     int findSubString(string str)//done
//     {
//         unordered_map<char,int> m;
//         for(int i=0;i<str.length();i++){
//             m[str[i]]++;
//         }
//         int i=0,j=0;
//         int ans = INT_MAX;
//         unordered_map<char,int> temp;
//         while(i<str.length() && j<str.length()){
//             temp[str[j]]++;
//             while(temp.size() == m.size()){
//                 ans = min(ans,j-i+1);
//                 temp[str[i]]--;
//                 if(temp[str[i]] == 0){
//                     temp.erase(str[i]);
//                 }
//                 i++;
//             }
//             j++;
//         }
//         return ans;
//     }
// };
    

// // Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
// // For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

// // Example 1:
// // Input : "AABBBCBBAC"
// // Output : 3
// // Explanation : Sub-string -> "BAC"
// // Example 2:
// // Input : "aaab"
// // Output : 2
// // Explanation : Sub-string -> "ab"
 
// // Example 3:
// // Input : "GEEKSGEEKSFOR"
// // Output : 8
// // Explanation : Sub-string -> "GEEKSFOR"