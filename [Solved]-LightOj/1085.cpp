/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
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
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        100010

ll MaxVal;

ll tree[NN];
pair<ll,ll> a[NN];
ll b[NN];

ll update(ll idx,ll val)
{
    while(idx<=MaxVal)
    {
        tree[idx]=(tree[idx]+val)%mod;
        idx+=idx & (-idx);
    }
    return 0;
}

ll query(ll idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum=(sum+tree[idx])%mod;
        idx-=idx & (-idx);
    }
    return sum;
}

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    scanf("%d",&tc);

    ll i,j,k,l,m,n;
    while(tc--)
    {
        scanf("%lld",&n);

        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i].ft);
            a[i].second=i;
        }
        sort(a+1,a+n+1);
        memset(tree,0,sizeof(ll)*(n+2));

        b[0]=0;
        b[a[1].sd]=1;
        for(i=2;i<=n;i++)
        {
            if(a[i].ft==a[i-1].ft)
                b[a[i].sd]=b[a[i-1].sd];
            else
                b[a[i].sd]=b[a[i-1].sd]+1;
        }

        ll ret=0;
        MaxVal=b[a[n].sd];
        for(i=1;i<=n;i++)
        {
            ret=(query(b[i]-1)+1)%mod;
            update(b[i],ret);
        }
        printf("Case %d: %lld\n",t++,query(MaxVal));
    }
    return 0;
}
