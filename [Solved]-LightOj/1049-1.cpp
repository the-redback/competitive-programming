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
vector<int>cost[NN+7];
int view[NN+7];
int N;
int call(int u)
{
    view[u]=1;
    int i,res=0;
    for(i=0;i<2;i++)
    {
        if(view[e[u][i]]==0)
        {
            res=cost[u][i]+call(e[u][i]);
        }
    }
    return res;
}

int main()
{
    int tc,t=1,res=0;
    int i,j,k,l,cc;
    int r[3];
    int n,m,x=0,y=0;
    int u,v,w;
    scanf("%d",&tc);
    while(tc--)
    {
        mem(view,0);
        scanf("%d",&n);
        j=0;
        N=n;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            e[u].pb(v);
            e[v].pb(u);
            cost[u].pb(0);
            cost[v].pb(w);
        }
        cc=cost[1][1];
        if(e[e[1][0]][0]==1)
            cc+=cost[e[1][0]][0];
        else
            cc+=cost[e[1][0]][1];
        view[1]=1;
        cc+=call(e[1][1]);
        res=cc;
        mem(view,0);
        cc=cost[1][0];
        if(e[e[1][1]][0]==1)
            cc+=cost[e[1][1]][0];
        else
            cc+=cost[e[1][1]][1];
        view[1]=1;
        cc+=call(e[1][0]);
        res=min(res,cc);
        printf("Case %d: %d\n",t++,res);
        for(i=0;i<=n;i++)
        {
            e[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
