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

bool Flag[1000000];    // If a node already belongs to a scc or not.
int depth[1000000];    // The time when a node is visited
int Lowlink[1000000];  // A node connected with lowest timed node [if scc exist]
bool color[1000000];
int belong[1000000];     // A node blongs to which SCC
vector<int> G[1000000];  // Graph Store
stack<int> mystack;      // order of nodes r visited
int time, top, scc;

void tarjan(int u) {
    int v, i;
    depth[u] = Lowlink[u] = ++time;
    color[u] = true;
    mystack.push(u);
    Flag[u] = true;
    for (i = 0; i < G[u].size(); i++) {
        v = G[u][i];
        if (!color[v]) {
            tarjan(v);
            Lowlink[u] = min(Lowlink[u], Lowlink[v]);
        } else if (Flag[v])
            Lowlink[u] = min(Lowlink[u], depth[v]);
    }
    if (Lowlink[u] == depth[u]) {
        scc++;
        do {
            v = mystack.top(), mystack.pop();
            Flag[v] = false;
            belong[v] = scc;
        } while (u != v);
    }
}

void findSCC(int n) {
    mystack = stack<int>();
    scc = top = time = 0;
    memset(depth, -1, sizeof(depth));
    memset(Flag, 0, sizeof(Flag));
    memset(color, 0, sizeof(color));
    memset(Lowlink, 126, sizeof(Lowlink));
    for (int i = 1; i <= n; i++)
        if (!color[i]) tarjan(i);
}

int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int k, l;
        cin >> k >> l;
        G[k].push_back(l);
    }
    findSCC(node);
    cout << scc;

    return 0;
}

/*
Input:
5 5
1 2
2 3
3 4
5 2
3 5

Output:
3
*/
