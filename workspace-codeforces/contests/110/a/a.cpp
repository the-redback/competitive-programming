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

void solve(ll tc, string str) {
    ll i, j, k;
    ll n = 0;
    for (i = 0; i < str.size(); i++) {
        if (str[i] == '4' || str[i] == '7') {
            n++;
        }
    }

    if (n == 0) {
        cout << "NO\n";
        return;
    }

    while (n > 0) {
        k = n % 10;
        n /= 10;
        if (k != 4 && k != 7) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    // cin >> tc;
    ll     n, m;
    string str;
    while (cin >> str) {
        solve(t++, str);
    }
    return 0;
}
