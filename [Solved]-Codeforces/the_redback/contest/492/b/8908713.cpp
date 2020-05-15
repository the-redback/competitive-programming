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

ll a[10000];

main()
{
    //freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(cin>>n>>m)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        double ret=0;

        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                double dist=a[i];
                ret=dist;
            }
            if(i==n-1)
            {
                double dist=m-a[i];
                if(ret-dist<=eps)
                    ret=dist;
            }
            if(i-1>=0)
            {
                double dist=(a[i]-a[i-1])/2.0;
                if(ret-dist<=eps)
                    ret=dist;
            }
        }
        printf("%.10lf\n",ret);

    }
    return 0;
}

