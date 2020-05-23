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

ll MaxVal;
ll MaxOps;

ll tree[NN], ops[NN];

ll update(ll idx, ll val) {
    while (idx <= MaxVal) {
        tree[idx] += val;
        idx += idx & (-idx);
    }
    return 0;
}

ll query(ll idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

ll updateOps(ll idx, ll val) {
    while (idx <= MaxOps) {
        ops[idx] += val;
        idx += idx & (-idx);
    }
    return 0;
}

ll queryOps(ll idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += ops[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void solve(ll n) {
    ll i, j, k;
    ll m, val;
    cin >> m >> k;
    MaxVal = n;
    MaxOps = m;

    for (i = 1; i <= n; i++) {
        cin >> val;
        update(i, val);
        update(i + 1, -val);
    }

    vector<pair<ll, pair<ll, ll>>> v;
    ll                             x, y, vv;
    for (i = 1; i <= m; i++) {
        cin >> x >> y >> vv;
        v.emplace_back(vv, make_pair(x, y));
        updateOps(i, 1);
        updateOps(i, -1);
    }

    for (i = 0; i < k; i++) {
        cin >> x >> y;
        updateOps(x, +1);
        updateOps(y + 1, -1);
    }

    for (i = 0; i < v.size(); i++) {
        ll mult = queryOps(i + 1);
        update(v[i].second.first, mult * v[i].first);
        update(v[i].second.second + 1, -mult * v[i].first);
    }

    for (i = 1; i <= n; i++) {
        k = query(i);
        cout << k << " ";
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
