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

#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define NN        10010

vector<int> e[NN];
vector<pair<int, int> > bridge;
int dis[NN];
int par[NN];
int low[NN];
bool color[NN];
int Time;

int dfs(int u) {
    low[u] = dis[u] = ++Time;
    color[u] = true;
    int i;
    for (i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (!color[v]) {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (dis[u] < low[v]) bridge.pb(mp(min(u, v), max(u, v)));
        } else if (v != par[u])
            low[u] = min(low[u], dis[v]);
    }
    return 0;
}

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int articulation_Point(int n) {
    mem(dis, 0);
    mem(par, -1);
    mem(low, 0);
    mem(color, 0);
    Time = 0;
    bridge.clear();

    for (int i = 0; i < n; i++)
        if (!color[i]) dfs(i);

    int ans = bridge.size();
    printf("%d critical links\n", ans);
    sort(all(bridge), comp);
    for (int i = 0; i < bridge.size(); i++) printf("%d - %d\n", bridge[i].first, bridge[i].second);
    return 0;
}

main() {
    // ios_base::sync_with_stdio(false);
    int t = 1, tc;
    cin >> tc;  // Test Case
    int i, j, k, l, m, r, n;
    int node, edge;
    while (tc--) {
        scanf("%d", &node);
        for (i = 0; i < node; i++) {
            scanf("%d (%d)", &k, &r);
            while (r--) {
                scanf("%d", &l);
                e[k].pb(l);
            }
        }
        printf("Case %d:\n", t++);
        articulation_Point(node);
        for (i = 0; i <= node; i++) e[i].clear();
    }
    return 0;
}

/*
Input:
3

8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0

2
0 (1) 1
1 (1) 0

Output:
Case 1:
3 critical links
0 - 1
3 - 4
6 - 7
Case 2:
0 critical links
Case 3:
1 critical links
0 - 1
*/
