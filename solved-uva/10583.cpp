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
#define NN        50000
int prnt[NN + 7];
int a[NN + 7];
int root(int n) {
    if (prnt[n] == n) return n;
    return root(prnt[n]);
}

int main() {
    // freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    // ios_base::sync_with_stdio(false);
    int i, j, k, l, n, r, c, count;
    int tc, t = 1;
    // scanf("%d",&tc);
    while (~scanf("%d%d", &n, &r)) {
        if (n == 0 && r == 0) return 0;
        for (i = 1; i <= n; i++) prnt[i] = i;
        while (r--) {
            scanf("%d%d", &k, &l);
            int u = root(k);
            int v = root(l);
            if (u != v) prnt[u] = v;
        }
        mem(a, 0);
        count = 0;
        for (i = 1; i <= n; i++) {
            int u = root(i);
            if (a[u] == 0) count++;
            a[u] = 1;
        }
        printf("Case %d: %d\n", t++, count);
    }
    return 0;
}
