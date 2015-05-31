/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
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

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 10010

vector<int>Graph[NN];
vector< pair<int,int> >edge;
int depth[NN];
int par[NN];
int low[NN];
int degree[NN];
bool color[NN];
int Time;

int dfs(int u)
{
    low[u]=depth[u]=++Time;
    color[u]=true;
    int i;
    for(i=0; i<Graph[u].size(); i++)
    {
        int v=Graph[u][i];
        if(!color[v])
        {
            par[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=par[u])
            low[u]=min(low[u],depth[v]);
    }
    return 0;
}

int biconnected_component(int n)
{
    mem(depth,0);
    mem(par,-1);
    mem(low,0);
    mem(color,0);
    mem(degree,0);
    Time=0;

    for(int i=0; i<n; i++)  //lowest node=0
        if(!color[i])
            dfs(i);
    int Highest_Node=Time;

    for(int i=0;i<edge.size();i++)
    {
        int u=low[edge[i].first];
        int v=low[edge[i].second];
        if(u!=v)
        {
            degree[u]++;
            degree[v]++;
        }
    }
    int ans=0;
    for(int i=0;i<=Time;i++)
        if(degree[i]==1)
            ans++;

    return ceil(ans/2.0);
}

main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    cin>>tc;          //Test Case
    int i,j,k,l,m,n;
    int e;
    while(tc--)
    {
        cin>>n>>e;
        for(i=0; i<e; i++)
        {
            cin>>k>>l;
            Graph[k].pb(l);
            Graph[l].pb(k);
            edge.pb(mp(k,l));
        }
        int ans=biconnected_component(n);
        printf("Case %d: %d\n",t++,ans);
        for(i=0; i<=n; i++)
            Graph[i].clear();
        edge.clear();
    }
    return 0;
}

/*
Input:
2

4 3
1 2
2 3
2 0

3 3
1 2
2 0
0 1

Output:
Case 1: 2
Case 2: 0
*/
