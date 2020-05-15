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

ll check(ll k)
{
    ll i,j,num=0;

    for(i=0;i<=k;i++)
    {
        if(i+1!=k)
            num|=1LL<<i;
    }
    return num;
}

int main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n;
    while(~sf2(n,m)) {
        ll i,j,k=0;

        for(i=0;i<=62;i++)
        {
            if((n&(1LL<<i)))
                k=i;
        }

        ll sum=0;
        if(k<1)
            k++;

        while(k>=1)
        {
            ll num=check(k);
            if(num>=n && num<=m)
                sum++;
            if(num>m)
                break;

            for(i=k-1;i>0;i--)
            {
                num|=1LL<<i;
                num= num & ~(1LL<<(i-1));
                if(num>=n && num<=m)
                sum++;
            }
            k++;
        }

        printf("%lld\n",sum);


    }
    return 0;
}
