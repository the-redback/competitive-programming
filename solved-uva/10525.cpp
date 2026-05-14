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

#define inf       1000000000
#define mem(a, b) memset(a, b, sizeof(a))
#define NN        300
int a[NN + 7][NN + 7];
int d[NN + 7][NN + 7];
main() {
    // freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    // ios_base::sync_with_stdio(false);
    int i, j, k, l, n, r, c, u, v, w;
    int tc, t = 1, m;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &r);
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) a[i][j] = d[i][j] = inf;
            a[i][i] = d[i][i] = 0;
        }
        while (r--) {
            scanf("%d%d%d%d", &u, &v, &k, &l);
            if (k < a[u][v]) {
                a[u][v] = a[v][u] = k;
                d[u][v] = d[v][u] = l;
            } else if (k == a[u][v])
                d[u][v] = d[v][u] = min(d[u][v], l);
        }
        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++) {
                    if (a[i][j] > a[i][k] + a[k][j]) {
                        a[i][j] = a[i][k] + a[k][j];
                        d[i][j] = d[i][k] + d[k][j];
                    } else if (a[i][j] == a[i][k] + a[k][j]) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
        if (t != 1) puts("");
        t++;
        scanf("%d", &r);
        while (r--) {
            scanf("%d%d", &u, &v);
            k = d[u][v];
            if (k >= inf)
                puts("No Path.");
            else
                printf("Distance and time to reach destination is %d & %d.\n", d[u][v], a[u][v]);
        }
    }
    return 0;
}
