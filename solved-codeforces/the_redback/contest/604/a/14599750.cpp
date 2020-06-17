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

double mm[10];
double ww[10];
double xx[10]={500,1000,1500,2000,2500};

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        //freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //sf(tc);
    double l,m,n;
    while(cin>>mm[0]) {
        double j,k;
        ll i;

        for(i=1;i<5;i++) cin>>mm[i];
        for(i=0;i<5;i++) cin>>ww[i];
        cin>>m;
        cin>>n;

        double sum=0;

        for(i=0;i<5;i++)
        {
            double x=xx[i]*0.3;
            double y=((1-(mm[i]/250))*xx[i])-(50*ww[i]);
            sum+=max(x,y);

        }

        sum+=100.0*m;
        sum-=50.0*n;

        printf("%.0lf\n",sum);

    }
    return 0;
}
