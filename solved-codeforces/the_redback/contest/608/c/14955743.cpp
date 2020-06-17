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

ll dp[NN];
vector<ll>v;
pair<ll,ll>a[NN],pp;


ll call(ll pos)
{
    if(pos<0)
        return 0;
    if(pos==0)
        return 1;

    ll &tc=dp[pos];

    if(tc!=-1)
        return tc;

    vector<ll>::iterator low;


    pp=a[pos];
    ll ind=pp.ft-pp.sd;

    low=lower_bound (v.begin(), v.end(), ind);
    ll in=low- v.begin();
    tc=call(in-1)+1;

    return tc;
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

        for(i=0;i<n;i++)
        {
            sf2(k,l);
            a[i]=mp(k,l);
        }
        sort(a,a+n);

        for(i=0;i<n;i++)
        {
            v.pb(a[i].ft);
        }

        mem(dp,-1);

        ll sum=0,ind=-1;

        for(i=n-1;i>=0;i--)
        {
            sum=max(sum,call(i));
        }
        printf("%lld\n",n-sum);

        v.clear();



    }
    return 0;
}
