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

#ifdef redback
#include "prettyprint.hpp"
#else
#define dbg(args...)
#endif

ll colors[NN];
vector<ll> col;
vector<pair<ll, ll>> e;

void solve(ll n) {
    ll i, j, k;
    ll m;
    cin >> m;
    for (i = 0; i < n; i++) {
        cin >> k;
        col.pb(k);
    }
    for (i = 0; i < m; i++) {
        cin >> k >> j;
        if (col[k - 1] != col[j - 1]) {
            ll kk = min(col[k - 1], col[j - 1]);
            ll jj = max(col[k - 1], col[j - 1]);
            e.emplace_back(kk, jj);
        }
    }

    sort(all(e));

    if (!e.empty()) {
        colors[e[0].first]++;
        colors[e[0].second]++;
    }
    for (i = 1; i < e.size(); i++) {
        if (e[i].first == e[i - 1].first && e[i].second == e[i - 1].second) {
            continue;
        }
        colors[e[i].first]++;
        colors[e[i].second]++;
    }

    ll ans = -1, in;
    for (auto val : col) {
        if (ans < colors[val]) {
            ans = colors[val];
            in = val;
        } else if (ans == colors[val] && in > val) {
            ans = colors[val];
            in = val;
        }
    }

    cout << in << "\n";
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
