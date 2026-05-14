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
#define NN        50
int a[NN + 7][NN + 7];
map<string, int> mp;
string s, ss;

int warsh(int n) {
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    int ret = -inf;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) ret = max(ret, a[i][j]);

    return ret;
}

main() {
    // freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    // ios_base::sync_with_stdio(false);
    int i, j, k, l, n, r, c;
    int tc, t = 1;
    // cin>>tc;
    while (~scanf("%d%d", &n, &r)) {
        if (n == 0 && r == 0) return 0;
        k = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) a[i][j] = (i == j) ? 0 : inf;
        for (i = 0; i < r; i++) {
            cin >> s >> ss;
            if (mp.find(s) == mp.end()) mp[s] = k++;
            if (mp.find(ss) == mp.end()) mp[ss] = k++;
            a[mp[s]][mp[ss]] = 1;
            a[mp[ss]][mp[s]] = 1;
        }
        int ret = warsh(n);
        if (ret >= inf)
            printf("Network %d: DISCONNECTED\n", t++);
        else
            printf("Network %d: %d\n", t++, ret);
        puts("");
        mp.clear();
    }
    return 0;
}
