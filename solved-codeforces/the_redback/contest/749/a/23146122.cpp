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
struct  debugger
{
    template<typename T>debugger& operator ,(const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

vector<ll>v;

int main()
{
#ifdef redback
   // freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n;
    while(~sf(n))
    {
        ll i,j,k;

        for(i=2; i<=n; i++)
        {
            k=i;
            while(n-k>1 || n-k==0)
            {
                n-=k;
                v.pb(k);
            }
            if(n==1)
                break;
        }
        if(n>1)
            v.pb(n);

        printf("%lld\n",(ll)v.size());
        for(i=0;i<v.size();i++)
        {
            if(i!=0)
                printf(" ");
            printf("%lld",v[i]);
        }
        puts("");
        v.clear();

    }
    return 0;
}
