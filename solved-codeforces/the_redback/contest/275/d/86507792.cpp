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
#define ft        first
#define sd        second
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define mem(a, b) memset(a, b, sizeof(a))
#define eps       1e-9

const ll inf = 1e9;
const ll mod = 1e9 + 7;
const ll NN = 1e5 + 10;

// Debugging micros
#ifdef redback
#include "prettyprint.hpp"
#else
#define dbg(args...)
#endif

ll vis[NN], pl[NN], mn[NN];
vector<ll> e[NN];
ll a[NN];

void dfs(ll u) {
    vis[u] = 1;
    for (auto v : e[u]) {
        if (vis[v]) continue;
        dfs(v);
        pl[u] = max(pl[u], pl[v]);
        mn[u] = max(mn[u], mn[v]);
    }

    a[u] = a[u] + mn[u] - pl[u];
    if (a[u] > 0)
        pl[u] += abs(a[u]);
    else
        mn[u] += abs(a[u]);
}

void solve(ll n) {
    ll i, j, k;
    ll m;
    for (i = 0; i < n - 1; i++) {
        cin >> j >> k;
        e[j].pb(k);
        e[k].pb(j);
    }
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    mem(vis, 0);
    dfs(1);

    cout << pl[1] + mn[1] << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    solve(n);
    return 0;
}
