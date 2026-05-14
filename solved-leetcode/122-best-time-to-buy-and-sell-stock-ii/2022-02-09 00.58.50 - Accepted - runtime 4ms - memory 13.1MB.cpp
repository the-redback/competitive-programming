#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int peak, valley;
        for (int i = 1; i < prices.size(); i++) {
            if (prices.at(i) > prices.at(i - 1)) maxprofit += prices.at(i) - prices.at(i - 1);
        }
        return maxprofit;
    }
};