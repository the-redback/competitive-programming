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

const int MAXN = 100005;

vector<int> adj[MAXN];
int distanceArr[MAXN];
int parent[MAXN];

void bfs(int source, int numOfNodes) {
    memset(distanceArr, -1, sizeof(distanceArr));
    memset(parent, -1, sizeof(parent));

    queue<int> q;
    distanceArr[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (distanceArr[v] == -1) {
                distanceArr[v] = distanceArr[u] + 1;
                parent[v] = u;

                q.push(v);
            }
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove for directed graph
    }

    int source;
    cin >> source;
    bfs(source, nodes);

    return 0;
}
