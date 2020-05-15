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
#define NN        300100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

ll a[NN];
ll b[NN];

bool comp(ll aa,ll bb)
{
    return aa>bb;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;

    ll i,j,k,l,m,n,ii,jj;

    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<a[0]<<"\n";
        return 0;
    }

    sort(a,a+n,comp);
    b[0]=0;
    ll ret=0,res=0,temp=0;
    for(i=1;i<n;i++)
    {
        a[i]+=a[i-1];
        ret+=a[i];
    }
    ret+=a[n-1];
    cout<<ret<<"\n";

    return 0;
}
