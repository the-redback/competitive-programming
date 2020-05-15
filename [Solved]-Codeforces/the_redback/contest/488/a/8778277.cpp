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

ll check(ll n)
{
    ll m;
    if(n<0)
        n=n*-1;
    while(n>1)
    {
        m=n%10;
        n=n/10;
        if(m==8)
            return 1;
    }
    return 0;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        ll sum=0;
        ll fl=1;
        for(i=n;1;i++)
        {
            if(check(i) && fl==0)
            {
                break;
            }
            fl=0;
            sum++;
        }
        cout<<sum<<"\n";
        return 0;

    }
    return 0;
}

