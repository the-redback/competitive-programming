#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[10010];
    const int inf = 1e7;

    int rec(int rem, vector<int> &coins) {
        if (rem == 0)
            return 0;
        if (rem < 0)
            return inf;

        int &tc = dp[rem];
        if (tc != -1)
            return tc;

        tc = inf;
        for (auto coin: coins) {
            tc = min(tc, rec(rem - coin, coins) + 1);
        }
        return tc;
    }

    int coinChange(vector<int> &coins, int amount) {
        memset(dp, -1, sizeof(dp));

        int ans = rec(amount, coins);
        if (ans >= inf)
            return -1;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int ans = sol.coinChange(coins, amount);
    cout << "Minimum Coins Needed: " << ans << '\n';
    return 0;
}

/*
Sample Input:
coins = [1, 2, 5]
amount = 11

Sample Output:
3

Explanation:
11 = 5 + 5 + 1
*/
