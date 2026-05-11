/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
using namespace std;

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define NN 15

struct D
{
    int x,y,step;
    D(int X,int Y,int S)
    {
        x=X,y=Y,step=S;
    }
    D()
    {

    }
};

bool viw[NN][NN];
int dis[NN][NN];
int total[NN][NN];
int N,M;
char a[NN][NN];
queue<D>q;

int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};

int bfs(int x,int y,int k)
{
    mem(viw,0);
    viw[x][y]=1;
    q=queue<D>();
    q.push(D(x,y,0));
    while(q.size())
    {
        D dd=q.front();
        q.pop();
        total[dd.x][dd.y]++;
        for(int i=0;i<8;i++)
        {
            int xx=dd.x+dx[i];
            int yy=dd.y+dy[i];
            if(xx<0 || yy<0||xx>=N||yy>=M)
                continue;
            if(viw[xx][yy])
                continue;
            viw[xx][yy]=1;

            dis[xx][yy]+=ceil((dd.step+1)/(double)k);
            q.push(D(xx,yy,dd.step+1));
        }
    }
}


main()
{
    //ios_base::sync_with_stdio(false);
    int t=1,tc;
    cin>>tc;
    int i,j,k,l,m,n,man;
    while(tc--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
        }
        N=n,M=m;
        mem(dis,0);
        mem(total,0);
        int cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(a[i][j]!='.')
                    cnt++,bfs(i,j,a[i][j]-'0');
        }
        int sum=inf;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(total[i][j]==cnt)
                    sum=min(sum,dis[i][j]);
        }
        if(sum==inf)
            sum=-1;
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
