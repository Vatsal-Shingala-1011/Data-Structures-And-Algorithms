// // The count function calculates the count of ugly numbers up to a given number num. It uses the inclusion-exclusion principle to count the numbers that are divisible by a, b, or c, subtracting the counts of numbers that are divisible by the least common multiples of pairs of numbers (lcm(a, b), lcm(b, c), lcm(a, c)), and adding the count of numbers divisible by the least common multiple of all three numbers (lcm(a, lcm(b, c))). The result is returned as an integer.
// typedef long long ll;
// class Solution {
// public:
//     ll lcm(ll a, ll b) {
//         return a * b / gcd(a, b);
//     }
//     int count(ll num, ll a, ll b, ll c) {//return count of ugly number upto num //range -common +common in all three
//         return (int)(num / a + num / b + num / c - num / lcm(a, b) - num / lcm(b, c) - num / lcm(a, c) + num / (lcm(a, lcm(b, c))));
//     }
//     int nthUglyNumber(int n, int a, int b, int c) { //easy done 
//         int left = 0, right = 2e9, result = 0;   
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (count(mid, a, b, c) >= n) { 
//                 result = mid;
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         }
//         return result;
//     }
    
// };