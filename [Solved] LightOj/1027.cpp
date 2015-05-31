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


main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);
        ll zro=0;
        ll sum=0;
        for(i=0;i<n;i++)
        {
            read(k);
            if(k<0)
            {
                zro++;
                k=k*-1L;
            }
            sum+=k;
        }
        if(zro==n)
        {
            printf("Case %lld: inf\n",t++);
            continue;
        }
        ll num=sum;
        ll den=n-zro;
        ll gcd=__gcd(num,den);

        num/=gcd;
        den/=gcd;
        printf("Case %lld: %lld/%lld\n",t++,num,den);


    }
    return 0;
}

