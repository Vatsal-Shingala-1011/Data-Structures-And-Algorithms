// class Solution { ///done
// public:
//     vector<int> hour = {1,2,4,8};
//     vector<int> minute = {1,2,4,8,16,32};
//     vector<string> res;
//     void solve(int hr, int min, int i, int n){
//         if(n == 0){
//             string s = to_string(hr)  + (min < 10 ? ":0" : ":")  + to_string(min);
//             res.push_back(s);
//             return;
//         }
//         for(int j = i; j < hour.size() + minute.size();j++){
//             if(j < hour.size()){
//                 hr += hour[j];
//                 if(hr < 12) solve(hr,min,j+1,n-1);
//                 hr -= hour[j];
//             }
//             else{
//                 min += minute[j-hour.size()];
//                 if(min < 60) solve(hr,min,j+1,n-1);
//                 min -= minute[j-hour.size()];
//             }
//         }
//     }
//     vector<string> readBinaryWatch(int turnedOn) {
//         solve(0,0,0,turnedOn);
//         return res;
//     }
// };
// //not done
// // vector<string> readBinaryWatch(int num) {   // let num be 6
// //     int mask = 1 << 10;                     // mask = "10000000000
// //     vector<string>ans;
// //     for (int i = 0; i < mask; i++)
// //     {
// //         if (__builtin_popcount(i) == num)   // counts number of set bits
// //         {                                   // let i = "101001111"
// //             int hr = i >> 6;                // hours = "101" = 5
// //             int mn = (hr << 6)^i;           // hr<<6 ="101000000"  
// //                                             // xor of i and hr<<6 will give us minutes 
// // 			if (hr < 12 && mn < 60)
// //             {
// //                 ans.push_back(to_string(hr) + ((mn < 10) ? ":0" : ":") + to_string(mn));
// //             }
// //         }
// //     }
// //     return ans;
// // }




































