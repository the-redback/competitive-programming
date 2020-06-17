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
#define NN         101

#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

ll dp[10][NN][NN][2];
char s[20],ss[20];
ll a[20];
ll N,K;

ll call(ll pos,ll moded,ll sum,ll smaller)
{
    if(pos>=N)
    {
        if(moded==0 && sum%K==0)
            return 1;
        return 0;
    }

    ll &tc=dp[pos][moded][sum][smaller];

    if(tc!=-1)
        return tc;

    tc=0;

    for(ll i=0;i<=9;i++)
    {
        if(smaller)
        {
            tc+=call(pos+1,(moded*10+i)%K,(sum+i)%K,smaller);
        }
        else if(i<a[pos])
        {
            tc+=call(pos+1,(moded*10+i)%K,(sum+i)%K,1);
        }
        else if(i==a[pos])
        {
            tc+=call(pos+1,(moded*10+i)%K,(sum+i)%K,0);
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

        scanf("%s",s);
        scanf("%s",ss);
        sf(K);

        if(K>90)
        {
            printf("Case %lld: 0\n",t++);
            continue;
        }

        N=strlen(s);
        for(i=0;i<N;i++) a[i]=s[i]-'0';
        mem(dp,-1);
        ll sum1=call(0,0,0,0);

        N=strlen(ss);
        for(i=0;i<=N;i++) a[i]=ss[i]-'0';
        mem(dp,-1);
        ll sum2=call(0,0,0,0);

        // as s is part of [s,ss];
        sscanf(s,"%lld",&k);
        ll numSum=0;
        for(i=0;s[i];i++) numSum=numSum+a[i];

        if(k%K==0 && numSum%K==0)
            sum1--;


        printf("Case %lld: %lld\n",t++,sum2-sum1);



    }
    return 0;
}
