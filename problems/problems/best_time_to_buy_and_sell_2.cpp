// //self
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxprofit=0;
//         int totalprofit=0;
//         int temp;
//         int bestprice=INT_MAX;
//         for(int i=0;i<prices.size();i++)
//         {
//             bestprice=min(bestprice,prices[i]);
//             temp=max(maxprofit,(prices[i]-bestprice));
//             if(maxprofit!=temp) //if temp is updated
//             {
//               totalprofit=totalprofit + temp ; 
//               bestprice=prices[i];
//               maxprofit=0;  
//             }
//         }
//     return totalprofit;
//     }
// };

//easy way 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        for(int i = 0 ; i < n-1 ; i++){
            if(prices[i] < prices[i+1]){
                ans += prices[i+1] - prices[i];
            }
        }
        return ans;
    }
};