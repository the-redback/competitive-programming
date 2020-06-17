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
#define NN        300010

#define read(a)   scanf("%lld",&a)

ll a[NN];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    double sum=0,ss=0,s=0;
    while(~read(n))
    {
        double w;
        scanf("%lf",&w);

        for(i=0;i<2*n;i++)
            read(a[i]);
        sort(a,a+(2*n));

        double mn=a[0];
        double mn2=a[n];
        sum=0;

        if(mn2/2.0 > mn)
            sum+=(mn*n)+(mn*2*n);
        else
            sum+=mn2*n+(mn2/2.0)*n;

        sum=min(sum,w);

        printf("%.8lf\n",sum);

    }
    return 0;
}
