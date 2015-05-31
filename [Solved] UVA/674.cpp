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
long dp[5][7490];
int check(int i, int amount)
{
    long x=0,y=0;
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
    long n;
    memset(dp,-1,sizeof(dp));
    while(scanf("%ld",&n)==1)
    {
        n=check(0,n);
        printf("%ld\n",n);
    }
    return 0;
}
