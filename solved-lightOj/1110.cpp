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

#define ft         first
#define sd         second
#define mp         make_pair
#define pb(x)      push_back(x)
#define all(x)     x.begin(),x.end()
#define allr(x)    x.rbegin(),x.rend()
#define mem(a,b)   memset(a,b,sizeof(a))
#define repv(i,a)  for(i=0;i<(ll)a.size();i++)
#define revv(i,a)  for(i=(ll)a.size()-1;i>=0;i--)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define sf(a)      scanf("%lld",&a)
#define sf2(a,b)   scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf        1e9
#define eps        1e-9
#define mod        1000000007
#define NN         101

#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

ll dp[NN][NN];
string s[NN][NN];

char a[NN],b[NN];

ll lcs(ll i,ll j)
{
    if(i<=0 || j<=0)
    {
        s[i][j]="";
        return 0;
    }

    ll &tc=dp[i][j];

    if(tc!=-1)
        return tc;

    if(a[i]==b[j])
    {
        tc=lcs(i-1,j-1)+1;

        s[i][j]=s[i-1][j-1]+a[i];
    }
    else
    {
        tc=lcs(i-1,j);
        tc=max(tc,lcs(i,j-1));

        if(lcs(i-1,j)>lcs(i,j-1))
            s[i][j]=s[i-1][j];
        else if(lcs(i-1,j)<lcs(i,j-1))
            s[i][j]=s[i][j-1];
        else if(lcs(i-1,j)==lcs(i,j-1))
            s[i][j]=min(s[i-1][j],s[i][j-1]);
    }
    return tc;
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    sf(tc);
    ll l,m,n;
    while(tc--) {
        ll i,j,k;

        scanf("%s",a+1);
        scanf("%s",b+1);

        m=strlen(a+1);
        n=strlen(b+1);

        mem(dp,-1);
        k=lcs(m,n);

        if(k==0)
            printf("Case %lld: :(\n",t++);
        else
            printf("Case %lld: %s\n",t++,s[m][n].c_str());


    }
    return 0;
}
