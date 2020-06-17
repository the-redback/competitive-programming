#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int coin[22];
long long dp[22][30001];
long long check(int i, int amount)
{
    long long x=0,y=0;
    if(i>=21)
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    if(amount-coin[i]>=0)
        x=check(i,amount-coin[i]);
    y=check(i+1,amount);
    return dp[i][amount]=x+y;
}

main()
{
    int n;
    long long m;
    for(n=1;n<=21;n++)
        coin[n-1]=pow(n,3);
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n)==1)
    {
        m=check(0,n);
        printf("%lld\n",m);
    }
    return 0;
}
