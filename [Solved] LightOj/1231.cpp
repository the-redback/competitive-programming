
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
/*
=======[ Theme ]=======
n types of coins of value A1, A2 ... An.
C1, C2, ... Cn denote the number of coins of value A1, A2 ... An.
find the number of ways you can make K using the coins.

*/
int n,k;
int tc[51];
int coin[51];
long long dp[51][1001];
long long check(int i, int amount)
{
    int j;
    long long y=0;
    if(i>=n)
    {
        if(amount==k)
            return 1;
        else
            return 0;
    }
    long long &t=dp[i][amount];
    if(t!=-1)
        return t;
    y=check(i+1,amount)%100000007;
    for(j=1;j<=tc[i];j++)
    {
        if(amount+coin[i]*j<=k)
        y+=check(i+1,amount+coin[i]*j)%100000007;
    }
    return t=y%100000007;
}

main()
{
    int i,j,t;
    long long m;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&n,&k);
        for(j=0;j<n;j++)
            scanf("%d",&coin[j]);
        for(j=0;j<n;j++)
            scanf("%d",&tc[j]);
        m=(check(0,0))%100000007;
        printf("Case %d: %lld\n",i,m);
    }
    return 0;
}
