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

ll N,M;
ll a[1010];

ll check(ll num)
{
    ll i,cnt=0,sum=0;
    for(i=0;i<=N;i++)
    {
        if(a[i]>num)
            return 0;
        if(sum+a[i]<=num)
        {
            sum+=a[i];
        }
        else
        {
            sum=a[i];
            cnt++;
        }
    }
    cnt++;
    if(cnt<=M+1)
        return 1;
    return 0;
}


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(N);
        read(M);
        ll sum=0;

        for(i=0;i<=N;i++)
        {
            read(a[i]);
            sum+=a[i];
        }
        ll low=0,high=sum;
        ll ans=inf;
        while(low<=high)
        {
            ll mid=(low+high)/2.0;
            if(check(mid))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        printf("Case %lld: %lld\n",t++,ans);
        sum=0;
        for(i=0;i<=N;i++)
        {
            if(sum+a[i]<=ans && N-i+1>M )
            {
                sum+=a[i];
            }
            else
            {
                printf("%lld\n",sum);
                sum=a[i];
                M--;
            }
        }
        printf("%lld\n",sum);




    }
    return 0;
}

