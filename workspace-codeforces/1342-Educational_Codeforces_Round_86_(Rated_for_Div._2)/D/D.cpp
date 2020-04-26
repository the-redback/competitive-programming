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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    // cin >> tc;
    ll n, m, k;
    while (cin >> n >> k) {
        ll         i, j;
        vector<ll> a(n + 2);
        vector<ll> f(k + 2);
        vector<ll> ck(k + 2);

        ll sum1 = n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            f[a[i]]++;
            debug(i, a[i])
        }
        ll sum2 = 0;
        for (i = 1; i <= k; i++) {
            cin >> ck[i];
            sum2 += ck[i];
            debug(i, ck[i])
        }

        ll pos = 1;
        for (i = 1; i <= k; i++) {
            ll l                          = ceil(sum1 / ((1.0) * sum2));
            debug(sum1, sum2, l, pos) pos = max(pos, l);
            sum1 -= f[i] * i;
            sum2 -= ck[i];
        }

        vector<ll> ans[pos + 2];
        vector<ll> chk(pos + 2);

        for (i = 1; i <= k; i++) {
            ll fr = ceil(f[i] / 1.0 * pos);
            for (j = 0; j < pos && ck[i] > 0; j++) {
                ans[j].push_back(min(fr, ck[i]));
                ck[i] -= fr;
            }
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
    return 0;
}
