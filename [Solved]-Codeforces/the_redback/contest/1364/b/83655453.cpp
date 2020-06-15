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

void solve() {
    ll i, j, k;
    ll n, m;
    cin >> n;
    vector<ll> a(n);
    vector<ll> v;

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> big(n), small(n);

    big[n - 1] = a[n - 1];
    small[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        big[i] = max(a[i], big[i + 1]);
        small[i] = min(a[i], small[i + 1]);
    }

    dbg(big);
    dbg(small);

    v.pb(a[0]);
    ll last = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            while (i+1 < n && a[i] < a[i+1]) {
                i++;
            }
            v.pb(a[i]);
        } else if (a[i] < a[i-1]) {
            while (i+1 < n && a[i] > a[i+1]) {
                i++;
            }
            v.pb(a[i]);
        }
    }

    cout << (int)v.size() << "\n";
    for (auto val : v) {
        cout << val << " ";
    }
    cout << "\n";

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
