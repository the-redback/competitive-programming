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

ll a[4040];
ll dp[4040][2020];
vector<ll> v;

ll rec(ll pos, ll rem) {
    if (rem == 0) return 1;
    if (pos == v.size()) return 0;

    ll& tc = dp[pos][rem];
    if (tc != -1) return tc;

    tc = rec(pos + 1, rem);
    if (rem - v[pos] >= 0) {
        tc |= rec(pos + 1, rem - v[pos]);
    }
    return tc;
}

void solve() {
    ll i, j, k;
    ll n, m, ans = 0;
    cin >> n;
    cin >> a[0];
    ll in = 0;
    v.clear();
    for (i = 1; i < n + n; i++) {
        cin >> a[i];
        if (a[i] > a[in]) {
            v.pb(i - in);
            in = i;
        }
    }

    for (i = 0; i <= v.size(); i++) {
        for (j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    if (rec(0, n)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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
