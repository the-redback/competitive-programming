class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int maxProfit(vector<int>& prices) {
        int mx = -1;
        int profit = 0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            if (prices[i] > mx)
                mx = prices[i];
            else if (profit < mx - prices[i])
                profit = mx - prices[i];
        }
        return profit;
    }
};