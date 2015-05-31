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

#define inf 10000000
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 30
const int dx[]={0,-1,0,1,0,0};
const int dy[]={-1,0,1,0,0,0};
const int dz[]={0,0,0,0,1,-1};
char a[NN+7][NN+7][NN+7];
int dist[NN+7][NN+7][NN+7];
queue<int>X,Y,Z;
int R,C,L;
int bfs(int si,int sj,int sz)
{
    X=Y=Z=queue<int>();
    X.push(si),Y.push(sj),Z.push(sz);
    mem(dist,-1);
    dist[sz][si][sj]=0;
    while(!X.empty())
    {
        int x=X.front();
        int y=Y.front();
        int z=Z.front();
        X.pop(),Y.pop(),Z.pop();
        for(int r=0;r<6;r++)
        {
            int i=x+dx[r];
            int j=y+dy[r];
            int k=z+dz[r];
            if(i<0||j<0||k<0||i>=R||j>=C||k>=L)
                continue;
            if(a[k][i][j]!='#' && dist[k][i][j]==-1)
            {
                X.push(i),Y.push(j),Z.push(k);
                dist[k][i][j]=dist[z][x][y]+1;
                if(a[k][i][j]=='E')
                    return dist[k][i][j];
            }
        }
    }
    return -1;
}

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,si,sj,sk;
    int tc,t=1;
    //cin>>tc;
    while(~scanf("%d%d%d",&L,&R,&C))
    {
        if(L==0&&R==0&&C==0)
            return 0;
        k=0;
        for(k=0;k<L;k++)
            for(i=0;i<R;i++)
            {
                scanf("%s",&a[k][i]);
                for(j=0;j<C;j++)
                    if(a[k][i][j]=='S')
                        si=i,sj=j,sk=k;
            }
        n=bfs(si,sj,sk);
        if(n==-1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n",n);
    }
    return 0;
}




