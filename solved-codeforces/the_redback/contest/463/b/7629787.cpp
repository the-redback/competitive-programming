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
#define NN        30100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

ll a[100010];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        ll flag=0;
        ll ret=0;
        a[0]=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        a[0]=a[1];
        ret=0;
        ll ans=a[0];
        for(i=1;i<=n;i++)
        {
            if((ret+a[i-1]-a[i])>=0)
            {
                ret+=a[i-1]-a[i];
            }
            else
            {
                ans+=0-(ret+a[i-1]-a[i]);
                ret=0;
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}
