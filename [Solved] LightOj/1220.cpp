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

#define NN 70000

bool p[NN+7]; //Hashing
vector<ll>pr,facts; //storing prime
void sieve(ll n)
{
    ll i,j,k,l;
    p[1]=1;
    pr.push_back(2);
    for(i=4;i<=n;i+=2)
        p[i]=1;
    for(i=3;i<=n;i+=2)
    {
        if(p[i]==0)
        {
            pr.push_back(i);
            for(j=i*i;j<=n;j+=2*i)
                p[j]=1;
        }
    }
}

ll factor(ll n)
{
    facts.clear();
    ll count,k,i;

    for(i=0;i<pr.size() && pr[i]*pr[i]<=n;i++)
    {
        k=pr[i];
        count=0;
        while(n%k==0)
        {
            n/=k;
            count++;
        }
        facts.pb(count);
        if(n==1)
            break;
    }
    if(n>1)
        facts.pb(1);
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    sieve(NN);

    ll t=1,tc;
    sf(tc);
    ll l,m,n;
    while(tc--) {
        ll i,j,l;
        sf(n);

        ll minusFlag=0;

        if(n<0)
        {
            n*=-1;
            minusFlag=1;
        }
        factor(n);

        ll ans=0;
        for(i=1;i<34;i++)
        {
            ll flag=1;
            for(j=0;j<facts.size();j++)
            {
                if(facts[j]%i!=0)
                {
                    flag=0;
                    break;
                }
            }
            if(minusFlag && i%2==0)
                continue;

            if(flag)
                ans=max(ans,i);
        }

        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
