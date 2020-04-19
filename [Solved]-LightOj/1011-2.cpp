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
int dp[70000];
int a[20][20];
int n;

int go(int x,int mask)
{
    if(x>=n)
    {
        return 0;
    }
    int &t=dp[mask];
    if(t!=-1)
    {
        return t;
    }
    int k=0;
    for(int i=0;i<n;i++)
    {
        if((mask&(1<<i))==0)
        {
            k=max(k,go(x+1,mask | 1<<i)+a[x][i]);
        }

    }
    dp[mask]=k;

    return dp[mask];
}


main()
{
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        memset(dp,-1,sizeof(dp));
        int sum=go(0,0);
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
