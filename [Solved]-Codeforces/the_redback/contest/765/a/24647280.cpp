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

char home[10];
vector<string>v;
char a[10],b[10];
string s,ss;


map<string,ll>mmp;

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
        mmp.clear();
        mem(b,0);
        v.clear();

        ssf(home);
        s.assign(home);

        for(i=0;i<n;i++)
        {
            scanf("%s",&a);
            b[0]=a[5];
            b[1]=a[6];
            b[2]=a[7];
            b[3]=0;
            a[3]=0;
            if(mmp.find(a)==mmp.end())
            {
                mmp[a]=0;
                v.pb(a);
            }
            if(mmp.find(b)==mmp.end())
            {
                mmp[b]=0;
                v.pb(b);
            }
//            debug(b);
            mmp[a]++;
            mmp[b]++;
        }
        ll flag=0;
        for(i=0;i<v.size();i++)
        {
            if(mmp[v[i]]%2==1)
            {
                flag=1;
            }
        }

        if(flag)
            puts("contest");
        else
            puts("home");

    }
    return 0;
}
