// // class Solution {
// // public:
// //     bool isPowerOfThree(int n) {
// //         if(n<=0) return false;
// //         // if(pow(3,20)<INT_MAX) cout<<"True";          //Experiment which is the highest power of 3 that is in INT range
// //         // if(pow(3,19)<INT_MAX) cout<<"True";
// //         return 1162261467%n==0;                         //19th power of 3 is 1162261467
// //     }
// // };

// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         return fmod(log10(n)/log10(3), 1)==0;
//     }
// };
// // fmod(x, 1) calculates the remainder when x is divided by 1. It returns the fractional part of x. In this case, x is the logarithm of n to the base 3.