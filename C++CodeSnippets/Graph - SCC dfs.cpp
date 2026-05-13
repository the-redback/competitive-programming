/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define NN 10010

int color[NN];
vector<int> arr;             // topological sorted node
vector<int> Graph[NN];       // Graph Before SCC
vector<int> transGraph[NN];  // Transpose Graph Before SCC
vector<int> newGraph[NN];    // New Graph After SCC
vector<pair<int, int> > v;   // Edges Before SCC
int id[NN];                  // Id of Nodes After SCC
int amount[NN];              // Amount of original node in a SCC node

int dfs_1st(int u) {
    color[u] = true;
    for (int i = 0; i < Graph[u].size(); i++) {
        if (!color[Graph[u][i]]) dfs_1st(Graph[u][i]);
    }
    arr.push_back(u);
}

int dfs_2nd(int u, int k) {
    color[u] = true;
    id[u] = k;

    for (int i = 0; i < transGraph[u].size(); i++) {
        if (!color[transGraph[u][i]]) dfs_2nd(transGraph[u][i], k);
    }
}

int scc(int n) {
    arr.clear();
    memset(color, 0, sizeof(color));
    int i, k, l;

    for (i = 1; i <= n; i++)  // Topological Sort
        if (color[i] == 0) dfs_1st(i);

    reverse(arr.begin(), arr.end());

    memset(id, -1, sizeof(id));
    memset(color, 0, sizeof(color));
    k = 0;

    for (i = 0; i < arr.size(); i++) {  // Identify SCC
        if (!color[arr[i]]) {
            dfs_2nd(arr[i], k + 1);
            amount[id[arr[i]]] = 1;  // Amount of actual node
            // in SCC node
            k++;
        } else
            amount[id[arr[i]]]++;
    }

    int node = k;  // Number of SCC node

    for (i = 0; i < v.size(); i++) {  // Build SCC graph
        k = v[i].first;
        l = v[i].second;

        if (id[k] != id[l]) newGraph[id[k]].push_back(id[l]);
    }

    return node;  // Number of SCC node.
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    int i, k, l, m, n;

    cin >> tc;  // Test Case
    while (tc--) {
        cin >> n >> m;  // n=node, m=edge

        for (i = 0; i <= n; i++) {
            Graph[i].clear();
            transGraph[i].clear();
            newGraph[i].clear();
        }
        v.clear();

        for (i = 0; i < m; i++) {
            cin >> k >> l;
            Graph[k].push_back(l);
            transGraph[l].push_back(k);
            v.push_back(make_pair(k, l));
        }

        int sum = scc(n);
        cout << "Case " << t++ << ": " << sum << "\n";
    }
    return 0;
}

/*
=======[ input ]=======
2

4 4
1 2
2 1
3 4
4 3

3 3
1 2
2 3
3 1

=======[ output ]=======
Case 1: 2
Case 2: 1
*/
