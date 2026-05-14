#include <vector>
using namespace std;

int inf = 100000007;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += stones[i];
            prefix[i] = sum;
        }

        K = k;
        memset(dp, -1, sizeof(dp));
        return rec(0, n - 1, 1);
    }

    int prefix[33];
    int K;
    int dp[33][33][33];

    int rec(int i, int j, int piles) {
        if (i == j) {
            if (piles == 1) return 0;
            return inf;
        }

        int& tc = dp[i][j][piles];
        if (tc != -1) return tc;

        if (piles == 1) {
            int cost = prefix[j];
            if (i != 0) cost -= prefix[i - 1];
            return tc = rec(i, j, K) + cost;
        } else {
            int cost = inf;
            for (int mid = i; mid < j; mid++) {
                cost = min(cost, rec(i, mid, 1) + rec(mid + 1, j, piles - 1));
            }
            return tc = cost;
        }
    }
};