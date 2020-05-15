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

typedef long long   ll;
#define mem(a, b)   memset(a,b,sizeof(a))
#define inf         1e9
#define eps         1e-9
#define mod         1000000007
#define NN          100010


#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cout<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cout << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros


ll arr[100];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef redback
    //freopen("input.in", "r", stdin);
    //freopen("output.in", "w", stdout);
    //test by input1, input2  files for codeforces
#endif

    ll t = 1, tc;
    //cin >> tc ;
    ll n, m, h;
    while (cin >> n >> h >> m ) {
        ll i, j, k, l, r, x;

        mem(arr, -1);

        for (i = 0; i < m; ++i) {
            cin >> l >> r >> x;
            for (j = l; j <= r; ++j) {
                if (arr[j] == -1)
                    arr[j] = h;
                arr[j] = min(x, arr[j]);
            }
        }
        ll sum = 0;
        for (i = 1; i <= n; i++) {
            if (arr[i] == -1)
                sum += h * h;
            else
                sum += arr[i] * arr[i];
        }

        cout << sum << "\n";

    }
    return 0;
}
