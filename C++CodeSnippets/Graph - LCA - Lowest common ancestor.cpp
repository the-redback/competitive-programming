/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */

#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;

#define NN 10010

// cout << setfill('0') << setw(3) << a << endl;
// cout << fixed << setprecision(20) << a << endl;

ll par[NN];        // Parent
ll level[NN];      // level in tree
bool color[NN];    // DFS color
ll P[NN][20];      // Sparse table
vector<ll> g[NN];  // Gragh store

// 1 based index.

void dfs(ll u) {
    ll i, v;
    color[u] = 1;

    for (i = 0; i < g[u].size(); i++) {
        v = g[u][i];
        if (color[v] == 0) {
            par[v] = u;
            level[v] = level[u] + 1;
            dfs(v);
        }
    }
    return;
}

ll lca_query(ll p, ll q) {
    if (level[p] < level[q]) swap(p, q);
    ll i, j, k, log;
    log = 1;
    while (1) {
        ll next = log + 1;
        if (1 << next > level[p]) break;
        log++;
    }
    for (i = log; i >= 0; i--)
        if (level[p] - (1 << i) >= level[q]) p = P[p][i];
    if (p == q) return p;
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i]) p = P[p][i], q = P[q][i];
    return par[p];
}

void lca_init(ll n) {
    memset(color, 0, sizeof(color));
    memset(P, -1, sizeof(P));
    level[1] = 0;
    dfs(1);

    ll i, j;

    for (i = 1; i <= n; i++) P[i][0] = par[i];

    for (j = 1; 1 << j <= n; j++)
        for (i = 1; i <= n; i++)
            if (P[i][j - 1] != -1) P[i][j] = P[P[i][j - 1]][j - 1];

    return;
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tc;
    cin >> tc;
    ll i, j, k, l, n;
    ll r;
    while (tc--) {
        cin >> n;
        for (i = 0; i <= n; i++) g[i].clear();

        for (i = 0; i < n - 1; i++) {
            cin >> k >> l;
            g[k].push_back(l);
            g[l].push_back(k);
        }
        lca_init(n);

        cin >> r;
        while (r--) {
            cin >> k >> l;
            cout << lca_query(k, l) << "\n";
        }
        // if(tc)
        cout << "" << "\n";
    }
    return 0;
}

/*
Input:
1

6
1 2
2 4
2 5
1 3
3 6

4
1 2
3 2
5 4
6 5

Output:
1
1
2
1
*/
