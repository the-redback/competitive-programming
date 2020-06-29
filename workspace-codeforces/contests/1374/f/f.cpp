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
void _print_out(const char* name, T a[], ll n) {
    cout << name << " = " << pretty_print_array(a, n) << endl;
}
#else
#define dbg(args...)
#endif
/* -------------------------------------------------------------------------- */

ll a[505];
ll dirty_work(ll n, ll ex) {
    ll id = -1;
    for (ll i = n; i >= 0; i--) {
        if (a[i] != ex) {
            continue;
        }
        if (i > n - 2) {
            id = n - 2;
        } else if (i > 0) {
            id = i - 1;
        } else {
            id = i;
        }

        ll tmp = a[id + 2];
        a[id + 2] = a[id + 1];
        a[id + 1] = a[id];
        a[id] = tmp;
        return id;
    }
    return -1;
}

void solve() {
    ll i, j, k;
    ll n, m;
    cin >> n;
    vector<ll> v, ans;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        v.pb(a[i]);
    }
    sort(all(v));
    m = n - 1;
    while (m > 2 && ans.size() <= n * n) {
        while (a[m] != v[m]) {
            k = dirty_work(m, v[m]);
            dbg(k, m, v[m]);
            dbg(a, n);
            if (k == -1) {
                cout << "-1\n";
                return;
            }
            ans.pb(k);
        }
        m--;
    }

    while (ans.size() < n * n) {
        if (a[0] == v[0] && a[1] == v[1] && a[2] == v[2])
            break;
        ll id = 0;
        ll tmp = a[id + 2];
        a[id + 2] = a[id + 1];
        a[id + 1] = a[id];
        a[id] = tmp;
        ans.pb(id);
    }

    for (i = 0; i < n; i++) {
        if (v[i] != a[i]) {
            cout << "-1\n";
            return;
        }
    }

    cout << (ll)ans.size() << "\n";
    for (auto val : ans) {
        cout << val + 1 << " ";
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
