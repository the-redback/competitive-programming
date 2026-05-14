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

int call(int n, int r) {
    int i, sum = 1, k, t = 0, f = 0;
    for (i = n - r + 1; i <= n; i++) {
        k = i;
        while (!(k % 2)) {
            k /= 2;
            t++;
        }
        while (!(k % 5)) {
            k /= 5;
            f++;
        }
        sum = (sum * k) % 100;
    }
    for (i = f + 1; i <= t; i++) sum = (sum * 2) % 100;
    for (i = t + 1; i <= f; i++) sum = (sum * 5) % 100;
    return sum % 100;
}

main() {
    int tc, t = 1;
    int i, j, k, l;
    // scanf("%d",&tc);
    while (~scanf("%d%d", &k, &l)) {
        printf("%d\n", call(k, l) % 10);
    }
    return 0;
}
