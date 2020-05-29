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
#define xx        first
#define yy        second
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        100010

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

ll chk(ll n) { return (n * (n + 1)) / 2; }

void solve(ll n) {
    ll i, j, k;
    ll m;
    cin >> m;

    vector<ll> v(2 * n + 1), day(2 * n + 1), point(2 * n + 1);
    v[0] = 0;
    day[0] = 0;
    point[0] = 0;

    for (i = 1; i <= n; i++) {
        cin >> v[i];
        day[i] = day[i - 1] + v[i];
        point[i] = point[i - 1] + chk(v[i]);
    }
    for (i = n + 1; i <= n + n; i++) {
        day[i] = day[i - 1] + v[i - n];
        point[i] = point[i - 1] + chk(v[i - n]);
    }

    ll ans = 0;

    for (i = 1; i <= n + n; i++) {
        if (day[i] < m) {
            continue;
        }
        k = day[i] - m;
        auto low = lower_bound(all(day), k);
        ll   in = low - day.begin();

        if (day[in] > k) {
            in--;
        }

        dbg(in,day[in], point[in]);

        ll dif = k - day[in];
        ll ret = point[i] - point[in];
        ret -= (dif * (dif + 1)) / 2;
        ans = max(ret, ans);
    }

    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    // cin >> tc;
    ll n, m;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}
