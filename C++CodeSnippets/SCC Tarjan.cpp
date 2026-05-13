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

const int MAXN = 1000000;

vector<int> g[MAXN + 1];

int discovery[MAXN + 1];
int low[MAXN + 1];
int component[MAXN + 1];

bool visited[MAXN + 1];
bool inStack[MAXN + 1];

stack<int> st;

int timer;
int sccCount;

void tarjan(int u) {
    discovery[u] = low[u] = ++timer;

    visited[u] = true;
    inStack[u] = true;

    st.push(u);

    for (int v: g[u]) {
        if (!visited[v]) {
            tarjan(v);

            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], discovery[v]);
        }
    }

    if (low[u] == discovery[u]) {
        sccCount++;
        while (true) {
            int v = st.top();
            st.pop();
            inStack[v] = false;
            component[v] = sccCount;

            if (u == v) {
                break;
            }
        }
    }
}

void findSCC(int nodes) {
    timer = 0;
    sccCount = 0;

    memset(visited, false, sizeof(visited));
    memset(inStack, false, sizeof(inStack));

    while (!st.empty()) {
        st.pop();
    }

    for (int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            tarjan(i);
        }
    }
}

int main() {
    // Tarjan SCC

    int nodes, edges;

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;

        cin >> u >> v;

        g[u].push_back(v);
    }

    findSCC(nodes);

    cout << "Number of SCC: "
            << sccCount
            << '\n';

    cout << "\nNode -> Component\n";

    for (int i = 1; i <= nodes; i++) {
        cout << i
                << " -> "
                << component[i]
                << '\n';
    }

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
