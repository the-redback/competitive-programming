// The Graph is bi-directional/undirected.
/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
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
            if (depth[u] <= low[v])
                Flag[u] = true;
        } else if (v != par[u])
            low[u] = min(low[u], depth[v]);
    }
    if (par[u] == -1)
        Flag[u] = (call > 1);
}

int articulation_Point(int n) {
    mem(depth, 0);
    mem(par, -1);
    mem(low, 0);
    mem(color, 0);
    mem(Flag, 0);
    Time = 0;

    for (int i = 1; i <= n; i++)
        if (!color[i])
            dfs(i);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (Flag[i])
            ans++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    cin >> tc;   // Test Case
    int i, j, k, l, m, n;
    int node, edge;
    while (tc--) {
        cin >> node >> edge;
        for (i = 0; i < edge; i++) {
            cin >> k >> l;
            e[k].pb(l);
            e[l].pb(k);
        }

        int ans = articulation_Point(node);
        printf("Case %d: %d\n", t++, ans);

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
