#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
char a[30][30];
int N,M;
char land,water;
int dfs(int i,int j)
{
    if(i<0||i>=N||j<0||j>=M)
        return 0;
    if(a[i][j]==water)
        return 0;
    a[i][j]=water;
    int sum=1;
    for(int k=0;k<4;k++)
    {
        if(j+dy[k]==-1)
            sum+=dfs(i+dx[k],M-1);
        else if(j+dy[k]==M)
            sum+=dfs(i+dx[k],0);
        else
            sum+=dfs(i+dx[k],j+dy[k]);
    }
    return sum;
}

main()
{
    int n,m,i,j,k,l;
    while(scanf("%d%d",&n,&m)==2)
    {
        getchar();
        for(i=0;i<n;i++)
            gets(a[i]);
        int x,y;
        scanf("%d%d",&x,&y);
        M=m,N=n;
        land=a[x][y];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(a[i][j]!=land)
                {
                    water=a[i][j];
                    break;
                }
            if(j!=m)
                break;
        }
        dfs(x,y);
        int sum=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(a[i][j]==land)
                {
                    k=dfs(i,j);
                    sum=max(sum,k);
                }
        }
        printf("%d\n",sum);
    }
}
