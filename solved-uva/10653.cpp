/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : Redback
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

#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 1000
int a[NN+7][NN+7];
int dist[NN+7][NN+7];
queue<int>X;
queue<int>Y;
int dr[]={0,-1,0,1};
int dc[]={-1,0,1,0};
int R,C;
int bfs(int srcx,int srcy,int dstx,int dsty)
{
    X=queue<int>();
    Y=queue<int>();
    mem(dist,-1);
    X.push(srcx);
    Y.push(srcy);
    dist[srcx][srcy]=0;
    while(!X.empty())
    {
        int xx=X.front();
        int yy=Y.front();
        X.pop();
        Y.pop();
        for(int i=0; i<4; i++)
        {
            int x=xx+dr[i];
            int y=yy+dc[i];
            if(x<0 || y<0 ||x>=R || y>=C)
                continue;
            if(dist[x][y]==-1 && a[x][y]==0)
            {
                X.push(x);
                Y.push(y);
                dist[x][y]=dist[xx][yy]+1;
                if(x==dstx && y==dsty)
                    return dist[x][y];
            }
        }
    }
    return 0;
}

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    int i,j,k,l,n,r,c;
    int tc,t=1;
    //scanf("%d",&tc);
    while(~scanf("%d%d",&R,&C))
    {
        if(R==0 && C==0)
            return 0;
        mem(a,0);
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&r,&k);
            while(k--)
                scanf("%d",&c),a[r][c]=1;
        }
        int srcx,srcy,dstx,dsty;
        scanf("%d%d%d%d",&srcx,&srcy,&dstx,&dsty);
        int sum=bfs(srcx,srcy,dstx,dsty);
        printf("%d\n",sum);
    }
    return 0;
}





