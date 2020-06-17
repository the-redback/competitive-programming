///=======================================//
///    Author     : Maruf Tuhin           //
///    School     : CUET CSE 11           //
///    TopCoder   : the_redback           //
///    Codeforces : maruf.2hin            //
///    UVA        : Redback               //
///    http://www.fb.com/maruf.2hin       //
///=======================================//
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 22550
#define inf 99999

long long dp[30][160];
long long mid,ans,sum;
int N,K;
long long go(int pos,int v)
{
    if(pos==N)
    {
        if(v>=K)
            return 1;
        else
            return 0;
    }
    long long &t=dp[pos][v];
    if(t!=-1)
        return t;
    long long ret=0;
    for(int i=1;i<=6;i++)
        ret+=go(pos+1,v+i);
    t=ret;
    return t;
}

main()
{
    while(~scanf("%d %d",&N,&K))
    {
        if(N==0 && K==0)
            return 0;
        int n,l,i,j;
        memset(dp,-1,sizeof(dp));
        ans=go(0,0);
        sum=pow(6.0,N);
        mid=__gcd(ans,sum);
        ans/=mid;
        sum/=mid;
        if(ans==0)
            printf("0\n");
        else if(ans==sum)
            printf("1\n");
        else
            printf("%lld/%lld\n",ans,sum);
    }
    return 0;
}
