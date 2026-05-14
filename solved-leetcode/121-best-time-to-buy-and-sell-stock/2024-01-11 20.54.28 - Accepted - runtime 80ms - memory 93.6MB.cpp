class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int low = prices[0];
        for(auto p : prices){
            low = min (low, p);
            profit = max(profit, p-low);
        }

        return profit;
    }
};