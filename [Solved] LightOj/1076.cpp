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

ll a[1111];
ll N,M;

bool check(ll val)
{
    ll i,cnt=0,sum=0;

    for(i=0;i<N;i++)
    {
        if(a[i]>val)
            return 0;
        if(sum+a[i]==val)
        {
            cnt++;
            sum=0;
        }
        else if(sum+a[i]<val)
        {
            sum+=a[i];
        }
        else
        {
            sum=a[i];
            cnt++;
        }
    }
    if(sum!=0)
        cnt++;
    if(cnt<=M)
        return 1;
    return 0;
}


main()
{
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);
        read(m);
        N=n;
        M=m;

        ll ans=inf;
        ll sum=0;
        for(i=0;i<n;i++)
        {
            read(a[i]);
            sum+=a[i];
        }
        ll low=0,high=sum;

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

    }
    return 0;
}

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

ll a[1111];
ll N,M;

bool check(ll val)
{
    ll i,cnt=0,sum=0;

    for(i=0;i<N;i++)
    {
        if(a[i]>val)
            return 0;
        if(sum+a[i]==val)
        {
            cnt++;
            sum=0;
        }
        else if(sum+a[i]<val)
        {
            sum+=a[i];
        }
        else
        {
            sum=a[i];
            cnt++;
        }
    }
    if(sum!=0)
        cnt++;
    if(cnt<=M)
        return 1;
    return 0;
}


main()
{
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);
        read(m);
        N=n;
        M=m;

        ll ans=inf;
        ll sum=0;
        for(i=0;i<n;i++)
        {
            read(a[i]);
            sum+=a[i];
        }
        ll low=0,high=sum;

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

    }
    return 0;
}

