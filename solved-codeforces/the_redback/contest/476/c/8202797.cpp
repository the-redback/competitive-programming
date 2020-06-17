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
#define NN        30100



main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,r,m,n;
    ll a,b;
    while(cin>>a>>b)
    {
        ll sum=0;
        ll ans=0;
        for(i=1;i<b;i++)
            sum=(sum+i)%mod;

        for(i=1;i<=a;i++)
        {
            ll temp=(1*i*b)+1;
            temp%=mod;
            ans=(ans+(temp*sum)%mod)%mod;
        }

        cout<<ans<<"\n";
            return 0;
    }
    return 0;
}
