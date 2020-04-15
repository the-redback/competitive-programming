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
#define ft           first
#define sd           second
#define mp           make_pair
#define pb(x)        push_back(x)
#define all(x)       x.begin(),x.end()
#define allr(x)      x.rbegin(),x.rend()
#define mem(a, b)    memset(a,b,sizeof(a))
#define sf(a)        scanf("%lld",&a)
#define ssf(a)       scanf("%s",a)
#define sf2(a, b)    scanf("%lld %lld",&a,&b)
#define sf3(a, b, c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf          1e9
#define eps          1e-9
#define mod          1000000007
#define NN           100010


#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cout<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cout << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

map<pair<int, int>, int> vis;
vector<pair<int, int> > v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef redback
    freopen("input4", "r", stdin);
    //freopen("output.in", "w", stdout);
    //test by input1, input2  files for codeforces
#endif
    v.clear();

    ll t = 1, tc;
    //cin >> tc ;
    ll n, m;
    while (cin >> n >> m ) {
        ll i, j, k;
        for (i = 0; i < m; ++i) {
            cin >> j >> k;
            vis[mp(j, k)] = 1;
            vis[mp(k, j)] = 1;
            v.pb(mp(j, k));
        }


        bool res = false;
        for (i = 1; i < n; i++) {
            int ii;
            for (ii = 0; ii < v.size(); ii++) {
                k = (v[ii].first + i) % n;
                if (k == 0) k = n;
                j = (v[ii].second + i) % n;
                if (j == 0) j = n;
                if (vis.find(mp(k, j)) == vis.end()) {
                    debug(k,j)
                    break;
                }
            }

            if (ii == v.size())
                res = true;
        }
        if (res )
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";

    }
    return 0;
}
