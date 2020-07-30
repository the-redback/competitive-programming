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
    string s;
    cin >> s;

    ans = 2;

    for (ll ii = '0'; ii <= '9'; ii++) {
        for (ll jj = '0'; jj <= '9'; jj++) {
            ll tmp = 0;
            if (ii == jj) {
                for (i = 0; i < s.size(); i++) {
                    if (s[i] == ii) tmp++;
                }
                ans = max(ans, tmp);
            }
            tmp = 0;
            ll cnt = 0;
            ll fl = 0;
            for (i = 0; i < s.size(); i++) {
                if (fl == 0) {
                    if (s[i] == ii) {
                        cnt++;
                        fl ^= 1;
                    }
                } else {
                    if (s[i] == jj) {
                        cnt++;
                        fl ^= 1;
                    }
                }
            }
            if (cnt % 2) {
                continue;
            }
            ans = max(ans, cnt);
        }
    }

    ll rem = (ll)s.size() - ans;

    cout << rem << "\n";
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
