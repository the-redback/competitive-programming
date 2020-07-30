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

void solve() {
    ll i, j, k;
    ll n, m, ans = 0;
    cin >> n >> k;
    ll l1, r1, l2, r2;
    cin >> l1 >> r1;
    cin >> l2 >> r2;

    if (l1 > l2 || l1 == l2 && r1 > r2) {
        swap(l1, l2);
        swap(r1, r2);
    }

    dbg(l1, r1, l2, r2);

    ll must = 0;

    if (r1 < l2) {
        must = l2 - r1;
        r1 = l2;
    }

    ll l = 0;
    if (l1 == l2 && r1 <= r2) {
        l = r1 - l1;
    } else if (l2 <= r1 && r2 <= r1) {
        l = r2 - l2;
    } else if (l2 <= r1) {
        l = r1 - l2;
    }

    ll poss = abs(l2 - l1) + abs(r2 - r1);
    ll rem = max(0ll, k - (l * n));
    ans = 0;
    for (i = 0; i < n; i++) {
        if (rem <= 0) break;
        ll ones = min(poss, rem);

        if (i != 0 && must + ones > ones * 2) break;

        ans += must + ones;
        rem -= ones;
    }
    if (rem < 0) rem = 0;

    ans += rem * 2;

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
