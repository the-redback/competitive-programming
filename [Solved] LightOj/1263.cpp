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
#define NN 1000
vector<int>e[NN+7];

int dir[NN+7];
int view[NN+7];
int dis,node;

void dfs(int u)
{
    view[u]=1;
    dis+=dir[u];
    node++;
    int i;
    for(i=0;i<e[u].size();i++)
    {
        if(view[e[u][i]]==-1)
        {
            dfs(e[u][i]);
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
        scanf("%d%d",&n,&r);
        w=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&dir[i]);
            w+=dir[i];
        }
        for(i=0;i<r;i++)
        {
            scanf("%d%d",&u,&v);
            e[u-1].pb(v-1);
            e[v-1].pb(u-1);
        }
        mem(view,-1);
        int flag=1;
        if(w%n)
            flag=0;
        k=w/n;
        for(i=0 ; i<n && flag ; i++)
        {
            dis=0;
            node=0;
            if(view[i]==-1)
            {
                dfs(i);
                if(dis%node || k*node!=dis)
                    flag=0;
            }
        }
        if(flag)
            printf("Case %d: Yes\n",t++);
        else
            printf("Case %d: No\n",t++);
        for(i=0;i<=n;i++)
            e[i].clear();
    }
    return 0;
}





