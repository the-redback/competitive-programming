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

// Debugging macros
#ifdef redback
#include "prettyprint.hpp"
#else
#define dbg(args...)
#endif
ll a[NN];

void solve(ll n) {
    ll i, j, k;
    ll m;
    vector<ll> v;
    for (i = 0; i < n; i++) cin >> a[i];

    for (i = 0; i < n; i += 2) v.pb(a[i]);
    for (i = 1; i < n; i += 2) v.pb(a[i]);

    for (i = 0; i < n; i++) v.pb(v[i]);

    for (i = 1; i < n + n; i++) v[i] += v[i - 1];

    ll sz = (n + 1) / 2;
    ll ans = v[sz - 1];

    for (i = sz; i < n + n; i++) ans = max(ans, v[i] - v[i - sz]);

    cout << ans << "\n";
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
