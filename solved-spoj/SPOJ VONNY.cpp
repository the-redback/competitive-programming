#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int a[10][10];
bool visit[10][10];
int srch[7][7];
vector<int>v;
int N,M,flag,cnt;
int xx[]={0,1};
int yy[]={1,0};

void call(int r,int c,int n)
{
    if(n==56)
    {
        cnt++;
        return;
    }
    if(c>=8)
    {
        call(r+1,0,n);
        return;
    }
    if(visit[r][c])
    {
        call(r,c+1,n);
        return;
    }
    if(r>=7 &&c>=8)
        return;
    for(int i=0;i<2;i++)
    {
        int rr=r+xx[i];
        int cc=c+yy[i];
        if(rr>=0 && cc>=0 && rr<7 && cc<8 && visit[r][c]==0 && visit[rr][cc]==0)
        {
            int x=a[r][c];
            int y=a[rr][cc];
            if(srch[x][y]==0||srch[y][x]==0)
            {
                srch[x][y]=1;
                srch[y][x]=1;
                visit[rr][cc]=1;
                visit[r][c]=1;
                call(r,cc+1,n+2);
                visit[rr][cc]=0;
                visit[r][c]=0;
                srch[x][y]=0;
                srch[y][x]=0;
            }
        }
    }
    return;
}

main()
{
    int n,m,i,j,t=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        for(i=0;i<7;i++)
            for(j=0;j<8;j++)
                scanf("%d",&a[i][j]);
        memset(visit,0,sizeof(visit));
        memset(srch,0,sizeof(srch));
        cnt=0;
        call(0,0,0);
        printf("%d\n",cnt);
    }
    return 0;
}
