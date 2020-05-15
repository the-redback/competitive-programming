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

vector<ll> arr;
int        main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        cin >> n;
        ll i, j, k;

        k = n / 2;
        if (k % 2) {
            cout << "NO\n";
            continue;
        }

        arr.clear();

        ll l = 0, r = 0;

        j = 2;
        for (i = 0; i < n / 2; i++) {
            arr.push_back(j);
            l += j;
            j += 2;
        }

        j = 1;
        for (i = 0; i < n / 2 - 1; i++) {
            arr.push_back(j);
            r += j;
            j += 2;
        }

        arr.push_back(l - r);

        cout << "YES\n";

        for (i = 0; i < arr.size(); i++) {
            if (i) cout << " ";
            cout << arr[i];
        }
        cout << "\n";
    }
    return 0;
}
