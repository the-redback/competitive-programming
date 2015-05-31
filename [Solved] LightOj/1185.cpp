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
#define NN 100

vector<int>e[NN+7];
int vis[NN+7][3];

int dfs(int u,int fl)
{
    if(vis[u][fl]!=-1)
        return 0;
    int i,res=0;
    if(fl==1)
        res=1;
    vis[u][fl]=1;
    for(i=0;i<e[u].size();i++)
    {
        res+=dfs(e[u][i],(fl+1)%2);
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
        scanf("%d%d",&n,&r);
        while(r--)
        {
            scanf("%d%d",&u,&v);
            e[u].pb(v);
            e[v].pb(u);
        }
        mem(vis,-1);
        res=dfs(1,-1);
        printf("Case %d: %d\n",t++,res);
        for(i=0;i<=n;i++)
            e[i].clear();
    }
    return 0;
}













