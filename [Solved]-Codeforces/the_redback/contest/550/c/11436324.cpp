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

ll dp[111][10][2];
char a[111];

 ll N;



bool rec(ll pos,ll rem,ll fl)
{

    ll &tc=dp[pos][rem][fl];

    if(pos==N)
    {
        if(rem==0 && fl==1)
            return tc=1;
        return 0;
    }

    if(tc!=-1)
        return tc;

    ll temp=0;
    bool ret=0;

    ret=rec(pos+1,rem,fl);

    temp=rem;
    temp=temp*10+a[pos]-48;
    temp=temp%8;

    ret|=rec(pos+1,temp,1);

    return tc=ret;
}

void prnt(ll pos,ll rem,ll fl)
{
    if(pos==N)
    {
        puts("");
        return;
    }

    ll temp=0;
    bool ret=0;

    temp=rem;
    temp=temp*10+a[pos]-48;
    temp=temp%8;

    if(dp[pos+1][rem][fl]==1)
    {
        prnt(pos+1,rem,fl);
    }
    else if(dp[pos+1][temp][1]==1)
    {
        printf("%c",a[pos]);
        prnt(pos+1,temp,1);
    }
    return;
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~scanf("%s",&a))
    {
        l=strlen(a);
        N=l;

        for(i=0;i<N;i++)
        {
            if(a[i]=='0')
            {
                printf("YES\n0\n");
                return 0;
            }
        }

        mem(dp,-1);

        ll ret=rec(0,0,0);

        if(ret==1)
        {
            printf("YES\n");
            prnt(0,0,0);
        }
        else
            printf("NO\n");

    }
    return 0;
}
