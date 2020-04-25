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

ll a[NN], freq[NN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        ll i, j, k;
        cin >> n >> k;
        mem(freq, 0);

        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        freq[0] = 0;
        for (i = 1; i < n - 1; i++) {
            freq[i] = freq[i - 1];

            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                freq[i]++;
            }
        }

        freq[n - 1] = freq[n - 2];

        ll ret  = -1;
        ll left = -1;
        for (i = k - 1; i < n; i++) {
            j = freq[i] - freq[i - k + 1];
            debug(j, i, i - k + 1, freq[i],
                  freq[i - k + 1]) if (freq[i] > freq[i - 1]) j--;
            if (j > ret) {
                ret  = j;
                left = i - k + 2;
            }
        }
        cout << ret + 1 << " " << left << "\n";
    }
    return 0;
}
