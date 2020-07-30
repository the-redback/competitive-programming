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
    cin >> n;
    vector<ll> v(n);
    ll mx = 26;
    for (i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(v[i], mx);
    }

    vector<string> an;

    for (i = 0; i <= n; i++) {
        string str = "";
        ll ch = i % 26;
        for (j = 0; j < mx; j++) {
            str += 'a' + ch;
        }
        an.pb(str);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < v[i]; j++) {
            an[i + 1][j] = an[i][j];
        }
        while (j < mx) {
            an[i + 1][j] = an[i][j] + 1;
            if (an[i + 1][j] > 'z') an[i + 1][j] = an[i + 1][j] - 'z' + 'a';
            j++;
        }
        cout << an[i] << "\n";
    }

    cout << an[n] << "\n";
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
