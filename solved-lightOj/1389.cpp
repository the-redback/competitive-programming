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

char a[111];

main()
{
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);

        ll ans=0;
        scanf("%s",&a);

        for(i=0,j=0,k=0;i<n;i++)
        {
            if(a[i]=='.')
                k++,j++;
            if(a[i]=='#' && k!=0)
                j++;
            if(j%3==0 && k!=0)
            {
                ans++;
                k=0;
            }

        }
        if(k!=0)
            ans++;
        printf("Case %lld: %lld\n",t++,ans);

    }
    return 0;
}

