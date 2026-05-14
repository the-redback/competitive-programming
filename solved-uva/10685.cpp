
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
#define NN        5000

map<string, int> mp;
int view[NN + 7];
int pr[NN + 7];
string s, ss;
char a[100], b[100];

int root(int n) {
    if (pr[n] == n) return n;
    return root(pr[n]);
}

main() {
    int tc, t = 1;
    int i, j, k, l, m, n, count;
    // scanf("%d",&tc);
    while (~scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) return 0;
        for (i = 1; i <= n; i++) {
            scanf("%s", &a);
            s.assign(a);
            mp[s] = i;
            pr[i] = i, view[i] = 0;
        }
        while (m--) {
            scanf("%s%s", &a, &b);
            s.assign(a);
            ss.assign(b);
            int u = root(mp[s]);
            int v = root(mp[ss]);
            if (u != v) {
                pr[u] = v;
            }
        }
        count = 0;
        for (i = 1; i <= n; i++) {
            int u = root(i);
            view[u]++;
            count = max(count, view[u]);
        }
        printf("%d\n", count);
        mp.clear();
    }
    return 0;
}
