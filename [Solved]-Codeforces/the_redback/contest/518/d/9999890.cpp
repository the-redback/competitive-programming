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
#define NN        2002

#define read(a)   scanf("%lld",&a)

double dp[NN][NN];
bool dc[NN][NN];

double p;

double rec(ll n,ll t)
{
    if(t==0||n==0)
        return 0.0;
    double &tc=dp[n][t];
    if(dc[n][t])
        return tc;

    double e1,e2;

    e1=(rec(n-1,t-1)+1.0)*p;
    e2=rec(n,t-1)*(1.0-p);

    dc[n][t]=1;
    return tc=e1+e2;

}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        //freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    double dd;
    while(cin>>n>>p>>m)
    {
        mem(dc,0);
        double res=rec(n,m);

        printf("%.8lf\n",res);


    }
    return 0;
}

