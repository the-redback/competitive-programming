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

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        505

#define read(a)   scanf("%lld",&a)


ll a[NN];
ll seq[1010];
ll fl[NN];
vector<pair<ll,ll> >v;

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~read(n))
    {
        v.clear();
        read(m);
        for(i=1;i<=n;i++)
        {
            read(a[i]);
        }
        mem(fl,0);
        for(i=0;i<m;i++)
        {
            read(k);
            seq[i]=k;
            if(fl[k]==0)
            {
                v.pb(mp(a[k],k));
                fl[k]=1;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(fl[i]==0)
                v.pb(mp(a[i],i));
        }
        ll ans=0;
        ll pos=-1;
        reverse(all(v));
        for(i=0;i<m;i++)
        {
            ll temp=0;
            for(j=n-1;j>=0;j--)
            {
                if(v[j].sd==seq[i])
                {
                    pos=j;
                    break;
                }
                temp+=v[j].ft;
            }
            ans+=temp;
            v.pb(v[pos]);
            v.erase(v.begin()+pos);
        }
        printf("%lld\n",ans);


    }
    return 0;
}

