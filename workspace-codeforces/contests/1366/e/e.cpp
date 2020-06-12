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
const ll mod = 998244353;
const ll NN = 2e5 + 10;

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

void solve(ll n) {
    ll i, j, k;
    ll m;
    cin >> m;

    vector<ll> a(n), b(m), cnt(n);

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < m; i++) {
        cin >> b[i];
    }

    j = m - 1;
    cnt[n - 1] = a[n - 1];

    for (i = n - 1; i >= 0; i--) {
        while (j >= 0 && a[i] < b[j]) {
            j--;
        }
        if (j < 0) {
            cout << "0\n";
            return;
        }
        if (i == n - 1) {
            continue;
        }

        cnt[i] = min(a[i], cnt[i + 1]);
    }

    if (j != 0 || cnt[0] != b[0]) {
        cout << "0\n";
        return;
    }

    j = 1;
    ll sum = 1;

    for (i = 0; i < n && j < m; i++) {
        if (cnt[i] != b[j])
            continue;

        auto it = upper_bound(all(cnt), b[j]);
        k = (int)(it - cnt.begin()) - 1;
        sum = (sum * (k - i + 1)) % mod;

        j++;
        i = k;
    }

    if (j != m) {
        sum = 0;
    }

    cout << sum << "\n";
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
