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
const ll NN = 2e3 + 10;

/* -------------------------------------------------------------------------- */
/*                              Debugging Macros                              */
/* -------------------------------------------------------------------------- */
#ifdef redback
#include "prettyprint.hpp"
#define dbg(...)                        \
    cout << "L-" << __LINE__ << " :: "; \
    _print_out(#__VA_ARGS__, __VA_ARGS__);
template <typename T>
void _print_out(const char* name, T&& arg1) {
    cout << name << " = " << arg1 << endl;
}
template <typename T1, typename... Args>
void _print_out(const char* names, T1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " = " << arg1 << " | ";
    _print_out(comma + 1, args...);
}
template <typename T>
void _print_out(const char* name, T a[], int n) {
    cout << name << " = " << pretty_print_array(a, n) << endl;
}
#else
#define dbg(args...)
#endif
/* -------------------------------------------------------------------------- */
ll dp[NN][NN];
ll ss[26][NN];
ll tt[26][NN];
string s, t;

ll rec(ll i, ll j) {
    if (j <= 0) return 0;

    ll& tc = dp[i][j];
    if (tc != -1) {
        return tc;
    }

    tc = inf;
    if (i > 0) {
        tc = rec(i - 1, j) + 1;
        if (t[j] == s[i]) {
            tc = min(tc, rec(i - 1, j - 1));
        }
    }

    char x = t[j] - 'a';
    dbg(i, j);
    dbg(x, ss[x][i + 1], tt[x][j + 1]);
    if (ss[x][i + 1] > tt[x][j + 1]) {
        tc = min(tc, rec(i, j - 1));
    }
    dbg(i, j, tc);
    return tc;
}

void solve() {
    ll i, j, k;
    ll n, m;
    cin >> n;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    for (i = 0; i < 26; i++) {
        ss[i][n + 1] = 0;
        tt[i][n + 1] = 0;
    }

    for (i = n; i >= 1; i--) {
        for (j = 0; j < 26; j++) {
            ss[j][i] = ss[j][i + 1];
            tt[j][i] = tt[j][i + 1];
            dbg(ss[j][i], tt[j][i]);
        }
        ss[s[i] - 'a'][i]++;
        tt[t[i] - 'a'][i]++;
    }

    ll ans = rec(n, n);
    if (ans >= inf) {
        ans = -1;
    }

    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        solve();
    }
    return 0;
}
