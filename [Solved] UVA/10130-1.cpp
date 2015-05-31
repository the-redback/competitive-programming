#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int weight[1001],n,cap,cost[1001];
int dp[1001][101];
int check(int i,int w)
{
    int x,y;
    if(i==n)
        return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];

    if(w+weight[i]<=cap)
        x=cost[i]+check(i+1,w+weight[i]);
    else
        x=0;

    y=check(i+1,w);
    dp[i][w]=max(x,y);
    return dp[i][w];
}


main()
{
    int i,k;
    int sum,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d",&cost[i],&weight[i]);
        scanf("%d",&k);

        sum=0;
        for(i=0;i<k;i++)
        {
            memset(dp,-1,sizeof(dp));
            scanf("%d",&cap);
            sum+=check(0,0);
        }
        printf("%d\n",sum);
    }
    return 0;
}
