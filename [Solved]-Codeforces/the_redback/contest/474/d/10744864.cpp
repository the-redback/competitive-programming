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
#define NN        100010

ll a[NN];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,r,n;
    while(cin>>n>>k)
    {
        a[0]=0;

        for(i=1;i<k;i++)
        {
            a[i]=1;
        }
        a[k]=2;
        for(i=k+1;i<=100000;i++)
        {
            a[i]=(a[i-1]%mod+a[i-k]%mod)%mod;
        }
        for(i=1;i<=100000;i++)
        {
            a[i]=(a[i]+a[i-1])%mod;
        }
        while(n--)
        {
            cin>>k>>l;
            ll ans=(a[l]-a[k-1])%mod;
            ans=(ans+mod)%mod;
            cout<<ans<<"\n";
        }
        return 0;


    }
    return 0;
}