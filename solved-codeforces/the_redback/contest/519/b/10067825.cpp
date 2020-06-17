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

#define read(a)   scanf("%lld",&a)

ll a[NN];
ll b[NN];
ll c[NN];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(i=0;i<n-1;i++)
            cin>>b[i];
        sort(b,b+n-1);
        for(i=0;i<n-2;i++)
            cin>>c[i];
        sort(c,c+n-2);

        ll x=-1,y=-1;

        for(i=0;i<n-1;i++)
        {
            if(a[i]!=b[i])
            {
                x=a[i];
                break;
            }
        }
        if(x==-1)
            x=a[n-1];
        for(i=0;i<n-2;i++)
        {
            if(c[i]!=b[i])
            {
                y=b[i];
                break;
            }
        }
        if(y==-1)
            y=b[n-2];
        cout<<x<<"\n";
        cout<<y<<"\n";

    }
    return 0;
}

