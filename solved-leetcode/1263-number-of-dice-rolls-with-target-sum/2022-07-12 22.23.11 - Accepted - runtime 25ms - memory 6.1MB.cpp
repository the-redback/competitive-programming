#include <cstring>

using namespace std;

int mod = 1000000007;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        K = k;
        return rec(n, target);
    }

    int K;

    int dp[31][1001];

    int rec(int n, int target) {
        if (n == 0) {
            if (target == 0) return 1;
            return 0;
        }

        int& tc = dp[n][target];
        if (tc != -1) return tc;
        tc = 0;

        for (int i = 1; i <= K; i++) {
            if (target >= i) tc = (tc + rec(n - 1, target - i) % mod) % mod;
        }
        return tc;
    }
};