#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
int m,k;
int a[25];
int dp[25][1500];
int ans[25][1500];
bool dc[25][1500];
int call(int i,int n)
{
    if(i==m)
        return n;
    if(dc[i][n])
        return dp[i][n];
    int x=0,y=0;
    if(n+a[i]<=k)
        x=call(i+1,n+a[i]);
    y=call(i+1,n);
    if(x>=y)
    {
        ans[i][n]=1;
        dp[i][n]=x;
    }
    else
    {
        ans[i][n]=2;
        dp[i][n]=y;
    }
    dc[i][n]=1;
    return dp[i][n];
}
main()
{
    int i,n,l,j;
    while(scanf("%d %d",&k,&m)==2)
    {
        memset(ans,-1,sizeof(ans));
        memset(dc,0,sizeof(dc));
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        sort(a,a+m);
        j=call(0,0);
        i=0;
        n=0;
        while(ans[i][n]!=-1)
        {
            if(ans[i][n]==1)
            {
                printf("%d ",a[i]);
                n=n+a[i];
            }
            i++;
        }
        printf("sum:%d\n",j);
    }
    return 0;
}
