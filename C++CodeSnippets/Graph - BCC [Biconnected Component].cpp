/*Undirected Graph.

One Biconnected component means a region where nodes
will Be connected after deleting exactly one edge.*/

/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

#define NN 10010

vector<int> Graph[NN];          // Graph Before BCC
vector<int> newGraph[NN];       // Graph after BCC
vector<pair<int, int> > edge;   // Input edges
stack<int> mystack;             // order of nodes r visited
int depth[NN];                  // The depth(time) when a node is visited
int par[NN];                    // Parent of node
int low[NN];      // A node connected with lowest timed node [if bcc exist]
bool color[NN];   // Color if a node is visited or not
int belong[NN];   // A node blongs to which BCC
int Time, bcc;

int dfs(int u) {
    low[u] = depth[u] = ++Time;
    color[u] = true;
    mystack.push(u);
    int i, v;
    for (i = 0; i < Graph[u].size(); i++) {
        v = Graph[u][i];
        if (!color[v]) {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (v != par[u])
            low[u] = min(low[u], depth[v]);
    }
    if (low[u] == depth[u]) {
        bcc++;
        do {
            v = mystack.top();
            mystack.pop();
            belong[v] = bcc;
        } while (u != v);
    }
    return 0;
}

int findbcc(int n) {
    memset(depth, 0, sizeof(depth));
    memset(par, -1, sizeof(par));
    memset(low, 0, sizeof(low));
    memset(color, 0, sizeof(color));
    mystack = stack<int>();
    Time = bcc = 0;

    for (int i = 0; i < n; i++)   // lowest node=0
        if (!color[i]) dfs(i);
    int Highest_Node = bcc;

    for (int i = 0; i < edge.size(); i++) {
        int u = belong[edge[i].first];
        int v = belong[edge[i].second];
        if (u != v) {
            newGraph[u].push_back(v);
            newGraph[v].push_back(u);
        }
    }
    return Highest_Node;
}

int Print_NewGraph(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {   // lowest node=1
        if (newGraph[i].size()) {
            printf("%d :", i);
            for (j = 0; j < newGraph[i].size(); j++)
                printf(" %d", newGraph[i][j]);
            puts("");
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    cin >> tc;   // Test Case
    int i, j, k, l, m, n;
    int e;
    while (tc--) {
        cin >> n >> e;
        for (i = 0; i < e; i++) {
            cin >> k >> l;
            Graph[k].push_back(l);
            Graph[l].push_back(k);
            edge.push_back(make_pair(k, l));
        }
        printf("Case %d:\n", t++);
        k = findbcc(n);
        Print_NewGraph(k);
        for (i = 0; i <= n; i++) Graph[i].clear(), newGraph[i].clear();
        edge.clear();
    }
    return 0;
}

/*
Input:
2

4 4
0 1
1 2
2 3
3 1

6 6
0 1
1 2
1 3
3 4
4 5
1 4

Output:

Case 1:
1 : 2
2 : 1

Case 2:
1 : 3
2 : 3
3 : 4 1 2
4 : 3

*/
