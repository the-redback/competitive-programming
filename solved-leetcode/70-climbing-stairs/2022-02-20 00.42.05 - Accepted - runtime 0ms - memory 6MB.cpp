class Solution {
public:
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return rec(n);
    }

    int dp[46];
    int rec(int n) {
        if (n == 0) return 1;
        if (n < 0) return 0;

        int& tc = dp[n];
        if (tc != -1) {
            return tc;
        }
        tc = rec(n - 1);
        tc += rec(n - 2);
        return tc;
    }
};