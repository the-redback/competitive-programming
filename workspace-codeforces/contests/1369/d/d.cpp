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

vector<ll> pr(2000010);

void solve() {
    ll i, j, k;
    ll n, m;
    cin >> n;

    cout << (pr[n] * 4) % mod << "\n";
    return;
}

void pre() {
    ll n = 2000001;
    pr[0] = 0;
    pr[1] = 0;
    for (ll i = 2; i < n; i++) {
        pr[i] = (pr[i - 1] + 2 * pr[i - 2]) % mod;
        if (i % 3 == 0)
            pr[i] = (pr[i] + 1) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pre();

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        solve();
    }
    return 0;
}
