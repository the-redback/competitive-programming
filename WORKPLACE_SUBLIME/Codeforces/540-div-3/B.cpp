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
#define NN           100010


#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cerr<<":: "; dbg,args; cerr<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cerr << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

ll a[200010], L[200010], R[200010];

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
        for (i = 0; i < n; i++)
        {
            sf(a[i]);
            if (i < 2) L[i] = a[i];
            else L[i] = L[i - 2] + a[i];
        }

        R[n - 1] = a[n - 1];
        R[n - 2] = a[n - 2];

        for (i = n - 3; i >= 0; i--) R[i] = R[i + 2] + a[i];

        ll LL = 0, RR = 0, LL1 = 0, RR1 = 0, sum = 0;

        for (int i = 0; i < n; i++)
        {
            LL = 0, RR = 0, LL1 = 0 , RR1 = 0;
            if (i > 0) RR = L[i - 1];
            if (i > 1) LL = L[i - 2];

            if (i < n - 1) LL1 = R[i + 1];
            if (i < n - 2) RR1 = R[i + 2];

            debug(i, a[i], LL, RR, LL1, RR1);

            if (LL + LL1 == RR + RR1) sum++;

        }
        printf("%lld\n", sum);
    }
    return 0;
}
