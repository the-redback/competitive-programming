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
#define NN        100010

#define read(a)   scanf("%lld",&a)

/*

sum=a[0]+a[1]+....+a[n];

answer=(sum*(n^(k-1))*k)%mod;

*/

//(m^n)%p;
ll check(ll m,ll n,ll p)
{
    int sum;
    if(n==0)
        return 1;
    if(n%2==0)
    {
        sum=check(m,n/2,p);
        return ((sum%p)*(sum%p))%p;
    }
    else
    {
        sum=check(m,n-1,p);
        return ((m%p)*(sum%p))%p;
    }
}



int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);
        read(k);
        read(m);

        ll sum=0,ans=0;

        for(i=0;i<n;i++)
        {
            read(l);
            sum+=l;
        }

        ans=((sum%m * check(n,k-1,m))%m * k%m)%m;

        printf("Case %lld: %lld\n",t++,ans);



    }
    return 0;
}
