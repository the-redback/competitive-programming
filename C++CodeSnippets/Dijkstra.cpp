#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int INF = 1e9;

vector<int> g[MAXN], cost[MAXN];
int dis[MAXN];
int par[MAXN];

struct node {
    int u, w;
    bool operator<(const node& p) const {
        return w > p.w;
    }
};

// If destination is -1, calculates distance to all the nodes.
void dijkstra(int source, int destination) {
    fill(dis, dis + MAXN, INF);
    memset(par, -1, sizeof(par));

    priority_queue<node> pq;
    pq.push({source, 0});
    dis[source] = 0;

    while (!pq.empty()) {
        int u = pq.top().u;
        int w = pq.top().w;
        pq.pop();

        if (w > dis[u]) continue;

        if (u == destination) return;

        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            int cost_uv = cost[u][i];

            if (dis[u] + cost_uv < dis[v]) {
                dis[v] = dis[u] + cost_uv;
                par[v] = u;
                pq.push({v, dis[v]});
            }
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);

        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int source, destination;
    cin >> source >> destination;

    dijkstra(source, destination);

    return 0;
}