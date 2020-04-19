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

vector<ll>v;

bool check(ll k)
{
    ll i,last=0;
    for(i=0;i<v.size();i++)
    {
        if(k<v[i]-last)
            return 0;
        if(k==v[i]-last)
            k--;
        last=v[i];
    }
    return 1;
}

main()
{
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);
        v.clear();
        for(i=0;i<n;i++)
        {
            read(k);
            v.pb(k);
        }
        ll  low=0,high=v[n-1];
        ll  ans=inf;
        while(low<=high)
        {
            ll  mid=(low+high)/2.0;
            if(check(mid))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        printf("Case %lld: %lld\n",t++,ans);

    }
    return 0;
}


