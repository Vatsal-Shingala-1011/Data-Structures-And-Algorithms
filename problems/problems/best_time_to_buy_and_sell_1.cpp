class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int bestprice=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            bestprice=min(bestprice,prices[i]);
            maxprofit=max(maxprofit,(prices[i]-bestprice));
        }
    return maxprofit;
    }
};