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
    ll i, j, k, l;
    ll n, m, ans = 0;
    cin >> n >> k >> l;

    ll var;
    ll down = 1;
    ll tide = k;
    ll ok = 1;
    for (i = 0; i < n; i++) {
        cin >> var;
        if (var + k <= l) {
            // good place to sleep and wait
            tide = k;
            down = 1;
            continue;
        }
        if (down)
            tide--;
        else
            tide++;

        ll minus = max(0ll, var + tide - l);

        if (minus && (!down || tide < minus)) {
            ok = 0;
            continue;
        }
        tide -= minus;
        if (tide <= 0) down = 0;
    }

    if (ok) {
        cout << "Yes\n";
        return;
    }

    cout << "No\n";
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
