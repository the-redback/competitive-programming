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
#define NN         100010

#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

ll N;
ll a[50];
ll dp[50][2][2][50];

ll call(ll pos,ll smaller, ll prev,ll total)
{
    if(pos>=N)
    {
        return total;
    }

    ll &tc=dp[pos][smaller][prev][total];

    if(tc!=-1)
        return tc;

    tc=0;

    for(ll i=0;i<=1;i++)
    {
        if(smaller || a[pos]==i)
        {
            if(i==1 && prev==1)
                tc+=call(pos+1,smaller,i,total+1);
            else
                tc+=call(pos+1,smaller,i,total);
        }
        else if(a[pos]>i)
        {
            tc+=call(pos+1,1,i,total);
        }

    }
    return tc;


}



int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    sf(tc);
    ll l,m,n;
    while(tc--) {
        ll i,j,k;
        sf(n);

        i=0;
        while(n>0)
        {
            a[i]=n%2;
            n/=2;
            i++;
        }
        N=i;

        reverse(a,a+N);

        mem(dp,-1);

        printf("Case %lld: %lld\n",t++,call(0,0,0,0));
    }
    return 0;
}
