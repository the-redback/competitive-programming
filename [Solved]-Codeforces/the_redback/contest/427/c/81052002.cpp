/***
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://maruftuhin.com
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        100010

// clang-format off
#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cout<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cout << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros
// clang-format on

int         color[NN];
vector<int> arr;              // topological sorted node
vector<int> Graph[NN];        // Graph Before SCC
vector<int> transGraph[NN];   // Transpose Graph Before SCC
int         id[NN];           // Id of Nodes After SCC
// in a SCC node

void dfs_1st(int u) {
    color[u] = true;
    for (int i = 0; i < Graph[u].size(); i++) {
        if (!color[Graph[u][i]]) dfs_1st(Graph[u][i]);
    }
    arr.pb(u);
}

void dfs_2nd(int u, int k) {
    color[u] = true;
    id[u]    = k;

    for (int i = 0; i < transGraph[u].size(); i++) {
        if (!color[transGraph[u][i]]) dfs_2nd(transGraph[u][i], k);
    }
}

int scc(int n) {
    arr.clear();
    mem(color, 0);
    int i, j, k, l;

    for (i = 1; i <= n; i++)   // Topological Sort
        if (color[i] == 0) dfs_1st(i);

    reverse(all(arr));

    mem(id, -1);
    mem(color, 0);
    k = 0;

    for (i = 0; i < arr.size(); i++) {   // Identify SCC
        if (!color[arr[i]]) {
            dfs_2nd(arr[i], k + 1);
            // in SCC node
            k++;
        }
    }
    return k;   // Number of SCC node.
}

void solve(ll n) {
    ll i, j, k, l;
    ll m;

    vector<ll> arr(n + 10);
    vector<ll> mscc(n + 10);
    vector<ll> cnt(n + 10);

    for (i = 0; i <= n; i++) {
        Graph[i].clear();
        transGraph[i].clear();
        mscc[i] = inf;
    }

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> k >> l;
        Graph[k].pb(l);
        transGraph[l].pb(k);
    }

    scc(n);
    ll way = 1, ans = 0;

    for (i = 0; i < n; i++) {
        k = id[i + 1];
        if (mscc[k] > arr[i]) {
            mscc[k] = arr[i];
            cnt[k]  = 1;
        } else if (mscc[k] == arr[i]) {
            cnt[k]++;
        }
    }

    for (i = 0; i <= n; i++) {
        if (cnt[i] != 0) {
            ans += mscc[i];
            way = (way * (cnt[i]) % mod) % mod;
        }
    }

    cout << ans << " " << way << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    // cin >> tc;
    ll n, m;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}
