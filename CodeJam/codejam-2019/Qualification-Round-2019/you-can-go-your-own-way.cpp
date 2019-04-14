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

char s[100010];
char ans[100010];
ll N;

bool poss(ll i, ll x, ll y, ll xi, ll yi, char dir) {
    ll xx = x, yy = y, xxi = xi, yyi = yi;
    if (dir == 'E') {
        yy = y + 1;
    } else {
        xx = x + 1;
    }
    if (xx >= N || yy >= N)
        return false;

    if (s[i] == 'E') {
        yyi = y + 1;
    } else {
        xxi = x + 1;
    }
    if (x == xi && y == yi && xx == xxi && yy == yyi)
        return false;

    if (xx != xxi || yy != yyi)
        return true;

    // two future point at same position
    if (s[i + 1] == 0)
        return true;

    if (s[i + 1] == 'E') {
        xx += 1;
    } else if (s[i + 1] == 'S') {
        yy += 1;
    }
    if (xx >= N || yy >= N)
        return false;
    return true;
}

int main() {
#ifdef redback
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif

    ll t = 1, tc;
    sf(tc);
    ll n, m;
    while (tc--) {
        sf(n);
        ssf(s);
        ll l = strlen(s);
        N = n;
        ll i, j = 0, k = 0;

        ll xi = 0, yi = 0;
        ll x = 0, y = 0;

        ll fl = 0;

        for (i = 0; i < l; i++) {
            if (fl && poss(i, x, y, xi, yi, 'E')) {
                ans[i] = 'E';
                y += 1;
                fl ^= 1;
            } else if (!fl && poss(i, x, y, xi, yi, 'S')) {
                ans[i] = 'S';
                x += 1;
                fl ^= 1;
            } else if (poss(i, x, y, xi, yi, 'S')) {
                ans[i] = 'S';
                x += 1;
            } else if (poss(i, x, y, xi, yi, 'E')) {
                ans[i] = 'E';
                y += 1;
            }

            if (s[i] == 'E') {
                yi += 1;
            } else if (s[i] == 'S') {
                xi += 1;
            }
        }
        ans[l] = 0;


        printf("Case #%lld: %s\n", t++, ans);
    }
    return 0;
}
