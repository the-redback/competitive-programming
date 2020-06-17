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

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

ll n,m,w;
ll a[NN];
ll start[NN];

bool check(ll val)
{
    ll done=0;
    ll move=0;
    mem(start,0);
    for(ll i=0;i<n;i++)
    {
        if(i-w>=0)
            done-=start[i-w];
        if(a[i]+done<val)
        {
            start[i]+=val-a[i]-done;
            done+=start[i];
            move+=start[i];
        }
        if(move>m)
            return 0;
    }
    if(move<=m)
        return 1;
    return 0;
}



main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    ll i,j,k,l;
    cin>>n>>m>>w;
    for(i=0;i<n;i++)
        cin>>a[i];
    ll low=0;
    ll high=1000200000;
    ll ans=0;
    while(low<=high)
    {
        ll mid=(low+high)/2.0;
        if(check(mid))
        {
            low=mid+1;
            ans=mid;
        }
        else
            high=mid-1;
    }
    cout<<ans<<"\n";

    return 0;
}
