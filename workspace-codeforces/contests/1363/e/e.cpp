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
vector<ll> e[NN];
vector<ll> a(NN), b(NN), c(NN);
vector<ll> curZero(NN), curOne(NN);
bitset<NN> vis;

ll dfs(ll u, ll val) {
    vis[u] = 1;

    val = min(val, a[u]);
    ll sum = 0;

    ll one = 0, zero = 0;
    if (b[u] != c[u]) {
        if (b[u] == 1)
            one++;
        else
            zero++;
    }

    for (auto v : e[u]) {
        if (!vis[v]) {
            sum += dfs(v, val);
            one += curOne[v];
            zero += curZero[v];
        }
    }
    ll sh = min(one, zero);
    sum += val * (sh * 2);
    curZero[u] = zero - sh;
    curOne[u] = one - sh;

    return sum;
}

void solve(ll n) {
    ll i, j, k;
    ll m;
    for (i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (i = 0; i < n - 1; i++) {
        cin >> k >> j;
        e[k].pb(j);
        e[j].pb(k);
    }
    ll sum = dfs(1, inf);

    if (curOne[1] != 0 || curZero[1] != 0) {
        cout << "-1\n";
        return;
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
