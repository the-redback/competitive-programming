// The Graph is bi-directional/undirected.
/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define NN 10010

vector<int> e[NN];
int depth[NN];
int par[NN];
int low[NN];
bool color[NN], Flag[NN];
int Time;

void dfs(int u) {
    low[u] = depth[u] = ++Time;
    color[u] = true;
    int i, call = 0;
    for (i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (!color[v]) {
            call++;
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (depth[u] <= low[v]) Flag[u] = true;
        } else if (v != par[u])
            low[u] = min(low[u], depth[v]);
    }
    if (par[u] == -1) Flag[u] = (call > 1);
}

int articulation_Point(int n) {
    memset(depth, 0, sizeof(depth));
    memset(par, -1, sizeof(par));
    memset(low, 0, sizeof(low));
    memset(color, 0, sizeof(color));
    memset(Flag, 0, sizeof(Flag));
    Time = 0;

    for (int i = 1; i <= n; i++)
        if (!color[i]) dfs(i);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (Flag[i]) ans++;
    return ans;
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

        int ans = articulation_Point(node);
        cout << "Case " << t++ << ": " << ans << "\n";

        for (i = 0; i <= node; i++) e[i].clear();
    }
    return 0;
}

/*
Input:
3     //Test Case

5 4   //node edge
2 1
1 3
5 4
4 1

3 3
1 2
2 3
1 3

5 5
1 2
2 3
3 4
2 5
5 3

Output:
Case 1: 2
Case 2: 0
Case 3: 2
*/
