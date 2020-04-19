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
ll a[12];
char s[20],ss[20];
ll dp[12][2][2][12];

ll call(ll pos,ll smaller,ll firstDigit,ll total)
{
    if(pos>=N)
    {
        return total;
    }

    ll &tc=dp[pos][smaller][firstDigit][total];

    if(tc!=-1)
        return tc;

    tc=0;

    for(ll i=0;i<=9;i++)
    {
        if(a[pos]==i)
        {
            if(i==0 && firstDigit)
                tc+=call(pos+1,smaller,firstDigit,total+1);
            else if(i==0)
                tc+=call(pos+1,smaller,firstDigit,total);
            else
                tc+=call(pos+1,smaller,1,total);
        }
        else if(a[pos]>i || smaller==1)
        {
            if(i==0 && firstDigit)
                tc+=call(pos+1,1,firstDigit,total+1);
            else if(i==0)
                tc+=call(pos+1,1,firstDigit,total);
            else if(i>0)
                tc+=call(pos+1,1,1,total);
        }
    }
    return tc;
}


int main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    sf(tc);
    ll l,m,n;
    while(tc--) {
        ll i,j,k;
        scanf("%s %s",&s,&ss);

        N=strlen(s);
        ll temp=0;
        for(ll i=0;s[i];i++)
        {
            a[i]=s[i]-'0';
            if(a[i]==0)
                temp++;
        }
        mem(dp,-1);
        ll sum1=call(0,0,0,0);


        N=strlen(ss);
        for(ll i=0;ss[i];i++)
            a[i]=ss[i]-'0';
        mem(dp,-1);
        ll sum2=call(0,0,0,0);

        printf("Case %lld: %lld\n",t++,sum2-sum1+temp);
    }
    return 0;
}
