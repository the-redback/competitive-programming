#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = -1;
        int profit = 0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            if (prices[i] > mx)
                mx = prices[i];
            else
                profit = max(profit, mx - prices[i]);
        }
        return profit;
    }
};