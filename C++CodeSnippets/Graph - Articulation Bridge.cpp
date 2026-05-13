// Undirected Graph
/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define NN 10010

vector<int> e[NN];
vector<pair<int, int> > bridge;
int depth[NN];
int par[NN];
int low[NN];
bool color[NN];
int Time;

int dfs(int u) {
    low[u] = depth[u] = ++Time;
    color[u] = true;
    int i;
    for (i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (!color[v]) {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (depth[u] < low[v]) bridge.push_back(make_pair(u, v));
        } else if (v != par[u])
            low[u] = min(low[u], depth[v]);
    }
    return 0;
}

int articulation_Point(int n) {
    memset(depth, 0, sizeof(depth));
    memset(par, -1, sizeof(par));
    memset(low, 0, sizeof(low));
    memset(color, 0, sizeof(color));
    Time = 0;
    bridge.clear();

    for (int i = 0; i < n; i++)
        if (!color[i]) dfs(i);

    int ans = bridge.size();
    cout << ans << " critical links" << "\n";
    for (int i = 0; i < bridge.size(); i++) {
        cout << bridge[i].first << " - " << bridge[i].second << "\n";
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    cin >> tc;  // Test Case
    int i, j, k, l, m, n;
    int node, edge;
    while (tc--) {
        cin >> node >> edge;
        for (i = 0; i < edge; i++) {
            cin >> k >> l;
            e[k].push_back(l);
            e[l].push_back(k);
        }
        cout << "Case " << t++ << ":" << "\n";
        articulation_Point(node);
        for (i = 0; i <= node; i++) e[i].clear();
    }
    return 0;
}

/*
Input:
3

8 6
0 1
1 2
1 3
2 3
3 4
6 7

4 4
0 1
1 2
2 3
3 1

2 1
0 1

Output:
Case 1:
3 critical links
3 - 4
0 - 1
6 - 7

Case 2:
1 critical links
0 - 1

Case 3:
1 critical links
0 - 1
*/
