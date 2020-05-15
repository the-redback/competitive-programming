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
typedef unsigned long long llu;

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
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cerr << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros


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
        ll i, j, k, l;
        if (m * (m - 1) < n)
        {
            printf("NO\n");
            continue;
        }

        printf("YES\n");

        j = 1, k = 2, l = 0;
        for (i = 0; i < n; ++i)
        {
            if (j == m + 1)
            {
                j = 1;

                l++;
                k = 2;
                k += l;
            }
            k = k % (m + 1);
            if (k == 0)
                k = 1;

            printf("%lld %lld\n", j, k);
            j++;
            k++;
        }
    }
    return 0;
}
