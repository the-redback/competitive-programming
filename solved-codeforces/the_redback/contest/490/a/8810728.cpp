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

#define read(a)   scanf("%lld",&a)

vector<ll>math,prog,phy;

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
        {
            cin>>k;
            if(k==1)
                prog.pb(i);
            else if(k==2)
                math.pb(i);
            else
                phy.pb(i);
        }
        ll ans=min((ll)prog.size(),min((ll)math.size(),(ll)phy.size()));
        cout<<ans<<"\n";

        for(i=0;i<ans;i++)
        {
            cout<<prog[i]<<" "<<math[i]<<" "<<phy[i]<<"\n";
        }
    }
    return 0;
}

