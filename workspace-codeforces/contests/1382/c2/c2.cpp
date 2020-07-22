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
    string a, b;
    cin >> a;
    cin >> b;
    vector<ll> an;
    ll flip = 0;
    ll cnt = 0;
    for (i = 0, j = n - 1, k = n - 1; k >= 0; k--) {
        ll l;
        ll tmp = j - i + 1;
        if (flip == 1) {
            l = a[j] - '0';
            j--;
        } else {
            l = a[i] - '0';
            i++;
        }
        if (cnt % 2 == 1) l ^= 1;
        // dbg(k,l,b[k])
        if (b[k]-'0' == l) {
            an.pb(1);
            // dbg(an);
        }
        an.pb(tmp);
        // dbg(an);
        flip ^= 1;
        cnt++;
    }

    cout << (ll)an.size();
    for (auto val : an) {
        cout << " " << val;
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
