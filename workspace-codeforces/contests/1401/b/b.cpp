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
    ll za, oa, ta;
    ll zb, ob, tb;
    cin >> za >> oa >> ta;
    cin >> zb >> ob >> tb;

    dbg(za, oa, ta);
    dbg(zb, ob, tb);

    ll tmp = min(za, tb);
    za -= tmp;
    tb -= tmp;

    dbg(za, oa, ta);
    dbg(zb, ob, tb);

    tmp = min(tb, ta);
    tb -= tmp;
    ta -= tmp;

    dbg(za, oa, ta);
    dbg(zb, ob, tb);

    tmp = min(ta, ob);
    ans += tmp * 2;
    ta -= tmp;
    ob -= tmp;

    dbg(za, oa, ta);
    dbg(zb, ob, tb);

    tmp = min(tb, oa);
    ans -= tmp * 2;

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
