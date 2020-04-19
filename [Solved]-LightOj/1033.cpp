#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
int dp[111][111];
char a[111];
int l;
int call(int i,int j)
{
    if(i==j || i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int x=0,y=0;
    if(a[i]==a[j])
        return dp[i][j]=call(i+1,j-1);
    else
    {
        x=call(i+1,j)+1;
        y=call(i,j-1)+1;
        return dp[i][j]=min(x,y);
    }
}


main()
{
    int tc,i;
    scanf("%d",&tc);
    getchar();
    for( i=1;i<=tc;i++)
    {
        gets(a);
        memset(dp,-1,sizeof(dp));
        int sum=call(0,strlen(a)-1);
        printf("Case %d: %d\n",i,sum);
    }
}
