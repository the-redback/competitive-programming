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
#define NN        10001

#define read(a)   scanf("%lld",&a)

struct D
{
    ll xx=-1,yy=-1,x=0;
    ll res=0;

    D(ll XX,ll Y,ll X)
    {
        xx=XX;
        yy=Y;
        res=max(xx,yy);
        x=X;
    }
    D()
    {

    }
}a[NN];

ll power(ll n,ll m)
{
    ll sum=1;

    for(ll i=1;i<=m;i++)
        sum*=n;
    return sum;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        ll lim=power(2,n+1)-1;

        ll ret=0;

        for(i=2;i<=lim;i++)
        {
            cin>>a[i].x;
        }

        for(i=lim;i>=2;i-=2)
        {
            ll k=i/2;
            a[k]=D(a[i].x+a[i].res,a[i-1].x+a[i-1].res,a[k].x);

            ret+=a[k].res-a[k].xx;
            ret+=a[k].res-a[k].yy;
        }

        cout<<ret<<"\n";

    }
    return 0;
}
