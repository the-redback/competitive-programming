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

ll flag[NN];

vector<pair<ll,ll> >v,vv;
ll perm[]={0,1,2,3,4,5,6,7,8,9,10};

bool comp(pair<ll,ll>aa, pair<ll,ll> bb)
{
    if(aa.sd==bb.sd)
        return aa.ft<bb.ft;
    return aa.sd<bb.sd;

}

ll check(ll r)
{
    ll i=0;
    ll n=(ll)v.size();
    for(i=0;i<=n;i++)
        perm[i]=i;

    do
    {
        vv.clear();
        for(i=0;i<n;i++)
            vv.pb(v[perm[i]]);

        ll last=vv[0].ft;
        ll fl=1;
        for(i=1;i<vv.size();i++)
        {
            ll now=max(last+r,vv[i].ft);
            if(vv[i].sd<now)
            {
                fl=0;
                break;
            }
            last=now;
        }
        if(fl)
            return 1;
        //debug(perm[0],perm[1],perm[2]);
    }while(next_permutation(perm,perm+n));

    return 0;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n;
    while(~sf(n)) {
        ll i,j,k;

        if(n==0)
            return 0;
        v.clear();
        mem(flag,0);

        for(i=0;i<n;i++)
        {
            sf2(k,l);
            v.pb(mp(k*60000,l*60000));
        }
        sort(all(v),comp);

        ll low=0,high=10000000000;
        ll sum=0;

        while(low<=high)
        {
            ll mid=(low+high)/2;
            if(check(mid))
            {
                check(mid);
                sum=max(sum,mid);
                //debug(mid,low,high);
                low=mid+1;
            }
            else
                high=mid-1;
            //debug(mid,low,high);
        }
        ll hour=sum/60000;
        sum-=hour*60000;
        double dl=(double)sum/1000.0;


        printf("Case %lld: %lld:%02.00lf\n",t++,hour,dl);

    }
    return 0;
}
