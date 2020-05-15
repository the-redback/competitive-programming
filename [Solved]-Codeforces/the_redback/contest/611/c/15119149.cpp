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
#define repv(i,a)  for(i=0;i<(ll)a.size();i++)
#define revv(i,a)  for(i=(ll)a.size()-1;i>=0;i--)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define sf(a)      scanf("%lld",&a)
#define sf2(a,b)   scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf        1e9
#define eps        1e-9
#define mod        1000000007
#define NN         515

#ifdef  redback
#define bug prrintf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

ll tree[NN][NN];
char arr[NN][NN];
ll max_x,max_y;


void update(ll idx,ll idy,ll val)
{
    ll y;
    while(idx<=max_x)
    {
        y=idy;
        while(y<=max_y)
        {
            tree[idx][y]+=val;
            y+=y & -y;
        }
        idx+=idx & -idx;
    }
    return;
}

ll query(ll idx,ll idy)
{
    ll sum=0,y;
    while(idx>0)
    {
        y=idy;
        while(y>0)
        {
            sum+=tree[idx][y];
            y-=y & -y;
        }
        idx-=idx & -idx;
    }
    return sum;
}

main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif
    ll t=1,tc;
    ll i,j,k,l,n,m;
    ll x1,x2,y1,y2;
    ll r;
    while(~sf2(n,m))
    {
        max_x=n+10;
        max_y=m+10;

        mem(tree,0);
        for(i=1;i<=n;i++)
        {
            scanf("%s",arr[i]+1);
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(arr[i][j-1]=='.' &&  arr[i][j]=='.')
                {
                    update(i,j,1);
                    update(i,j-1,1);
                }
                if(arr[i][j]=='.' && arr[i-1][j]=='.')
                {
                    update(i-1,j,1);
                    update(i,j,1);
                }
            }
        }

        sf(r);

        while(r--)
        {
            sf2(x1,y1);
            sf2(x2,y2);
            ll temp=query(x2,y2);
                temp-=query(x2,y1-1);
                temp-=query(x1-1,y2);
                temp+=query(x1-1,y1-1);

            for(i=x1;i<=x2;i++)
            {
                if(arr[i][y1]=='.' &&  arr[i][y1-1]=='.') temp--;
                if(arr[i][y2]=='.' &&  arr[i][y2+1]=='.') temp--;
            }
            for(i=y1;i<=y2;i++)
            {
                if(arr[x1][i]=='.' &&  arr[x1-1][i]=='.') temp--;
                if(arr[x2][i]=='.' &&  arr[x2+1][i]=='.') temp--;
            }

                printf("%lld\n",temp/2);
        }
    }
    return 0;
}
