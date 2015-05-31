//Undirected Graph
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

vector<int>e[NN],ne[NN];
vector< pair<int,int> >edge;
map<pair<int,int>,int >mymap;
int depth[NN];      //The depth(time) when a node is visited
int par[NN];        //Parent of node
int low[NN];        //A node connected with lowest timed node [if bcc exist]
int color[NN];     //Color if a node is visited or not
int Time,bcc,cnt;


int dfs(int u)
{
    low[u]=depth[u]=++Time;
    color[u]=true;
    int i;
    for(i=0; i<e[u].size(); i++)
    {
        int v=e[u][i];
        if(!color[v])
        {
            par[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(depth[u]<low[v])
            {
                mymap[mp(u,v)]=1;
                mymap[mp(v,u)]=1;
            }
        }
        else if(v!=par[u])
            low[u]=min(low[u],depth[v]);
    }
    return 0;
}


int bicolorable(int u)
{
    cnt++;
    int i,flag=1;
    for(i=0; i<ne[u].size(); i++)
    {
        int v=ne[u][i];
        if(color[v]==-1)
        {
            par[v]=u;
            color[v]=color[u]^1;
            if(!bicolorable(v))
                flag=0;
        }
        else if(par[u]!=v && color[u]==color[v])
            flag=0;
    }
    return flag;
}

int findbcc(int n)
{
    mem(depth,0);
    mem(par,-1);
    mem(low,0);
    mem(color,0);
    mymap.clear();
    Time=bcc=0;

    for(int i=0; i<n; i++)  //lowest node=0
        if(!color[i])
            dfs(i);
    int Highest_Node=Time;

    for(int i=0; i<edge.size(); i++)
    {
        int u=edge[i].first;
        int v=edge[i].second;
        if(mymap.find(mp(u,v))==mymap.end())
        {
            ne[u].pb(v);
            ne[v].pb(u);
        }
    }
    return Highest_Node;
}

int go(int n)
{
    int node=findbcc(n);
    mem(color,-1);
    mem(depth,0);
    mem(par,-1);
    int ans=0,i;
    for(i=0; i<n; i++)
    {
        if(color[i]==-1)
        {
            cnt=0;
            color[i]=0;
            if(!bicolorable(i) && cnt>1)
                ans+=cnt;
        }
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    cin>>tc;          //Test Case
    int i,j,k,l,m,n;
    while(tc--)
    {
        cin>>n>>m;
        for(i=0; i<m; i++)
        {
            cin>>k>>l;
            e[k].pb(l);
            e[l].pb(k);
            edge.pb(mp(k,l));
        }
        int ans=go(n);
        printf("Case %d: %d\n",t++,ans);
        for(i=0; i<=n; i++)
            e[i].clear(),ne[i].clear();
        edge.clear();
    }
    return 0;
}
