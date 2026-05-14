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

long long dp[(1 << 20) + 10];
int a[25][25];
int n;
long long call(int mask, int r) {
    if (r >= n) {
        if (mask == (1 << n) - 1)
            return 1;
        else
            return 0;
    }
    long long& t = dp[mask];
    if (t != -1) return t;
    int i;
    long long sum = 0;
    for (i = 0; i < n; i++) {
        if (!(mask & 1 << i) && a[r][i] == 1) sum += call(mask | 1 << i, r + 1);
    }
    return t = sum;
}

int main() {
    int tc, t = 1;
    int i, j;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
        memset(dp, -1, sizeof(dp));
        long long sum = call(0, 0);
        printf("%lld\n", sum);
    }
}
