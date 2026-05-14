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

#define mem(a, b) memset(a, b, sizeof(a))
#define pb        push_back
#define pp        pop_back
#define inf       10000000
#define NN        2000100
char a[NN];

main() {
    int t, tc;
    int i, j, k, l;
    int res, u, w, p, n, x, y, z, m, q;
    // cin>>tc;
    while (~scanf("%d%d", &n, &m)) {
        if (ceil((double)n / (m + 1)) > 1)
            puts("-1");
        else if (ceil((double)m / (n + 1)) > 2)
            puts("-1");
        else if (n > m) {
            i = 0;
            for (j = m; j >= 0; j--) {
                k = ceil((double)n / (j + 1));
                n -= k;
                while (k--) {
                    a[i++] = '0';
                }
                if (j) a[i++] = '1';
            }
            a[i] = 0;
            puts(a);
        } else {
            i = 0;
            for (j = n; j >= 0; j--) {
                k = ceil((double)m / (j + 1));
                m -= k;
                while (k--) {
                    a[i++] = '1';
                }
                if (j) a[i++] = '0';
            }
            a[i] = 0;
            puts(a);
        }
    }
    return 0;
}
