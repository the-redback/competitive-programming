#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int low = prices[0];

        for (auto p : prices) {
            low = min(low, p);
            profit = max(profit, p - low);
        }

        return profit;
    }
};