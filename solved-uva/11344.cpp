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
char a[100100];
int mod(int d) {
    int rem, i;
    rem = 0;
    for (i = 0; a[i]; i++) {
        rem = rem * 10 + a[i] - 48;
        rem = rem % d;
    }
    return rem;
}

main() {
    int tc, t = 1;
    int res, ret, i, j, k, n;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%s", &a);
        scanf("%d", &n);
        res = 0;
        while (n--) {
            scanf("%d", &k);
            if (!res) res = mod(k);
        }
        if (res)
            printf("%s - Simple.\n", a);
        else
            printf("%s - Wonderful.\n", a);
    }
    return 0;
}
