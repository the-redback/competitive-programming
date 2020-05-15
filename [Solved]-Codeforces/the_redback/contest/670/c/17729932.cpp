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
#define inf        1e9
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

vector<pair<ll,pair<ll,ll> > >v;
map<ll,ll>mmp;

ll aa[NN],bb[NN];

bool comp (pair<ll,pair<ll,ll> > a,pair<ll,pair<ll,ll> > b)
{
    if(a.sd.ft==b.sd.ft)
        return a.sd.sd>b.sd.sd;
    return a.sd.ft>b.sd.ft;
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

        mmp.clear();

        for(i=0;i<n;i++)
        {
            sf(k);
            if(mmp.find(k)==mmp.end())
                mmp[k]=1;
            else
                mmp[k]++;
        }

        v.clear();

        sf(m);

        for(i=0;i<m;i++) sf(aa[i]);
        for(i=0;i<m;i++) sf(bb[i]);

        for(i=0;i<m;i++)
        {
            j=aa[i];
            k=bb[i];
            v.pb(mp(i,mp(mmp[j],mmp[k])));
        }

        sort(all(v),comp);

        printf("%lld\n",v[0].ft+1);


    }
    return 0;
}
