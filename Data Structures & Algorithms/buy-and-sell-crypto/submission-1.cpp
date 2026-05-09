class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = prices[0];
        for(int i=0;i<prices.size();i++){
            maxProfit = max(maxProfit, prices[i] - bestBuy);
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};
