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
#define inf 1000000000
#define NN 500

char a[NN+7][NN+7];
int view[NN+7][NN+7];
int pr[1010];
int N,M;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int dfs(int i,int j,int fl)
{
    if(i<0||j<0||i>=N||j>=M)
        return 0;
    int ret=0;
    if(view[i][j]!=-1 || a[i][j]=='#')
        return 0;
    view[i][j]=fl;
    if(a[i][j]=='C')
        ret=1;
    a[i][j]='.';
    for(int k=0;k<4;k++)
        ret+=dfs(i+dx[k],j+dy[k],fl);
    return ret;
}

int main()
{
    int tc,t=1,ret=0;
    int i,j,k,l,r,cc;
    int n,m,x=0,y=0;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d%d",&n,&m,&r);
        N=n,M=m;
        for(i=0;i<n;i++)
            scanf("%s",&a[i]);
        mem(view,-1);
        i=1;
        printf("Case %d:\n",t++);
        while(r--)
        {
            scanf("%d%d",&k,&l);
            if(view[k-1][l-1]==-1)
            {
                cc=dfs(k-1,l-1,i);
                i++;
                pr[view[k-1][l-1]]=cc;
            }
            printf("%d\n",pr[view[k-1][l-1]]);
        }
    }
    return 0;
}
