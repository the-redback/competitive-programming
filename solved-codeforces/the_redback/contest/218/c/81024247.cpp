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
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        200010

// clang-format off
#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cout<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cout << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros
// clang-format on

vector<ll> e[111];
vector<ll> vis(111);

void rec(ll u) {
    if (vis[u]) {
        return;
    }
    vis[u] = true;

    for (ll i = 0; i < e[u].size(); i++) {
        rec(e[u][i]);
    }
    return;
}

void solve(ll n) {
    ll i, j, k;
    ll m;

    vector<pair<ll, ll>> in;

    for (i = 0; i < n; i++) {
        e[i].clear();
        cin >> j >> k;
        in.emplace_back(j, k);
    }

    fill(vis.begin(), vis.end(), 0);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            if (in[i].first == in[j].first || in[i].second == in[j].second) {
                e[i].push_back(j);
                e[j].push_back(i);
            }
        }
    }

    ll ans = 0;

    for (i = 0; i < n; i++) {
        if (vis[i] == 0) {
            ans++;
            rec(i);
        }
    }

    cout << ans - 1 << "\n";
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
