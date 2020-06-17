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

vector<ll> e[2020];

ll rec(ll u) {
    if (e[u].size() == 0) {
        return 1;
    }

    ll ret = 0;

    for (ll i = 0; i < e[u].size(); i++) {
        ll v = e[u][i];
        ret  = max(ret, rec(v) + 1);
    }
    return ret;
}

void solve(ll n) {
    ll         i, j, k;
    ll         m;
    vector<ll> v(2020);
    for (i = 0; i < n; i++) {
        e[i].clear();
    }

    for (i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] != -1) {
            e[v[i]].push_back(i);
        }
    }

    ll ret = 0;

    for (i = 1; i <= n; i++) {
        if (v[i] == -1) {
            ret = max(ret, rec(i));
        }
    }

    cout << ret << "\n";
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
