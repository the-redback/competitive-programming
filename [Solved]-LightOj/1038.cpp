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
#define NN        100001

#define read(a)   scanf("%lld",&a)



bool dc[NN+7];
double dp[NN+7];
vector<ll>Div[NN];

void prework(ll N)
{
    ll i,j,k;
    for(i=2;i<=N;i++)
    {
        for(j=i;j<=N;j+=i)
            Div[j].pb(i);
    }
    return;
}

double rec(ll num)
{
    if(num<=1)
        return 0;

    double &tc=dp[num];
    if(dc[num])
        return tc;

    ll m=(ll)Div[num].size();
    m++;

    double res=1;
    for(ll i=0;i<Div[num].size();i++)
    {
        res+=rec(num/Div[num][i])+1;
    }
    tc=res/(m-1);
    dc[num]=1;
    return tc;
}



main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif
    prework(NN);

    ll t=1,tc;
    cin>>tc;
    ll i,j,k,l,m,n;
    while(tc--)
    {
        cin>>n;
        memset(dc,0,sizeof(bool)*(n+2));
        double res=rec(n);
        printf("Case %lld: %.8lf\n",t++,res);
    }
    return 0;
}
