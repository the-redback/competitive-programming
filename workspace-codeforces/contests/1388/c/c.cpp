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
const ll NN = 2e5 + 10;

// debugging macros
#ifdef redback
#include "prettyprint.hpp"
#else
#define dbg(args...)
#endif

vector<pair<ll, ll>> tree(NN);
vector<ll> e[NN];
vector<ll> p(NN), h(NN);
vector<ll> score(NN), vis(NN), total(NN);
ll fl = 1;

ll dfs(ll u) {
    vis[u] = 1;

    ll happy = 0, unh = 0, people = 0;
    for (auto v : e[u]) {
        if (vis[v]) continue;

        if (!dfs(v)) {
            return 0;
        };

        happy += tree[v].first;
        unh += tree[v].second;
        people += total[v];
    }

    if (happy + unh != people) {
        return 0;
    }

    people += p[u];
    if (people < h[u] || (people - h[u]) % 2) return 0;

    ll tmpunhappy = (people - h[u]) / 2;
    ll tmphappy = people - tmpunhappy;

    if (tmphappy < 0 || tmpunhappy < 0 || tmphappy < happy) return 0;
    total[u] = people;
    tree[u] = {tmphappy, tmpunhappy};

    return 1;
}

void solve() {
    ll i, j, k, l;
    ll n, m, ans = 0;
    cin >> n >> m;

    for (i = 0; i <= n; i++) {
        e[i].clear();
        score[i] = 0;
        tree[i] = {0, 0};
        vis[i] = 0;
        total[i] = 0;
    }

    for (i = 1; i <= n; i++) cin >> p[i];
    for (i = 1; i <= n; i++) cin >> h[i];
    for (i = 0; i < n - 1; i++) {
        cin >> k >> l;
        e[k].pb(l);
        e[l].pb(k);
    }

    if (!dfs(1) || total[1] != m)
        cout << "NO\n";
    else
        cout << "YES\n";

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
