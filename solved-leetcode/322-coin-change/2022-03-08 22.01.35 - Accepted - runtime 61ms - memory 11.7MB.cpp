#define inf 10000007

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int temp = rec(coins, amount);
        if (temp >= inf) return -1;
        return temp;
    }

    int dp[10001];

    int rec(vector<int>& coins, int rem) {
        if (rem == 0) return 0;
        if (rem < 0) return inf;

        int& tc = dp[rem];
        if (tc != -1) return tc;
        tc = inf;
        for (auto coin : coins) {
            tc = min(tc, rec(coins, rem - coin) + 1);
        }

        return tc;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);