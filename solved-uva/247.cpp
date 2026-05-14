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

#define ppb       pop_back
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1000000000
#define eps       1e-9
#define NN        100

vector<int> arr;
vector<int> e[NN];
vector<int> te[NN];
vector<string> ans[NN];
vector<string> vs;
map<string, int> mp;
int color[NN];

void dfs1(int u) {
    color[u] = true;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (!color[v]) dfs1(v);
    }
    arr.pb(u);
    return;
}

void dfs2(int u, int flag) {
    color[u] = flag;
    for (int i = 0; i < te[u].size(); i++) {
        int v = te[u][i];
        if (!color[v]) dfs2(v, flag);
    }
    return;
}

string s, ss;

main() {
    // ios_base::sync_with_stdio(false);
    int t = 0, tc;
    int n, m, i, j, l;
    // cin>>tc;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) return 0;
        int r = 0;
        for (i = 0; i < m; i++) {
            cin >> s >> ss;
            if (mp.find(s) == mp.end()) {
                mp[s] = r++;
                vs.pb(s);
            }
            if (mp.find(ss) == mp.end()) {
                mp[ss] = r++;
                vs.pb(ss);
            }
            e[mp[s]].pb(mp[ss]);
            te[mp[ss]].pb(mp[s]);
        }
        mem(color, 0);
        for (i = 0; i < n; i++) {
            if (!color[i]) dfs1(i);
        }
        reverse(all(arr));
        int mx = -inf;
        r = 1;
        mem(color, 0);
        for (i = 0; i < arr.size(); i++) {
            if (!color[arr[i]]) {
                dfs2(arr[i], r++);
                mx = max(mx, r);
            }
        }
        for (i = 0; i < n; i++) {
            int u = color[i];
            ans[u].pb(vs[i]);
        }
        if (t) puts("");
        printf("Calling circles for data set %d:\n", ++t);
        for (i = 1; i < mx; i++) {
            for (j = 0; j < ans[i].size(); j++) {
                if (j) printf(", ");
                cout << ans[i][j];
            }
            puts("");
        }
        mp.clear();
        vs.clear();
        arr.clear();
        for (i = 0; i <= n; i++) {
            e[i].clear();
            te[i].clear();
            ans[i].clear();
        }
    }
    return 0;
}
