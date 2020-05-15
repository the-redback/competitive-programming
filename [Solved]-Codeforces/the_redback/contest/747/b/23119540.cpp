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

char a[100000];

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
        ll aa=0,cc=0,gg=0,tt=0,uu=0;
        ssf(a);

        for(i=0;i<n;i++)
        {
            if(a[i]=='A') aa++;
            if(a[i]=='C') cc++;
            if(a[i]=='G') gg++;
            if(a[i]=='T') tt++;
            if(a[i]=='?') uu++;
        }
        k=n/4;

        if(n%4!=0 || aa>k || cc>k || gg>k || tt>k)
        {
            printf("===\n");
            continue;
        }

        for(i=0;i<n;i++)
        {
            if(a[i]=='?')
            {
                if(aa<k)
                {
                    aa++;
                    a[i]='A';
                }
                else if(cc<k)
                {
                    cc++;
                    a[i]='C';
                }
                else if(gg<k)
                {
                    gg++;
                    a[i]='G';
                }
                else if(tt<k)
                {
                    tt++;
                    a[i]='T';
                }
            }
        }
        puts(a);

    }
    return 0;
}
