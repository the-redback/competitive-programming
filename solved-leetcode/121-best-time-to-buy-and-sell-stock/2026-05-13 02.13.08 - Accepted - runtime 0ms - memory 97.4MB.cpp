class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (auto num : prices) {
            min_price = min(min_price, num);
            max_profit = max(max_profit, num - min_price);
        }

        return max_profit;
    }
};