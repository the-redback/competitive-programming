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

vector<ll> v = {6, 10, 14, 22, 26, 15, 21, 33, 39, 35, 55, 65, 77, 91};

void solve() {
    ll i, j, k;
    ll n, m, ans = 0;
    cin >> n;
    if (n < 6 + 10 + 14 + 1) {
        cout << "NO\n";
        return;
    }
    for (i = 0; i < v.size(); i++) {
        for (j = 0; j < v.size(); j++) {
            if (i == j) continue;
            for (k = 0; k < v.size(); k++) {
                if (i == k || j == k) continue;
                ans = n - v[i] - v[j] - v[k];
                if (ans > 0 && ans != v[i] && ans != v[j] && ans != v[k]) {
                    cout << "YES\n";
                    cout << v[i] << " " << v[j] << " " << v[k] << " " << ans
                         << "\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";

    ans = n - 6 - 10 - 14;

    cout << "6 10 14 " << ans << "\n";
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
