class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int peak, valley;
        for (int i = 0; i < prices.size() - 1; i++) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};