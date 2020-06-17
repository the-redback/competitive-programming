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
    ll     i, j, k, n;
    string str;
    cin >> str;

    ll a[5];
    a[1]=-1;
    a[2]=-1;
    a[3]=-1;
    ll ans=inf;
    for(i=0;i<str.size(); i++){
        a[str[i]-'0']=i;

        if(a[1]!= -1 && a[2] != -1 && a[3] != -1){
            ll mx=min(a[1],a[2]);
            mx=min(mx,a[3]);
            ans=min((i-mx+1),ans);
        }
    }

    if(ans==inf){
        cout<<"0\n";
        return;
    }

    cout << ans << "\n";
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
