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
#define inf       1e9
#define eps       1e-9
// #define mod       1000000007
// #define NN        100010

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
const ll NN = 1e6 + 10;
const ll mod = 1e9 + 7;
ll fr[NN];
vector<ll> v;

ll bigMod(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b % 2) r = r * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return r % mod;
}

void solve() {
    ll i, j, k;
    ll n, m;
    ll p;
    cin >> n >> p;
    ll mx = 0;
    v.clear();
    for (i = 0; i < n; i++) {
        cin >> k;
        if (fr[k] == 0) {
            v.pb(k);
        }
        fr[k]++;
        mx = max(mx, k);
    }
    ll fl = 0;
    if (p == 1) {
        fl = 1;
        if (n % 2) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    for (i = mx; i >= 0 && !fl; i--) {
        dbg(i, fr[i]);
        if (fr[i] % 2 == 0) {
            continue;
        }
        ll need = 1;
        ll ok = 0;
        for (j = i - 1; j >= 0; j--) {
            dbg(j, need, p);
            need *= p;
            if (need > 1e6) {
                ok = 0;
                break;
            }
            ll have = fr[j];
            if (have >= need) {
                i = j + 1;
                fr[j] -= need;
                ok = 1;
                break;
            }
            need -= have;
        }
        dbg(need, i, j);

        if (!ok) {
            ll prev = bigMod(p, i);
            // ll next = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (fr[j] != 0) {
                    ll tmp = bigMod(p, j);
                    prev = ((prev - (tmp * fr[j]) % mod) + mod) % mod;
                }
            }
            // dbg(i, prev, next);
            // ll ans = ((prev - next)%mod +mod)%mod;
            cout << prev << "\n";
            break;
        }
    }
    if (!fl && i < 0) {
        cout << "0\n";
    }

    for (i = 0; i < v.size(); i++) {
        fr[v[i]] = 0;
    }
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