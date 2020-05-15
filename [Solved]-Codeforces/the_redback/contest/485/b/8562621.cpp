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



main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        ll xh=-inf,yh=-inf,xl=inf,yl=inf;
        for(i=0;i<n;i++)
        {
            cin>>k>>l;
            xh=max(xh,k);
            xl=min(xl,k);
            yh=max(yh,l);
            yl=min(yl,l);
        }
        ll area=max(abs(xh-xl),abs(yh-yl));
        area=area*area;
        cout<<area;
        return 0;


    }
    return 0;
}
