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
vector<ll> e[NN], ans;
ll color[NN];
ll dist[NN];
ll x, fl;
ll cnt;

ll dfs(ll u, ll l) {
    dist[u] = l;
    color[u] = l % 2;

    for (auto v : e[u]) {
        if (color[v] != -1) {
            if (l + 1 - dist[v] > 2 && l + 1 - dist[v] <= x) {
                cnt = l + 1 - dist[v];
                if (ans.size() < cnt)
                    ans.pb(u);
                fl = 1;
                return l;
            }
            if (color[v] == color[u]) {
                color[u] = 2;
            }
        } else {
            ll ret = dfs(v, l + 1);
            if (ret != 0) {
                if (ans.size() < cnt)
                    ans.pb(u);
                return 1;
            }
        }
    }
    return 0;
}

ll sol1(ll u, ll n, ll k) {
    ans.clear();
    for (ll i = 1; i <= n && ans.size() < k; i++) {
        if (color[i] == u) {
            ans.pb(i);
        }
    }

    cout << "1\n";
    for (auto v : ans) {
        cout << v << " ";
    }
    return 0;
}

void solve(ll n) {
    ll i, j, k;
    ll m;
    cin >> m >> x;

    for (i = 0; i < m; i++) {
        cin >> k >> j;
        e[k].pb(j);
        e[j].pb(k);
    }

    mem(color, -1);
    fl = 0;
    dfs(1, 0);
    if (fl) {
        cout << "2\n";
        cout << (int)ans.size() << "\n";
        for (auto v : ans) {
            cout << v << " ";
        }

        cout << "\n";
        return;
    }

    ll des = ceil(x / 2.0);
    vector<ll> dd(5);
    for (i = 1; i <= n; i++) {
        dd[color[i]]++;
    }

    for (i = 0; i <= 2; i++) {
        if (dd[i] >= des) {
            sol1(i, n, des);
            return;
        }
    }
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
