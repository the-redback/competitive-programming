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
#define NN         300010

#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

char s[NN],ss[NN];

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
        strcpy(ss,"1");

        ll ans=-1;
        ll cnt=0;

        for(i=0;i<n;i++)
        {
            ll z=0,ot=0,on=0;
            scanf("%s",&s);
            for(j=0;s[j];j++)
            {
                if(s[j]=='1')
                    on++;
                else if(s[j]!='1' && s[j]!='0')
                    ot=1;
                if(s[j]=='0')
                    z++;
            }
            if(ot==1 || on>1)
            {
                strcpy(ss,s);
            }
            else if(on==0 && ot==0)
                ans=0;
            else
                cnt+=z;
        }

        if(ans==0)
            printf("0\n");
        else
        {
            printf("%s",ss);
            for(i=0;i<cnt;i++)
                printf("0");
            puts("");
        }

    }
    return 0;
}
