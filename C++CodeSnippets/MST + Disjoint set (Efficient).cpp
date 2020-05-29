#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define inf       10000000
#define mem(a, b) memset(a, b, sizeof(a))
#define NN        10010
int root[NN + 7];
int rank[NN + 7];

struct edge {
    int u, v, w;
};

vector<edge> e;

bool comp(edge n, edge m) { return n.w > m.w; }

void init(int n) {
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        rank[i] = 0;
    }
}

int find(int u) {
    if (u != root[u]) root[u] = find(root[u]);
    return root[u];
}

void Union(int u, int v) {
    if (rank[u] > rank[v])
        root[v] = u;
    else {
        root[u] = v;
        if (rank[u] == rank[v]) rank[v]++;
    }
}

int mst(int n) {
    init(n);
    int i, j, k;
    sort(e.begin(), e.end(), comp);
    int count = 0, sum = 0;
    for (i = 0; i < e.size(); i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            Union(u, v);
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
