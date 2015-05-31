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
#define NN        111

#define read(a)   scanf("%lld",&a)

bool dc[NN];
double dp[NN];
ll N;
ll a[NN];

double rec(ll pos)
{
    if(pos>=N)
        return 0;
    double &tc=dp[pos];
    if(dc[pos])
        return tc;
    ll hor=min(N-pos-1,6LL);
    double res=0;
    for(ll i=1;i<=hor;i++)
    {
        res+=(rec(pos+i)+a[pos+i])/(double)hor;
    }
    dc[pos]=1;
    tc=res;
    return tc;
}


main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif // redback

    //ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);
        N=n;
        for(i=0;i<n;i++)
            read(a[i]);
        mem(dc,0);
        double res=rec(0)+a[0];
        printf("Case %lld: %.10lf\n",t++,res);

    }
    return 0;
}

