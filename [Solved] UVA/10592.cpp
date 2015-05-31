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
int dx[]= {-1,0,0,1,-1,-1,1,1};
int dy[]= {0,-1,1,0,-1,1,-1,1};
char a[100][100];
int N,b,p,total,flag=0;
int call(int i,int j,char ch)
{
    if(i<0||j<0||i>=N||j>=N)
        return 0;
    if(ch=='B' && a[i][j]=='P' &&flag==0)
        return 1;
    if(ch=='P' && a[i][j]=='B' &&flag==0)
        return 1;
    if(a[i][j]!=ch)
        return 0;
    a[i][j]='*';
    int sum=0;
    for(int k=0; k<4; k++)
    {
        sum=sum|call(i+dx[k],j+dy[k],ch);
    }
    return sum;
}

void dfs(int i,int j)
{
    if(i<0||j<0||i>=N||j>=N)
        return;
    if(a[i][j]=='.')
        return;
    if(a[i][j]=='P')
    {
        flag=0;
        int k=call(i,j,a[i][j]);
        p++;
        if(k!=0)
            total+=2;
    }
    else if(a[i][j]=='B')
    {
        flag=0;
        int k=call(i,j,a[i][j]);
        b++;
        if(k!=0)
            total+=2;
    }
    a[i][j]='.';
    for(int k=0; k<4; k++)
    {
        dfs(i+dx[k],j+dy[k]);
    }
    return;
}

main()
{
    int n,m,i,j,k,tc,t=1;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            return 0;
        getchar();
        for(i=0; i<n; i++)
            gets(a[i]);
        N=i;
        total=0;
        int count=0;
        k=1;
        for( i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(a[i][j]=='*' ||a[i][j]=='B' ||a[i][j]=='P')
                {
                    b=0,p=0;
                    dfs(i,j);
                    printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy group(s)\n",k++,b,p);
                }
            }
        }
        printf("Total %d group(s) are in fighting position.\n\n",total);
    }
    return 0;
}
