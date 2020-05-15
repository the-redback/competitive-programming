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

ll a[NN], b[NN];

void solve(ll tc) {
    ll i, j, k, n;
    cin >> n;

    mem(a, 0);
    mem(b, -1);

    for (i = 0; i < n; i++) {
        cin >> j;
        a[j] = i + 1;
        b[i] = 0;
    }
    b[n] = 0;

    ll next = a[1] + 1;
    b[a[1]] = -1;

    for (i = 2; i <= n; i++) {
        if (b[next] != -1 && a[i] != next) {
            cout << "No\n";
            return;
        }
        next    = a[i] + 1;
        b[a[i]] = -1;
    }
    cout << "Yes\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        solve(t++);
    }
    return 0;
}
