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

vector<ll>E[NN];
ll vis[NN];
ll col[NN];
ll res[NN];

ll rec(ll u)
{
    vis[u]=1;
    ll temp=-1;
    ll ad=0;

    for(ll i=0;i<E[u].size();i++)
    {
        ll v=E[u][i];
        if(col[u]!=col[v])
        {
            res[u]=1;
            res[v]=1;
        }

        if(vis[v]==-1)
        {
            rec(v);
        }
    }
    return 0;
}

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
        mem(vis,-1);
        mem(col,-1);

        for(i=0;i<n-1;i++)
        {
            sf2(j,k);
            E[j].pb(k);
            E[k].pb(j);
        }
        for(i=1;i<=n;i++)
            sf(col[i]);

        mem(res,0);
        rec(1);

        ll ans=0;
        ll node=1;
        ll tans=0;

        for(i=1;i<=n;i++)
            ans+=res[i];

        for(i=1;i<=n;i++)
        {
            ll u=i;
            if(res[u]==1)
            {
                tans=1;
                for(j=0;j<E[u].size();j++)
                {
                    ll v=E[u][j];
                    if(res[v]==1)
                        tans++;
                }
            }
            if(tans==ans)
            {
                node=u;
                break;
            }
        }


        if(ans==tans)
            printf("YES\n%lld\n",node);
        else
            printf("NO\n");

        for(i=0;i<=n;i++)
            E[i].clear();

    }
    return 0;
}
