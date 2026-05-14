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
int a[20];
int n;
int dp[(1 << 15) + 10][91];
int call(int mask, int r, int v) {
    if (mask == (1 << n) - 1) {
        if (r == 3 && v >= 20)
            return 1;
        else
            return 0;
    }
    int& t = dp[mask][v];
    if (t != -1) return t;
    if (r == 3) {
        if (v >= 20)
            return call(mask, 0, 0) + 1;
        else
            return call(mask, 0, 0);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (!(mask & 1 << i)) sum = max(sum, call(mask | 1 << i, r + 1, v + a[i]));
    }
    return t = sum;
}
int main() {
    int tc, t = 1;
    int i, j, k;
    while (~scanf("%d", &n)) {
        if (n == 0) return 0;
        for (i = 0; i < n; i++) scanf("%d", &a[i]);
        memset(dp, -1, sizeof(dp));
        int sum = call(0, 0, 0);
        printf("Case %d: %d\n", t++, sum);
    }
    return 0;
}
