// // class Solution {
// // public:
// //     // Using Backtracking time complexity more  //done
// //     bool solve(int n, int p = 1) {  //take not take
// //     if (n == 0)
// //         return true;
// //     if (p > n)
// //         return false;
// //     return solve(n, p * 3) || solve(n - p, p * 3);
// //     }                         //take                    //not take
// //     bool checkPowersOfThree(int n) {
// //         return solve(n);
// //     }
// // };


// class Solution {//done
// public:
//     bool checkPowersOfThree(int n) {
//         int sum = 0;
//         for(int i=14; i>=0; i--) { //we can alsp take from i=floor(log(n)/log(3)) to 0 so no need to check <n condition
//             if(sum + pow(3, i) == n) return true;
//             else if(sum + pow(3, i) < n) sum += pow(3, i);
//         }
//         return false;
//     }
// };

// // class Solution { //done
// // public:
// //     bool checkPowersOfThree(int n) {
// //         while(n>0){
// //             if(n%3==2) return false;
// //             n = n/3;
// //         }
// //         return true;
// //     }
// // };
