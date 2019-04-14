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
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cerr << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

ll a[4000];
ll cc[4000];
ll ans[25][25];
int main()
{
#ifdef redback
    freopen("input.in", "r", stdin);
    //freopen("output.in", "w", stdout);
#endif

    ll t = 1, tc;
    //sf(tc);
    ll n, m;
    while (~sf(n)) {
        ll i, j, k;
        ll mx = 0;
        ll chk = -1;
        mem(cc, 0);
        mem(ans, -1);
        for (i = 0; i < n * n; i++) {
            sf(a[i]);
            cc[a[i]]++;
            mx = max(mx, a[i]);
        }
        sort(a, a + n);
        for (i = 0; i < n && chk == -1; i++)
        {
            for (j = 0; j < n && chk == -1; j++)
            {
                if (ans[i][j] == -1) {
                    int cnt = 1;
                    if (i != n - 1 - i) cnt++;
                    if (j != n - 1 - j) cnt++;
                    if (i != n - 1 - i && j != n - 1 - j) cnt++;
                    ll num = -1;

                    for (k = 0; k <= mx; k++)
                    {
                        if (cc[k] >= cnt && cnt == 2) {
                            if (cnt == 2 && cc[k] % 4 != 0) {
                                num = k;
                                break;
                            } else {
                                num = k;
                            }
                        } else if (cc[k] >= cnt) {
                            num = k;
                            break;
                        }
                    }
                    if (num == -1)
                    {
                        chk = 0;
                        break;
                    }
                    cc[num] -= cnt;
                    ans[i][j] = num;
                    ans[n - 1 - i][j] = num;
                    ans[i][n - 1 - j] = num;
                    ans[n - 1 - i][n - 1 - j] = num;
                }
            }
        }
        if (chk != -1)
        {
            printf("NO\n");
            continue;
        }

        printf("YES\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (j != 0) printf(" ");
                printf("%lld", ans[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}