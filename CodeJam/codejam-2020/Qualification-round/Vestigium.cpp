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

int row[111][111];
int col[111][111];

bool dupl(int a[], int n) {
    sort(a,a+n);
    for (int i = 0; i < n; ++i) {
        if(a[i]!=i+1){
            return true;
        }
    }
    return false;
}


int main() {
#ifdef redback
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    ll t = 1, tc;
    cin >> tc ;
    ll n, m;
    while ( tc--) {
        cin >> n;
        ll i, j, k, sum=0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>k;

                if (i==j) {
                    sum+=k;
                }

                row[i][j]=k;
                col[j][i]=k;
            }
        }

        int r=0,c=0;

        for (int i = 0; i < n; ++i) {
            if(dupl(row[i], n)){
                r++;
            }
        }

        for (int i = 0; i < n; ++i) {
            if(dupl(col[i], n)){
                c++;
            }
        }

        printf("Case #%d: %d %d %d\n",t++,sum,r,c);

    }
    return 0;
}
