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

char a[NN];
ll N;

ll dp[NN][3][3];

ll call(ll pos, ll last, ll st)
{
    if(pos>=N)
        return 0;

    ll &tc=dp[pos][last][st];

    if(tc!=-1)
        return tc;

    ll sum=0;

    sum=call(pos+1,last,st);

    if(last==2)
    {
        sum=max(sum,call(pos+1,a[pos]-'0',st)+1);
    }
    else if(last==0)
    {
        if(a[pos]=='1' && st!=1)
        {
            sum=max(sum,call(pos+1,1,st)+1);
        }
        if(a[pos]=='1' && st==1)
        {
            sum=max(sum,call(pos+1,1,0)+1);
        }
        if(a[pos]=='0' && st==1)
        {
            sum=max(sum,call(pos+1,1,st)+1);
        }
        if(a[pos]=='0' && st==2)
        {
            sum=max(sum,call(pos+1,1,1)+1);
        }
    }
    else if(last==1)
    {
        if(a[pos]=='0' && st!=1)
        {
            sum=max(sum,call(pos+1,0,st)+1);
        }
        if(a[pos]=='0' && st==1)
        {
            sum=max(sum,call(pos+1,0,0)+1);
        }
        if(a[pos]=='1' && st==1)
        {
            sum=max(sum,call(pos+1,0,st)+1);
        }
        if(a[pos]=='1' && st==2)
        {
            sum=max(sum,call(pos+1,0,1)+1);
        }
    }

    tc=sum;
    return tc;
}



int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n;
    while(~sf(n)) {
        ll i,j,k;
        N=n;

        scanf("%s",&a);
        mem(dp,-1);

        printf("%lld\n",call(0,2,2));

    }
    return 0;
}
