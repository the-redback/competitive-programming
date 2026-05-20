#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*                  EULER PATH vs EULER CIRCUIT
    =========================================================
    Euler Path:
    ------------
    A traversal that uses every edge exactly once.
    Start node and end node can be DIFFERENT.

    Euler Circuit:
    ---------------
    A traversal that uses every edge exactly once
    AND returns back to the starting node.
    Start node and end node are SAME.

    =========================================================
                    HIERHOLZER ALGORITHM
    =========================================================
    Same algorithm works for BOTH:
        - Euler Path
        - Euler Circuit

    Core idea:
        - Keep consuming unused edges
        - Add node during backtracking
        - Reverse answer at the end

    Complexity:
        O(E), E = number of edges
*/
const int MAXN = 100005;
vector<int> g[MAXN];
vector<int> ans;

void dfs(int u) {
    while (!g[u].empty()) {
        int v = g[u].back();
        g[u].pop_back();

        dfs(v);
    }
    ans.push_back(u);
}

vector<int> getEulerTraversal(int start) {
    ans.clear();
    dfs(start);
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    /* EULER PATH
        Edges:
            1 -> 2
            2 -> 3
            3 -> 1
            1 -> 4
            4 -> 5
            5 -> 2

        One valid path:
            1 4 5 2 3 1 2
    */

    g[1].push_back(2);
    g[2].push_back(3);
    g[3].push_back(1);

    g[1].push_back(4);
    g[4].push_back(5);
    g[5].push_back(2);

    vector<int> path = getEulerTraversal(1);
    cout << "Euler Path:\n";
    for (auto u : path) {
        cout << u << " ";
    }
    cout << "\n\n";

    // Clear Graph
    for (int i = 0; i < MAXN; i++) {
        g[i].clear();
    }

    /* EULER CIRCUIT
        Edges:
            1 -> 2
            2 -> 3
            3 -> 1
            1 -> 4
            4 -> 5
            5 -> 1

        One valid circuit:
            1 4 5 1 2 3 1
    */

    g[1].push_back(2);
    g[2].push_back(3);
    g[3].push_back(1);

    g[1].push_back(4);
    g[4].push_back(5);
    g[5].push_back(1);

    vector<int> circuit = getEulerTraversal(1);
    cout << "Euler Circuit:\n";
    for (auto u : circuit) {
        cout << u << " ";
    }
    cout << "\n";
    return 0;
}
