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
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
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
    while (~sf(n)) {
        ll i, j, k;
        ll mx=0;
        ll ret=0;
        for (i = 1; i <= n; ++i)
        {
            sf(k);
            mx=max(mx,k);
            if(mx<=i)
                ret++;
        }
        printf("%lld\n",ret);

    }
    return 0;
}
