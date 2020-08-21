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

const ll inf = 1e12;
const ll mod = 1e9 + 7;
const ll NN = 1e5 + 10;

// debugging macros
#ifdef redback
#include "prettyprint.hpp"
#else
#define dbg(args...)
#endif

void solve() {
    ll i, j, k;
    ll n, m, ans = 0;
    cin >> n >> k;
    vector<ll> v(n);
    ll mx = -inf;
    for (i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    ll mx1 = -inf;
    for (i = 0; i < n; i++) {
        v[i] = mx - v[i];
        mx1 = max(mx1, v[i]);
    }

    if (k % 2 == 0) {
        for (i = 0; i < n; i++) {
            v[i] = mx1 - v[i];
        }
    }

    for (i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    cout << "\n";
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
