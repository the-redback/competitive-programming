/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : maruf.2hin
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 *
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
int main()
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
