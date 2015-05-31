#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
int dp[201][101];
int a[201][101];
int n;

int test(int i,int j)
{
    int x,y,b,c;
    b=a[i][j];
    if(dp[i][j]!=-1)
        return dp[i][j];

    else if(a[i][j]==-1)
        return 0;
    else if(j<0 || i>((2*n)-2))
        return 0;

    else
    {
        if(i<n-1)
        {
            x=test(i+1,j+1)+a[i][j];
            y=test(i+1,j)+a[i][j];
            if(x>y)
            dp[i][j]=x;
            else
            dp[i][j]=y;
        }
        else
        {
            x=test(i+1,j-1)+a[i][j];
            y=test(i+1,j)+a[i][j];
            if(x>y)
            dp[i][j]=x;
            else
            dp[i][j]=y;
        }
    }
    return dp[i][j];
}

main()
{
    int i,j,k,l,m,t,sum;
    scanf("%d",&t);
    for(l=1;l<=t;l++)
    {
        memset(a,-1,sizeof(a[0][0])*200*100);
        memset(dp,-1,sizeof(a[0][0])*200*100);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=n,k=1;i<(n*2)-1;i++,k++)
        {
            for(j=0;j<n-k;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        sum=test(0,0);
        printf("Case %d: %d\n",l,sum);

    }
    return 0;
}
