/***
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://maruftuhin.com
 */

#include "bits/stdc++.h"

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

void solve(ll n, ll k) {
    ll         i, j;
    vector<ll> a(n);
    vector<ll> f(k + 1);
    vector<ll> ck(k + 1);

    ll sum1 = n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    for (i = 1; i <= k; i++) {
        cin >> ck[i];
    }

    ll pos = 0;
    for (i = 1; i <= k; i++) {
        ll l = ceil(sum1 / ((1.0) * ck[i]));
        pos  = max(pos, l);
        if (f[i]) {
            sum1 -= f[i];
        }
    }

    vector<ll> ans[pos];
    sort(a.begin(), a.end());

    j = 0;
    for (i = 0; i < n; i++) {
        j %= pos;
        ans[j].push_back(a[i]);
        j++;
    }

    cout << pos << "\n";
    for (i = 0; i < pos; i++) {
        cout << ans[i].size();
        for (j = 0; j < ans[i].size(); j++) {
            cout << " " << ans[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    // cin >> tc;
    ll n, m, k;
    while (cin >> n >> k) {
        solve(n, k);
    }
    return 0;
}
