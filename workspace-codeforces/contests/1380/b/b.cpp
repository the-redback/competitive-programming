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
    ll R = 0, P = 0, S = 0;
    vector<pair<ll, ll>> v(3);
    v[0] = make_pair(0, 0);
    v[1] = make_pair(0, 1);
    v[2] = make_pair(0, 2);
    string s = "RPS";
    for (i = 0; i < str.size(); i++) {
        if (str[i] == 'R')
            v[0].first++;
        else if (str[i] == 'P')
            v[1].first++;
        else if (str[i] == 'S')
            v[2].first++;
    }
    sort(all(v));

    if (v[0].first == v[2].first) {
        cout << str << "\n";
        return;
    }

    for (i = 0; i < str.size(); i++) {
        cout << s[(v[2].second + 1) % 3];
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
