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
#define NN         200010

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

ll a[NN],b[NN];
pair<ll,pair<ll,ll> >q[NN];
deque<ll>dq;
vector<ll>v;

int main()
{
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n;
    while(~sf2(n,m))
    {
        dq=deque<ll>();
        v.clear();
        ll i,j,k,r;
        ll last=-1;

        for(i=0; i<n; i++)
            sf(a[i]);

        for(i=0; i<m; i++)
        {
            sf2(l,k);
            q[i]=mp(k-1,mp(i,l));
        }

        sort(q,q+m);
        reverse(q,q+m);

        ll lmt=n;

        k=q[0].ft;
        last=q[0].sd.ft;
        tc=q[0].sd.sd;
        lmt=k+1;
        sort(a,a+lmt);

        for(i=n-1; i>=k+1; i--)
            v.pb(a[i]);
        for(i=0; i<=k; i++)
            dq.push_back(a[i]);


        for(i=1; i<m; i++)
        {
            k=q[i].ft;
            if(q[i].sd.ft>last)
            {
                for(j=k+1; j<lmt; j++)
                {
                    if(tc==2)
                    {
                        v.pb(dq.front());
                        dq.pop_front();
                    }
                    else
                    {
                        v.pb(dq.back());
                        dq.pop_back();
                    }
                }
                tc=q[i].sd.sd;
                lmt=k+1;
                last=q[i].sd.ft;
            }
        }

        while(dq.size())
        {
            if(tc==2)
            {
                v.pb(dq.front());
                dq.pop_front();
            }
            else
            {
                v.pb(dq.back());
                dq.pop_back();
            }
        }

        reverse(all(v));
        for(i=0; i<v.size(); i++)
        {
            if(i!=0)
                printf(" ");
            printf("%lld",v[i]);
        }
        printf("\n");
    }


    return 0;
}
