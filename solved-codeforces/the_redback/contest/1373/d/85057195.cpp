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
ll odd[200010];
ll even[200010];

void solve() {
    ll i, j, k;
    ll n, m;
    cin >> n;
    vector<ll> v;
    for (i = 0; i < n; i++) {
        cin >> k;
        v.pb(k);
    }

    odd[0] = 0;
    even[0] = v[0];

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            even[i] = even[i - 1] + v[i];
            odd[i] = odd[i - 1];
        } else {
            odd[i] = odd[i - 1] + v[i];
            even[i] = even[i - 1];
        }
        // dbg(odd[i],even[i]);
    }
    odd[n] = odd[n - 1];
    even[n] = even[n - 1];

    dbg(odd, n + 1);
    dbg(even, n + 1);

    ll last = 0, right = 0;
    ll total = even[n - 1];
    ll res = even[n - 1];

    for (i = 1; i < n; i++) {
        if (i % 2 == 0)
            continue;

        ll tmp1 = 0, tmp2 = 0;
        ll l1 = 0, l2 = 0;

        if (v[i] <= v[i - 1]) {
            continue;
        }

        ll singleEv = v[i - 1];
        ll singleOdd = v[i];

        ll longTEv = even[i] - even[last] + v[last];
        ll longTOdd = odd[i] - odd[last];

        tmp1 = total - singleEv + singleOdd;
        tmp2 = total - longTEv + longTOdd;

        if (tmp1 > tmp2) {
            last = i - 1;
        }

        res = max(res, max(tmp1, tmp2));
        dbg(res, tmp1, tmp2, i);
    }

    last = 1;

    for (i = 2; i < n; i++) {
        if (i % 2 == 1)
            continue;

        dbg(i);

        ll tmp1 = 0, tmp2 = 0;
        ll l1 = 0, l2 = 0;
        // ll longTOdd = 0;

        if (v[i] >= v[i - 1]) {
            continue;
        }
        ll singleEv = v[i];
        ll singleOdd = v[i - 1];

        ll longTEv = even[i] - even[last];
        ll longTOdd = odd[i] - odd[last] + v[last];

        tmp1 = total - singleEv + singleOdd;
        dbg(total,singleEv,singleOdd)

        tmp2 = total - longTEv + longTOdd;

        if (tmp1 > tmp2) {
            last = i - 1;
        }

        res = max(res, max(tmp1, tmp2));
        dbg(res, tmp1, tmp2, singleEv, longTOdd);
    }

    cout << res << "\n";
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
