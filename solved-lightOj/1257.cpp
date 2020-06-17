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
#define NN 30000
vector<int>e[NN+7],cost[NN+7];

int dir[NN+7];
int view[NN+7];
int dis,node;

void dfs1st(int u)
{
    if(dis<view[u])
    {
        node=u;
        dis=view[u];
    }
    int i;
    for(i=0;i<e[u].size();i++)
    {
        if(view[e[u][i]]==-1)
        {
            view[e[u][i]]=view[u]+cost[u][i];
            dfs1st(e[u][i]);
        }
    }
    return;
}

void dfs2nd(int u)
{
    if(dis<view[u])
    {
        node=u;
        dis=view[u];
    }
    dir[u]=max(dir[u],view[u]);
    int i,res=0;
    for(i=0;i<e[u].size();i++)
    {
        if(view[e[u][i]]==-1)
        {
            view[e[u][i]]=view[u]+cost[u][i];
            dfs2nd(e[u][i]);
        }
    }
    return;
}

main()
{
    int t=1,tc;
    int q,r,j,k,l,n,i;
    int u,v,w;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            e[u].pb(v);
            e[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        mem(view,-1);
        node=0,dis=0,view[0]=0;
        dfs1st(0);
        mem(view,-1),mem(dir,-1);
        dis=0,view[node]=0;
        dfs2nd(node);
        mem(view,-1);
        view[node]=0;
        dfs2nd(node);
        printf("Case %d:\n",t++);
        for(i=0;i<n;i++)
        {
            printf("%d\n",dir[i]);
            e[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}





