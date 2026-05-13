#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;

int parent[MAXN];
int rank[MAXN];

struct edge {
    int u, v, w;
};

vector<edge> edges;

bool compare(edge a, edge b) { return a.w > b.w; }

void init(int nodes) {
    for (int i = 1; i <= nodes; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);
    }

    return parent[u];
}

void Union(int u, int v) {
    if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;

        if (rank[u] == rank[v]) {
            rank[v]++;
        }
    }
}

int mst(int nodes) {
    init(nodes);

    sort(edges.begin(), edges.end(), compare);

    int removedCost = 0;

    for (edge e : edges) {
        int u = find(e.u);
        int v = find(e.v);

        if (u != v) {
            Union(u, v);
        } else {
            removedCost += e.w;
        }
    }

    return removedCost;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int nodes, edgesCount;
        cin >> nodes >> edgesCount;

        edges.clear();

        for (int i = 0; i < edgesCount; i++) {
            edge e;

            cin >> e.u >> e.v >> e.w;

            edges.push_back(e);
        }

        cout << mst(nodes) << '\n';
    }

    return 0;
}
