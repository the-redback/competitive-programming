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
#define NN        200100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

ll MaxVal;

ll tree[NN];
pair<ll,ll> a[NN];

ll update(ll idx,ll val)
{
    while(idx<=MaxVal)
    {
        tree[idx]+=val;
        idx+=idx & (-idx);
    }
    return 0;
}

ll query(ll idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx & (-idx);
    }
    return sum;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1,tc;
    cin>>tc;

    ll i,j,k,l,m,n;
    while(tc--)
    {
        cin>>n;
        MaxVal=n;
        for(i=0;i<n;i++)
        {
            cin>>a[i].ft;
            a[i].second=i+1;
        }
        sort(a,a+n);
        memset(tree,0,sizeof(ll)*(n+1));

        ll ret=0;
        for(i=n-1;i>=0;i--)
        {
            ret+=query(a[i].second);
            update(a[i].second,1);
        }
        cout<<ret<<"\n";
    }
    return 0;
}
