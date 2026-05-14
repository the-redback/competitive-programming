class Solution {
public:
    int dp[13][10010];
    const int inf = 1e7;

    int rec(int pos, int rem, vector<int>& coins) {
        if (rem == 0) return 0;
        if (rem < 0 || pos == coins.size()) return inf;

        int& tc = dp[pos][rem];
        if (tc != -1) return tc;

        tc = rec(pos + 1, rem, coins);
        tc = min(tc, rec(pos, rem - coins[pos], coins) + 1);
        return tc;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));

        int ans = rec(0, amount, coins);
        if (ans >= inf) return -1;
        return ans;
    }
};