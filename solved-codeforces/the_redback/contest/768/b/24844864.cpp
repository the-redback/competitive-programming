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

ll num=0;

ll rec(ll n,ll l,ll r)
{
    if(n<=1)
    {
        if(n==1)
            num++;
       //debug(n);
        return 1;
    }
    ll len=0;
    ll i;
    for(i=55;i>=0;i--)
    {
        if(n&(1LL<<i))
        {
            len=i;
            break;
        }
    }
    ll ret=1,rp=1;
    for(i=1;i<=len;i++)
    {
        rp*=2;
        ret+=rp;
    }
    ll mid=ret/2+1;
    ll sum=0;
    if(l<mid)
        sum+=rec(n/2,l,min(mid-1,r));
    if(mid>=l && mid<=r)
    {
        sum++;
        if(n%2==1)
            num++;
        //debug(n%2);

    }
    if(r>mid)
        sum+=rec(n/2,l+sum-mid,r-mid);
    return sum;
}

int main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n,r;
    while(~sf3(n,l,r)) {
        ll i,j,k;
        num=0;
        rec(n,l,r);

        printf("%lld\n",num);

    }
    return 0;
}
