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

main() {
    int a[1010];
    int n, m;
    int i, j, l, x, k, y, z;
    long long sum;
    while (~scanf("%d%d", &n, &m)) {
        memset(a, 0, sizeof(a));
        while (m--) {
            scanf("%d%d%d", &x, &y, &z);
            a[x] += z;
            a[y] -= z;
        }
        sum = 0;
        for (i = 0; i <= n; i++)
            if (a[i] > 0) sum += a[i];
        cout << sum << endl;
    }
    return 0;
}
