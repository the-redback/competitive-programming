/**
 *    @author     : Maruf Tuhin
 *    @College    : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef unsigned long long llu;

#define ft         first
#define sd         second
#define mp         make_pair
#define pb(x)      push_back(x)
#define all(x)     x.begin(),x.end()
#define allr(x)    x.rbegin(),x.rend()
#define mem(a,b)   memset(a,b,sizeof(a))
#define sf(a)      scanf("%lld",&a)
#define ssf(a)     scanf("%s",&a)
#define sf2(a,b)   scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf        1e9
#define eps        1e-9
#define mod        1000000007
#define NN         100010

#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

ll a[1000];
ll vis[10000];
vector<ll>v;

int main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n;
    while(~sf(n)) {
        ll i,j,k;

        ll flag=0;

        for(i=1;i<=n;i++) sf(a[i]);

        for(i=1;i<=n;i++)
        {
            mem(vis,-1);
            k=i;
            j=0;
            while(vis[k]==-1)
            {
                j++;
                vis[k]=1;
                k=a[k];
            }
            if(k!=i)
            {
                flag=1;
                break;
            }
            if(j%2==0)
                v.pb(j/2);
            else
                v.pb(j);
        }

        if(flag)
        {
            printf("-1\n");
            continue;
        }

        ll lcm=v[0];
        for(i=1;i<v.size();i++)
        {
            lcm=(v[i]/__gcd(lcm,v[i]))*lcm;
        }
        printf("%lld\n",lcm);

        v.clear();



    }
    return 0;
}
