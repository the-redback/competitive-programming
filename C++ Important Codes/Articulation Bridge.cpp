//Undirected Graph
/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 10010

vector<int>e[NN];
vector< pair<int, int> >bridge;
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
            if (depth[u] < low[v])
                bridge.pb(mp(u, v));
        } else if (v != par[u])
            low[u] = min(low[u], depth[v]);
    }
    return 0;
}

int articulation_Point(int n) {
    mem(depth, 0);
    mem(par, -1);
    mem(low, 0);
    mem(color, 0);
    Time = 0;
    bridge.clear();

    for (int i = 0; i < n; i++)
        if (!color[i])
            dfs(i);

    int ans = bridge.size();
    printf("%d critical links\n", ans);
    for (int i = 0; i < bridge.size(); i++)
        printf("%d - %d\n", bridge[i].first, bridge[i].second);
    return 0;
}

main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    cin >> tc;        //Test Case
    int i, j, k, l, m, n;
    int node, edge;
    while (tc--) {
        cin >> node >> edge;
        for (i = 0; i < edge; i++) {
            cin >> k >> l;
            e[k].pb(l);
            e[l].pb(k);
        }
        printf("Case %d:\n", t++);
        articulation_Point(node);
        for (i = 0; i <= node; i++)
            e[i].clear();
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
