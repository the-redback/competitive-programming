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

// debugging macros
#ifdef redback
#include "prettyprint.hpp"
#else
#define dbg(args...)
#endif

vector<ll> e[NN], c;
map<ll, map<ll, ll> > mp;

ll vis[NN];
ll N;

pair<ll, ll> rec(ll u) {
    dbg(u) vis[u] = 1;

    pair<ll, ll> tmp = make_pair(0, 0);
    pair<ll, ll> sum = make_pair(1, 0);
    for (ll i = 0; i < e[u].size(); i++) {
        ll v = e[u][i];
        if (vis[v] != -1) continue;
        tmp = rec(v);
        sum.ft += tmp.ft;
        dbg(v, tmp);
    }
    ll tt = (sum.ft * (N - (sum.ft))) % mod;
    dbg(u, tt, sum);
    c.pb(tt);

    return make_pair(sum.ft, tt);
}

void solve() {
    ll i, j, k, l;
    ll n, m, ans = 0;
    cin >> n;
    N = n;
    c.clear();
    for (size_t i = 0; i <= n; i++) e[i].clear();

    for (i = 0; i < n - 1; i++) {
        cin >> k >> l;
        e[k].pb(l);
        e[l].pb(k);
    }

    cin >> m;
    vector<ll> pr(m);
    ll K = 1;
    for (size_t i = 0; i < m; i++) {
        cin >> pr[i];
        K = (K * pr[i]) % mod;
    }

    mem(vis, -1);
    rec(1);

    dbg(c);

    sort(allr(c));
    sort(allr(pr));

    // if (m >= N) {
    //     ans = (c[0] * K) % mod;
    //     cout << ans << "\n";
    //     return;
    // }

    for (j = 0; j <= m - n; j++) {
        pr[j + 1] = (pr[j + 1] * pr[j]) % mod;
    }

    dbg(c);
    dbg(pr);

    for (i = 0; i < N - 1; i++, j++) {
        if (j >= m) {
            ans = (ans + c[i]) % mod;
            continue;
        }
        ans = (ans + (c[i] * pr[j]) % mod) % mod;
        continue;
    }

    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
