/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10000000
#define NN 200

queue<int>x,y;
int vis[NN+7][NN+7];
int dis[NN+7][NN+7];
char a[NN+7][NN+7];
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
int R,C;
void bfs1st(int r,int c)
{
    x=queue<int>();
    y=queue<int>();
    x.push(r);
    y.push(c);
    dis[r][c]=0;
    while(x.size())
    {
        int i=x.front();
        int j=y.front();
        x.pop(),y.pop();
        for(int ii=0; ii<4; ii++)
        {
            int xx=i+dx[ii];
            int yy=j+dy[ii];
            if(xx<0||yy<0||xx>=R||yy>=C)
                continue;
            if(a[xx][yy]!='F' && a[xx][yy]!='#' && dis[xx][yy]>dis[i][j]+1)
            {
                dis[xx][yy]=dis[i][j]+1;
                x.push(xx);
                y.push(yy);
            }
        }
    }
    return;
}

int bfs(int r,int c)
{
    x=queue<int>();
    y=queue<int>();
    x.push(r);
    y.push(c);
    vis[r][c]=0;
    int res=inf;
    while(x.size())
    {
        int i=x.front();
        int j=y.front();
        x.pop(),y.pop();
        for(int ii=0; ii<4; ii++)
        {
            int xx=i+dx[ii];
            int yy=j+dy[ii];
            if(xx<0||yy<0||xx>=R||yy>=C)
                return vis[i][j]+1;
            if(a[xx][yy]!='F' && a[xx][yy]!='#' && vis[xx][yy]==-1 && dis[xx][yy]>vis[i][j]+1)
            {
                vis[xx][yy]=vis[i][j]+1;
                x.push(xx);
                y.push(yy);
            }
        }
    }
    return res;
}


main()
{
    int tc,t=1;
    int i,j,k,l,m,n,u,v,w,res,r;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&R,&C);
        for(i=0; i<R; i++)
            scanf("%s",&a[i]);
        for(i=0; i<R; i++)
            for(j=0; j<C; j++)
                dis[i][j]=inf;
        for(i=0; i<R; i++)
            for(j=0; j<C; j++)
            {
                if(a[i][j]=='F')
                    bfs1st(i,j);
                if(a[i][j]=='J')
                    u=i,v=j;
            }
        mem(vis,-1);
        res=bfs(u,v);
        if(res==inf)
            printf("Case %d: IMPOSSIBLE\n",t++);
        else
            printf("Case %d: %d\n",t++,res);
    }
    return 0;
}













