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
#define NN        1050
#define MAX       1000000

bool Flag[MAX];     // If a node already belongs to a scc or not.
int depth[MAX];     // The time when a node is visited
int Lowlink[MAX];   // A node connected with lowest timed node [if scc exist]
bool color[MAX];
int belong[MAX];      // A node blongs to which SCC
vector<int> G[MAX];   // Graph Store
stack<int> mystack;   // order of nodes r visited
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
    mem(depth, -1);
    mem(Flag, 0);
    mem(color, 0);
    mem(Lowlink, 126);
    for (int i = 1; i <= n; i++)
        if (!color[i]) tarjan(i);
}

int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int k, l;
        cin >> k >> l;
        G[k].pb(l);
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
