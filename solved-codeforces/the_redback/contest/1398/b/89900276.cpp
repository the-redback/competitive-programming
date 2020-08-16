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
    string str;
    cin >> str;

    vector<ll> v;
    ll cnt = 0;
    if (str[0] == '1') cnt++;

    for (i = 1; i < str.size(); i++) {
        if (str[i] == '1') {
            cnt++;
        } else if (cnt != 0) {
            v.pb(cnt);
            cnt = 0;
        }
    }

    if (cnt != 0) {
        v.pb(cnt);
        cnt = 0;
    }

    sort(allr(v));

    ans = 0;
    for (i = 0; i < v.size(); i++) {
        if (i % 2 == 0) ans += v[i];
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
