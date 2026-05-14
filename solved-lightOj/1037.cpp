/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
using namespace std;
#define inf HUGE_VAL

int b[20];
int a[20][20];
int n;
int dp[(1 << 15) + 10];
int call(int mask) {
    if (mask == (1 << n) - 1) {
        return 0;
    }
    int& t = dp[mask];
    if (t != -1) return t;
    int sum = inf;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (!(mask & 1 << i)) {
            int S = call(mask | 1 << i) + b[i];
            sum = min(sum, S);
        } else {
            for (int j = 0; j < n; j++) {
                if (!(mask & 1 << j) && a[i][j] != 0) {
                    int S = call(mask | 1 << j) + ceil(b[j] / (double)a[i][j]);
                    sum = min(sum, S);
                }
            }
        }
    }
    return t = sum;
}

int main() {
    int tc, t = 1;
    int i, j, k;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d", &b[i]);
        getchar();
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                char ch;
                scanf("%c", &ch);
                a[i][j] = ch - '0';
            }
            getchar();
        }
        memset(dp, -1, sizeof(dp));
        int sum = call(0);
        printf("Case %d: %d\n", t++, sum);
    }
    return 0;
}
