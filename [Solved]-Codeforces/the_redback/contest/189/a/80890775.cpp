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

ll dp[4010];
ll a, b, c;

ll rec(ll n) {
    if (n <= 0) {
        if (n == 0) {
            return 0;
        }
        return -inf;
    }

    ll& tc = dp[n];

    if (tc != -1) {
        return tc;
    }

    tc = -inf;

    if (n - a >= 0) {
        tc = max(tc, rec(n - a) + 1);
    }
    if (n - b >= 0) {
        tc = max(tc, rec(n - b) + 1);
    }
    if (n - c >= 0) {
        tc = max(tc, rec(n - c) + 1);
    }
    return tc;
}

void solve(ll n) {
    ll i, j, k;
    ll m;

    cin >> a >> b >> c;
    mem(dp, -1);

    ll ans = rec(n);

    cout << ans << "\n";
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
