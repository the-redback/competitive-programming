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

double chk(ll n, ll h, ll c) {
    double sum;
    ll     k = (n + 1ll) / 2ll;
    ll     l = n - k;
    sum = ((k * h) + (c * l)) / (1.0 * n);
    return sum;
}

void solve() {
    ll     i, j, k;
    ll     n, m;
    double h, c, t;
    cin >> h >> c >> t;

    double sum = (h + c) / 2.0;
    if (abs(t - sum) < eps || t < sum) {
        cout << "2\n";
        return;
    }

    ll low = 1;
    ll high = 1e12;
    ll midleft, midright;
    while (high - low > 3) {
        midleft = low + (high - low) / 3ll;
        midright = high - (high - low) / 3ll;

        if (midleft % 2l == 0) {
            midleft--;
        }
        if (midright % 2l == 0) {
            midright++;
        }

        double sum1 = chk(midleft, h, c);
        double sum2 = chk(midright, h, c);

        if (abs(sum2 - t) < abs(sum1 - t))
            low = midleft + 1;
        else
            high = midright - 1;
    }

    double ans = inf;
    ll     cnt = 0;

    for (i = low; i <= high; i++) {
        double temp = chk(i, h, c);

        if (abs(temp - t) < ans) {
            ans = abs(temp - t);
            cnt = i;
        }
    }

    cout << cnt << "\n";
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
