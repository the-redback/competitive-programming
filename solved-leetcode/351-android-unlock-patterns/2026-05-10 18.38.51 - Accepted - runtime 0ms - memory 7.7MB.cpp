#include <cstring>

using namespace std;

class Solution {
public:
    int skip[10][10];
    int dp[10][1 << 10];
    int M, N;

    void prepare() {
        memset(skip, 0, sizeof(skip));
        memset(dp, -1, sizeof(dp));

        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[7][9] = skip[9][7] = 8;
        skip[9][3] = skip[3][9] = 6;

        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
    }

    int backtrack(int curr, int len, int mask) {
        if (len > N) return 0;

        int& tc = dp[curr][mask];
        if (tc != -1) {
            return tc;
        }

        tc = 0;
        if (len >= M) {
            tc++;
        }

        for (int i = 1; i <= 9; i++) {
            if (mask & (1 << i))  // visited
                continue;

            int mid = skip[curr][i];
            if (mid == 0 || mask & (1 << mid)) {
                tc += backtrack(i, len + 1, mask | (1 << i));
            }
        }

        return tc;
    }

    int numberOfPatterns(int m, int n) {
        prepare();
        M = m, N = n;

        int ans = 0;
        for (int i = 1; i <= 9; i++) ans += backtrack(i, 1, 1 << i);

        return ans;
    }
};