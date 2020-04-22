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
#define NN        100010

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

ll arr[NN];
ll dp[100010][2];
ll N;

ll rec(ll pos, bool prevNeg) {
    debug(pos, prevNeg, N)
    if (pos == N) {
        return 0;
    }
    ll& tc = dp[pos][prevNeg];
    if (tc != -1) {
        return tc;
    }
    tc = -inf;
    if (prevNeg && arr[pos] < 0) {
        return tc = rec(pos + 1, prevNeg);
    } else if (!prevNeg && arr[pos] >= 0) {
        return tc = rec(pos + 1, prevNeg);
    }

    tc = rec(pos + 1, prevNeg);
    tc = max(tc, rec(pos + 1, arr[pos] < 0) + arr[pos]);
    return tc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        cin >> n;
        N = n;
        ll i, j, k;
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }

        mem(dp, -1);
        ll ans = rec(0, 0);
        ans    = max(ans, rec(0, 1));

        cout << ans << "\n";
    }
    return 0;
}
