#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int dp[10010];
    const int inf = 1e7;

    int rec(int rem, vector<int>& coins) {
        if (rem == 0) return 0;
        if (rem < 0) return inf;

        int& tc = dp[rem];
        if (tc != -1) return tc;

        tc = inf;
        for (auto coin : coins) {
            tc = min(tc, rec(rem - coin, coins) + 1);
        }
        return tc;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));

        int ans = rec(amount, coins);
        if (ans >= inf) return -1;
        return ans;
    }
};