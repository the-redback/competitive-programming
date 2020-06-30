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
char a[50][50];
ll dp[50][50][50][50];
ll ans[50][50][50][50];

ll call(ll x, ll y, ll xx, ll yy) {
    if (x > xx || y > yy) {
        return 0;
    }

    ll& tc = dp[x][y][xx][yy];
    if (tc != -1)
        return tc;

    ll fl = 1;
    for (ll i = x; i <= xx && fl; i++) {
        for (ll j = y; j <= yy && fl; j++) {
            if (a[i][j] == '1') {
                fl = 0;
                break;
            }
        }
    }

    ll sum = fl;
    sum += call(x, y, xx - 1, yy);
    sum += call(x, y, xx, yy - 1);
    sum -= call(x, y, xx - 1, yy - 1);

    return tc = sum;
}

void solve(ll n) {
    ll i, j, k;
    ll m, q;
    cin >> m >> q;
    mem(dp, -1);
    mem(ans, 0);
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll x = 0; x < n; x++) {
        for (ll y = 0; y < m; y++) {
            for (ll xx = x; xx < n; xx++) {
                for (ll yy = y; yy < m; yy++) {
                    ll tmp = 0;
                    for (i = x; i <= xx; i++) {
                        for (j = y; j <= yy; j++) {
                            tmp += call(i, j, xx, yy);
                        }
                    }
                    ans[x][y][xx][yy] = tmp;
                }
            }
        }
    }

    ll x, y, xx, yy;
    while (q--) {
        cin >> x >> y >> xx >> yy;
        cout << ans[x - 1][y - 1][xx - 1][yy - 1] << "\n";
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    solve(n);
    return 0;
}
