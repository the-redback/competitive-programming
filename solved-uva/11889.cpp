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

main() {
    int n, k, i, m, c;
    int tc, t = 1;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &c);
        if (c % n != 0)
            printf("NO SOLUTION\n");
        else {
            k = c / n;
            for (i = k; i <= c; i += k)
                if ((i / __gcd(i, n)) * n == c) break;
            printf("%d\n", i);
        }
    }
    return 0;
}
