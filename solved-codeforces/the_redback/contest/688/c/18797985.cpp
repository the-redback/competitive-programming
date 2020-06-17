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
#define sf2(a,b)   scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf        1e9
#define eps        1e-9
#define mod        1000000007
#define NN         100010

#ifdef  redback
#define bug prllf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

vector <ll> v[NN];
ll view[NN];
ll N,flag;
void bfs(ll u)
{
    ll i;
    queue <ll> q;
    q.push(u);
    view[u]=1;
    while(q.size())
    {
        ll n=q.front();
        for(i=0; i<v[n].size(); i++)
        {
           // ll uu=v[n][i];
            if(view[v[n][i]]==0)
            {
                q.push(v[n][i]);
                view[v[n][i]]=view[n]+1;
            }
            else if(view[v[n][i]]%2==view[n]%2)
            {
             //   debug(uu,n);
                flag=1;
                return;
            }
        }
        q.pop();
    }
}

main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n;
    while(~sf2(n,m)) {
        ll i,j,k;
        mem(view,0);
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&k,&l);
            v[k].push_back(l);
            v[l].push_back(k);
        }
        flag=0;

        for(i=1;i<=n;i++)
        {
            if(flag==0 && view[i]==0)
                bfs(i);
        }

        if(flag==1)
        {
            puts("-1");
            continue;
        }
        ll ret=0,ret2=0;

        for(i=1;i<=n;i++)
        {
            if(view[i]%2==0)
            {
                ret++;
            }
            else
                ret2++;
        }
        printf("%lld\n",ret);
        ll fl=0;
        for(i=1;i<=n;i++)
        {
            if(view[i]%2==0)
            {
                if(fl!=0)
                    printf(" ");
                printf("%lld",i);
                fl++;
            }
        }
        printf("\n");

        printf("%lld\n",ret2);
        fl=0;
        for(i=1;i<=n;i++)
        {
            if(view[i]%2!=0)
            {
                if(fl!=0)
                    printf(" ");
                printf("%lld",i);
                fl++;
            }
        }
        printf("\n");
    }
    return 0;
}
