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
#define NN        5000

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

ll slash[NN];
ll BackSlash[NN];
ll a[2010][2010];


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    ll i,j,k,l,m,n;
    cin>>n;
    mem(slash,0);
    mem(BackSlash,0);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            slash[i+j]+=a[i][j];
            BackSlash[i-j+2010]+=a[i][j];
        }
    }
    ll mx1=-inf,mx2=-inf;
    ll x1,x2,y1,y2;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if((i+j)%2==0)
            {
                ll temp=slash[i+j]+BackSlash[i-j+2010]-a[i][j];
                if(temp>mx1)
                {
                    mx1=temp;
                    x1=i,y1=j;
                }
            }
            if((i+j)%2==1)
            {
                ll temp=slash[i+j]+BackSlash[i-j+2010]-a[i][j];
                if(temp>mx2)
                {
                    mx2=temp;
                    x2=i,y2=j;
                }
            }
        }
    }
    cout<<mx1+mx2<<"\n";
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";

    return 0;
}
