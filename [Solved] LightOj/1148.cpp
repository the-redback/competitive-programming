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

ll a[100];


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1,tc;
    cin>>tc;
    ll i,j,k,l,m,n;
    while(tc--)
    {
        cin>>n;

        ll ans=0;
        ll sum=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);

        ll cnt=1;

        for(i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            {
                ll tmp=ceil(cnt/(double)(a[i-1]+1));
                tmp=tmp*(a[i-1]+1);
                sum+=tmp;
                cnt=1;
            }
            else
                cnt++;
        }
        ll tmp=ceil(cnt/(double)(a[n-1]+1));
        tmp=tmp*(a[n-1]+1);
        sum+=tmp;

        printf("Case %lld: %lld\n",t++,sum);

    }
    return 0;
}

