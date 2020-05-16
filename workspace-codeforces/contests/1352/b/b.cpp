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

void solve(ll tc) {
    ll i, j, k, n;
    cin >> n >> k;

    if (n < k || (n > k && (n < k + 2 || (n % 2==0 && k % 2)) && n < k * 2) ||
        (n % 2 && k % 2 == 0)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    if (n == k || n % 2 || n < k * 2) {
        for (i = 1; i < k; i++) {
            cout << 1 << " ";
        }
        cout << n - (k - 1) << "\n";
        return;
    }

    for (i = 1; i < k; i++) {
        cout << 2 << " ";
    }
    cout << n - (k - 1) * 2 << "\n";
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
