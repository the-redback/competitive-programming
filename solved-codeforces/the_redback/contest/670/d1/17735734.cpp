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
#define sf2(a,b)   scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf        1e12
#define eps        1e-9
#define mod        1000000007
#define NN         200010

#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

ll a[NN],b[NN];
ll c[NN];
vector<pair<ll, pair<ll,ll> > >v;
int main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n,k;
    while(~sf2(n,k)) {
        ll i,j;

        for(i=0;i<n;i++) sf(a[i]);
        for(i=0;i<n;i++) sf(b[i]);

        ll ret=inf;

        for(i=0;i<n;i++)
        {
            c[i]=b[i]/a[i];
            b[i]=b[i]%a[i];
            ret=min(ret,c[i]);
            //v.pb(mp(c[i],mp(b[i],a[i])));
        }

        //sort(all(v));
        ll sum=ret;

        for(i=0;i<n;i++)
            c[i]-=ret;



        for(j=0;j<1000;j++)
        {
            ret=inf;
            ll fl=1;
            for(i=0;i<n;i++)
            {
                if(c[i]==0)
                {
                    if((a[i]-b[i])<=k)
                    {
                        l=a[i]-b[i];
                        k=k-(a[i]-b[i]);
                        b[i]=0;
                    }
                    else
                    {
                        fl=0;
                        break;
                    }
                }
                else
                    c[i]--;
            }
            if(fl==0)
            {
                break;
            }
            sum++;
        }


        printf("%lld\n",sum);


    }
    return 0;
}
