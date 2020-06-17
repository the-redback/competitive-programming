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

void solve(ll tc) {
    ll i, j, k, n;
    cin >> n >> k;
    vector<ll> f(n + 10), arr;
    ll         fr = 0;

    for (i = 0; i < n; i++) {
        cin >> j;
        if (f[j] == 0) {
            f[j] = 1;
            fr++;
            arr.push_back(j);
        }
    }

    if (fr > k) {
        cout << "-1\n";
        return;
    }

    if (arr.size() < k) {
        for (i = 1; i <= n && arr.size() < k; i++) {
            if (!f[i]) {
                arr.push_back(i);
                f[i] = 0;
            }
        }
    }

    ll ans = (ll)arr.size() * n;
    cout << ans << "\n";
    ll fl = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < arr.size(); j++) {
            if (fl != 0) {
                cout << " ";
            }
            cout << arr[j];
            fl = 1;
        }
    }
    cout << "\n";
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
