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

int L[NN], R[NN], a[NN];


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef redback
    freopen("input2", "r", stdin);
    //freopen("output.in", "w", stdout);
    //test by input1, input2  files for codeforces
#endif

    ll t = 1, tc;
    //cin >> tc ;
    ll n, m;
    while (cin >> n >> m ) {
        ll i, j, k;
        mem(L, -1);
        mem(R, -1);
        mem(a, -1);

        for (i = 0; i < m; i++) {
            cin >> k;
            a[k] = 1;

            if ( a[k - 1] != -1) {
                L[k] = 1;
            }
            if ( a[k + 1] != -1) {
                R[k] = 1;
            }
        }

        ll sum = 0;

        for (int i = 1; i <= n; ++i) {
            debug(a[i], L[i], R[i])
            if (a[i] == -1) sum++;
            if (i != 1 && L[i] == -1) sum++;
            if (i != n && R[i] == -1) sum++;
        }

        cout << sum << "\n";

    }
    return 0;
}
