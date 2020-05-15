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
#define NN        5010

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;
ll a[NN];
ll sum[NN];
ll dp[NN][NN];
ll n,m;

ll rec(ll pos,ll k)
{
    if(k<=0 || pos>=n)
        return 0;
    ll &tc=dp[pos][k];
    if(tc!=-1)
        return tc;
    tc=0;
    tc=rec(pos+1,k);
    if(pos+m-1 <=n)
        tc=max(tc,rec(pos+m,k-1)+sum[pos]);
    return tc;
}



main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l;
    ll ans=0;
    while(cin>>n>>m>>k)
    {
        a[0]=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]+=a[i-1];
        }
        for(i=1;i<=n;i++)
        {
            ll r=i+m-1;
            r=min(r,n);
            sum[i]=a[r]-a[i-1];
        }

        if(m==1)
        {
            ans=0;
            sort(sum,sum+n+1);
            j=0;
            for(i=n;i>=1 && j<k ;i--,j++)
                ans+=sum[i];
        }
        else
        {
            mem(dp,-1);
            ans=rec(1,k);
        }

        cout<<ans<<"\n";
    }
    return 0;
}
