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
#define mem(a, b) comemset(a, b, sizeof(a))
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

vector<pair<ll, ll>> v;
vector<int> e[500010];
vector<int> th(500010);
bitset<500010> fl, vis;

void solve(ll n) {
    ll i, j, k;
    ll m;
    cin >> m;
    
    for (i = 0; i < m; i++) {
        cin >> k >> j;
        e[k].pb(j);
        e[j].pb(k);
    }

    for (i = 1; i <= n; i++) {
        cin >> k;
        th[i] = k;
        v.pb(make_pair(k, i));
    }

    sort(all(v));    

    for (i = 0; i < n; i++) {
        ll xx = v[i].second;
        dbg(i, xx, v[i]);
        fl.reset();

        for (j = 0; j < e[xx].size(); j++) {
            ll yy = e[xx][j];
            if (th[yy] == th[xx]) {
                dbg(i, v[i], k, e[xx][j]);
                cout << "-1\n";
                return;
            }
            if (vis[yy] != 0) {
                fl[th[yy]] = 1;
            }
        }
        
        for (j = 1; j < v[i].first; j++) {
            if (fl[j] == 0) {
                dbg(xx, th[xx], v[i].first, j, fl[j]);
                cout << "-1\n";
                return;
            }
        }
        
        fl[v[i].first] = 1;
        vis[xx] = 1;
    }
    

    for (i = 0; i < n; i++) {
        cout << v[i].second << " ";
    }

    cout << "\n";
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
