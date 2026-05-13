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
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int dist[MAXN];
int parent[MAXN];

void bfs(int source, int /*numOfNodes*/) {
    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));

    queue<int> q;
    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
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
        adj[v].push_back(u);  // Remove for directed graph
    }

    int source;
    cin >> source;
    bfs(source, nodes);
    cout << "Node : Distance from Source\n";

    for (int node = 1; node <= nodes; node++) {
        cout << node << " : " << dist[node] << '\n';
    }

    return 0;
}

/*
Sample Graph
------------
1 -- 2 -- 4
|    |    |
3    5 -- 6
 \--------/

Sample Input
------------
6 7
1 2
1 3
2 4
2 5
3 6
4 5
5 6
1

Sample Output
------------
Node : Distance from Source
1 : 0
2 : 1
3 : 1
4 : 2
5 : 2
6 : 2
 */
