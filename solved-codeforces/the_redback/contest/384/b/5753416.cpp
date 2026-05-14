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

#define inf       10000000
#define mem(a, b) memset(a, b, sizeof(a))
#define NN        200000
// char a[1010][1010];
int main() {
    int tc, t = 1;
    int n, m, i, j, k, l, u, v;
    while (~scanf("%d%d%d", &n, &m, &k)) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) scanf("%d", &l);
        }
        l = (m * (m - 1)) / 2;
        printf("%d\n", l);
        if (k == 0) {
            for (i = 0; i < m - 1; i++)
                for (j = 0; j < m - i - 1; j++) printf("%d %d\n", j + 1, j + 2);
        } else {
            for (i = 0; i < m - 1; i++)
                for (j = 0; j < m - i - 1; j++) printf("%d %d\n", j + 2, j + 1);
        }
    }
    return 0;
}
