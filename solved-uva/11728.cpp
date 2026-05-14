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
#define inf       HUGE_VAL
#define mem(a, b) memset(a, b, sizeof(a))
#define MM        1001
int a[MM + 7];
int b[MM + 7];

void go(void) {
    int i, j, k;
    for (i = 1; i < MM; i++) {
        for (j = i; j < MM; j += i) {
            a[j] += i;
        }
    }
    mem(b, -1);
    for (i = 1; i < MM; i++) {
        k = a[i];
        if (k < MM) b[k] = max(i, b[k]);
    }
    return;
}

main() {
    go();
    int n, k;
    int tc, t = 1;
    while (~scanf("%d", &n)) {
        if (n == 0) return 0;
        printf("Case %d: %d\n", t++, b[n]);
    }
    return 0;
}
