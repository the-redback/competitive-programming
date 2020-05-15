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

map<ll, ll> mp;

void solve(ll tc) {
    ll i, j, k, n;
    cin >> n;
    vector<ll> a(3 * n + 10);
    mp.clear();
    for (i = 0; i < n; i++) {
        cin >> k;
        a[i]         = k;
        a[i + n]     = k;
        a[i + n + n] = k;
    }

    for (i = 0; i < 3 * n; i++) {
        k = a[0]%n;
        if (i != 0) {
            k = i + (a[(i % n)]%n);
        }
        if (mp.find(k) != mp.end()) {
            cout << "NO\n";
            return;
        }
        mp[k] = 1;
    }

    cout << "YES\n";
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
