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

ll a[NN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        ll i, j, k;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll last = a[0];
        ll sum  = a[0];

        for (i = 1; i < n; i++) {
            if (a[i] < 0 && a[i - 1] < 0) {
                sum -= last;
                last = max(last, a[i]);
                sum += last;
            } else if (a[i] > 0 && a[i - 1] > 0) {
                sum -= last;
                last = max(last, a[i]);
                sum += last;
            } else {
                sum += a[i];
                last = a[i];
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
