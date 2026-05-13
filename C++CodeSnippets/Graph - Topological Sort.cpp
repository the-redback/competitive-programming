#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;

vector<int> g[MAXN];
vector<int> topo;
int visited[MAXN];

bool hasCycle = false;

void dfs(int u) {
    visited[u] = 1;

    for (int v : g[u]) {
        if (visited[v] == 0) {
            dfs(v);
        } else if (visited[v] == 1) {
            hasCycle = true;
            return;
        }
    }
    visited[u] = 2;
    topo.push_back(u);
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= nodes; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    if (hasCycle) {
        cout << "IMPOSSIBLE\n";
    } else {
        reverse(topo.begin(), topo.end());
        for (int node : topo) {
            cout << node << '\n';
        }
    }
    return 0;
}
