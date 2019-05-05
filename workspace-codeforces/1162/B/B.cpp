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

ll a[60][60], b[60][60];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef redback
    freopen("input1", "r", stdin);
    //freopen("output.in", "w", stdout);
    //test by input1, input2  files for codeforces
#endif

    ll t = 1, tc;
    //cin >> tc ;
    ll n, m;
    while (cin >> n >> m ) {
        ll i, j, k;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }

        bool result = true;


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ll x = min(a[i][j], b[i][j]);
                ll y = max(a[i][j], b[i][j]);
                a[i][j] = x;
                b[i][j] = y;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i != 0 && a[i][j] <= a[i - 1][j] ) || (j != 0 && a[i][j] <= a[i][j - 1] ) || ( i != 0 && b[i][j] <= b[i - 1][j]) || (j != 0 && b[i][j] <= b[i][j - 1]) ) {
                    result = false;
                    break;
                }
            }
        }

        if (result) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }
    return 0;
}
