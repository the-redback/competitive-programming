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

ll a[1000];

ll check(ll n) {
    sort(a, a + n);
    for (ll i = 0; i < n - 1; i++) {
        if (a[i] + 1 == a[i + 1]) return 1;
    }
    return 0;
}

void solve(ll t) {
    ll i, j, k;
    ll n, m;
    cin >> n;

    ll even = 0, odd = 0;
    for (i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] % 2) {
            odd++;
        } else {
            even++;
        }
    }

    if (odd == 0 || even == 0 || odd % 2 == 0 || even % 2 == 0) {
        cout << "YES\n";
        return;
    }

    ll ch = check(n);

    if (ch) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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
