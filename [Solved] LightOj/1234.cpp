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
#define NN        1000007

#define read(a) scanf("%lld",&a)

double a[NN];

void pre(void)
{
    double ans=0;
    ll i=0,j=1;
    a[0]=0;
    for(i=1;i<=100000000;i++)
    {
        ans+=1/(double)i;
        if(i%100==0)
        {
            a[j]=ans;
            j++;
        }
    }
    return;

}

main()
{
    pre();
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);
        double ans,ret;
        ll low=n/100;
        ans=a[low];
        for(i=(low*100)+1;i<=n;i++)
            ans+=1/(double)i;
        printf("Case %lld: %.10lf\n",t++,ans);

    }
    return 0;
}
