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

ll a[100000];
ll N;

void solve(ll tc) {
    ll i, j, k, n;
    cin >> n;
    ll ret = 0;
    for (i = N - 1; i > 0 && n > 1; i--) {
        if (a[i] <= n) {
            ret += n / a[i];
            n %= a[i];
        }
    }

    cout << ret << "\n";
    return;
}

void pre() {
    ll i;
    a[0] = 0;
    for (i = 1; a[i - 1] < 1000000000; i++) {
        ll sum = (i * (i + 1)) / 2ll;
        a[i]   = (2ll * sum) + sum - i;
    }
    N = i;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pre();
    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        solve(t++);
    }
    return 0;
}
