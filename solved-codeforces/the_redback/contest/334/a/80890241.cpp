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

void solve(ll n) {
    ll i, j, k;
    ll m;

    k=1;

    vector<ll> v[n+10];

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            v[j].push_back(k++);
        }
        for ( j = n-1; j >=0; j--)
        {
            v[j].push_back(k++);
        }
        
    }

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    // cin >> tc;
    ll n, m;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}
