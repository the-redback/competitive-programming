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
typedef unsigned long long llu;

#define ft           first
#define sd           second
#define mp           make_pair
#define pb(x)        push_back(x)
#define all(x)       x.begin(),x.end()
#define allr(x)      x.rbegin(),x.rend()
#define mem(a, b)    memset(a,b,sizeof(a))
#define sf(a)        scanf("%lld",&a)
#define ssf(a)       scanf("%s",&a)
#define sf2(a, b)    scanf("%lld %lld",&a,&b)
#define sf3(a, b, c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf          1e9
#define eps          1e-9
#define mod          1000000007
#define NN           200010


#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cerr << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

ll a[NN];

bool compare(ll n, ll m) {
    return n > m;
}

int main()
{
#ifdef redback
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif

    ll t = 1, tc;
    //sf(tc);
    ll n, m;
    while (~sf2(n, m)) {
        ll i, j, k = 0;
        for (i = 0; i < n; i++) {
            sf(a[i]);
            k += a[i];
        }
        if (k < m) {
            printf("-1\n");
            continue;
        }
        sort(a, a + n, compare);
        k = 0;
        int low = 1, high = n - 1;
        ll ans = n;
        while (low <= high) {
            ll mid = (low + high) / 2.0;
            k = 0;
            for (i = 0; i < n; i++)
            {
                k += max(0ll, a[i] - (i / mid));
            }
            if (k >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        printf("%lld\n", ans);

    }
    return 0;
}
