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

vector<ll> v[1010];

ll check(ll low, ll high, ll except) {
    vector<ll> tmp;
    for (ll i = low; i <= high; i++) {
        if (i == except) continue;
        for (auto val : v[i]) {
            tmp.pb(val);
        }
    }

    cout << "? " << (int)tmp.size();
    for (auto val : tmp) {
        cout << " " << val;
    }
    cout << "\n";
    cout.flush();
    cin >> low;
    return low;
}

void solve() {
    ll i, j, k;
    ll n, m, val;
    cin >> n >> k;
    for (i = 1; i <= k; i++) {
        cin >> m;
        ll sum = -1;
        for (j = 0; j < m; j++) {
            cin >> val;
            v[i].pb(val);
        }
    }

    ll mx;
    cout << "? " << n;
    for (i = 1; i <= n; i++) {
        cout << " " << i;
    }
    cout << "\n";
    cout.flush();
    cin >> mx;

    ll low = 1, high = k;
    while (low < high) {
        ll mid = (low + high) / 2;
        val = check(low, mid, 0);
        dbg(low, mid, high, val)

            if (val == mx) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    ll scd;
    bitset<1010> b;
    b.set();
    for (auto val : v[low]) {
        b[val] = 0;
    }

    cout << "? " << n - (int)v[low].size();

    for (i = 1; i <= n; i++) {
        if (b[i]) cout << " " << i;
    }
    cout << "\n";
    cout.flush();
    cin >> scd;

    cout << "!";

    for (i = 1; i <= k; i++) {
        if (low == i) {
            cout << " " << scd;
            continue;
        }
        cout << " " << mx;
    }
    cout << "\n";
    cout.flush();
    string demo;
    cin >> demo;
    dbg(v) for (i = 1; i <= k; i++) { v[i].clear(); }

    return;
}

int main() {
    ios::sync_with_stdio(false);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        solve();
    }
    return 0;
}
