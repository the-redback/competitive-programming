#include <bits/stdc++.h>
using namespace std;

#define inf       10000000
#define mem(a, b) memset(a, b, sizeof(a))
#define NN        10010
int pr[NN + 7];

struct edge {
    int u, v, w;
};

vector<edge> e;
bool comp(edge n, edge m) { return n.w > m.w; }

int root(int n) {
    if (pr[n] == n) return n;
    return root(pr[n]);
}

int mst(int n) {
    int i, j, k;
    for (i = 0; i <= n; i++) pr[i] = i;
    sort(e.begin(), e.end(), comp);
    int count = 0, sum = 0;
    for (i = 0; i < e.size(); i++) {
        int u = root(e[i].u);
        int v = root(e[i].v);
        if (u != v) {
            pr[u] = v;
        } else
            sum += e[i].w;
    }
    return sum;
}

main() {
    // freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i, j, k, l, n, r, c, u, v, w;
    edge ed;
    int tc, t = 1, x = -1, m;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        while (m--) {
            cin >> ed.u >> ed.v >> ed.w;
            e.push_back(ed);
        }
        int sum = mst(n);
        cout << sum << "\n";
        e.clear();
    }
    cin >> n;

    return 0;
}
