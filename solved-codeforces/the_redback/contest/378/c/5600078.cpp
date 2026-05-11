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

#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 100000007
int xx[]= {0,-1,0,1};
int yy[]= {-1,0,1,0};
char a[555][555];
int K,n,m;
int view[555][555];

void dfs(int i, int j)
{
    int x,y,k;
    view[i][j]=1;
    K--;
    for(k=0; k<4; k++)
    {
        x=i+xx[k];
        y=j+yy[k];
        if(x<0||y<0||x==n||y==m||!K||view[x][y]!=-1||a[x][y]!='.')
            continue;
        dfs(x,y);
    }
    return;
}
main()
{
    int tc,t=1;
    int i,j,k,l;

    while(~scanf("%d%d%d",&n,&m,&K))
    {

        for(i=0; i<n; i++)
        {
            scanf("%s",&a[i]);
        }
        int cnt=0;
        for(i=0; i<=n; i++)
            for(j=0; j<=m; j++)
                if(a[i][j]=='.')
                {
                    cnt++;
                    k=i;
                    l=j;
                }
        K=cnt-K;
        mem(view,-1);
        dfs(k,l);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(a[i][j]=='.' && view[i][j]==-1)
                    printf("X");
                else
                    printf("%c",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
