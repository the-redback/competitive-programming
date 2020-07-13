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
ll x, y, k;

ll rec(ll total, ll mustk) {
    ll ans = 0;
    if (mustk) {
        total -= k;
        ans += x;
        mustk = 0;
    }
    if (total < 0) return -1;

    if (x <= y * k) {
        ans += (total / k) * x;
        total = total % k;
    }

    ans += total * y;
    return ans;
}

void solve(ll n) {
    ll i, j;
    ll m, ans = 0;
    cin >> m;
    vector<ll> a(n), b(m);
    cin >> x >> k >> y;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < m; i++) cin >> b[i];

    a.pb(0);
    b.pb(0);

    ll last = 0, in = -1, mx = 0;
    for (i = 0, j = 0; i <= n && j <= m; i++) {
        mx = max(mx, a[i]);
        if (a[i] != b[j]) {
            continue;
        }
        j++;
        ll total = i - in - 1;

        ll tmp;
        if (mx != last && mx != a[i])
            tmp = rec(total, 1);
        else
            tmp = rec(total, 0);

        if (tmp == -1) {
            cout << "-1\n";
            return;
        }
        ans += tmp;
        last = a[i];
        mx = last;
        in = i;
    }
    if (j <= m) {
        ans = -1;
    }

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
