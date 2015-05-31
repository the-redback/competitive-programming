#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int coin[]={1,5,10,25,50};
long long dp[5][30001];
long long check(int i, int amount)
{
    long long x=0,y=0;
    if(i>=5)
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
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n)==1)
    {
        m=check(0,n);
        if(m==1)
            printf("There is only %lld way to produce %d cents change.\n",m,n);
        else
            printf("There are %lld ways to produce %d cents change.\n",m,n);
    }
    return 0;
}
