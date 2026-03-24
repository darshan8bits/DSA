class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            int profit = (prices[i] - minm > 0) ? (prices[i] - minm) : 0;
            maxProfit = max(maxProfit, profit);
            minm = min(minm, prices[i]);
        }
        return maxProfit;
    }
};
