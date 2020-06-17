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

ll a[2000];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    ll ans=0;
    while(cin>>n>>m>>k)
    {
        for(i=0; i<=m; i++)
        {
            cin>>a[i];
        }
        ans=0;

        ll cnt=0;
        for(j=0; j<m; j++)
        {
            cnt=0;
            for(i=0; i<=21; i++)
            {
                if((1<<i & a[j]) && (1<<i & a[m]) )
                    continue;
                else if((1<<i & a[j]) || (1<<i & a[m]))
                    cnt++;
            }
            if(cnt<=k)
                ans++;
        }
        cout<<ans<<"\n";

    }
    return 0;
}
