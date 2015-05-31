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

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define NN 20100

vector<int>arr;
vector<pair<int,int> >e;
vector<int>g[NN],tg[NN];
int view[NN],sinc[NN],source[NN];

int dfs(int u)
{
    int i;
    view[u]=1;
    for(i=0; i<g[u].size(); i++)
    {
        if(view[g[u][i]]==0)
            dfs(g[u][i]);
    }
    arr.pb(u);
}

int dfs_2nd(int u,int k)
{
    int i;
    view[u]=k;
    for(i=0; i<tg[u].size(); i++)
    {
        if(view[tg[u][i]]==0)
            dfs_2nd(tg[u][i],k);
    }
}

int scc(int n)
{
    int i;
    mem(view,0);
    arr.clear();
    for(i=1; i<=n; i++)
        if(view[i]==0)
            dfs(i);
    mem(view,0);
    reverse(all(arr));
    int k=0,l;
    for(i=0; i<arr.size(); i++)
        if(view[arr[i]]==0)
            dfs_2nd(arr[i],k+1),k++;
    int nodes=k;
    if(nodes<=1)
        return 0;
    mem(source,0);
    mem(sinc,0);
    int src,si;
    src=si=nodes;
    for(i=0; i<e.size(); i++)
    {
        k=e[i].first;
        l=e[i].second;
        if(view[k]!=view[l])
        {
            if(sinc[view[k]]==0)
                si--;
            if(source[view[l]]==0)
                src--;

            sinc[view[k]]=1;
            source[view[l]]=1;
        }
    }
    return max(src,si);
}

main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    cin>>tc;
    int i,j,k,l,m,n;
    while(tc--)
    {
        cin>>n>>m;

        for(i=0; i<=n; i++)
        {
            g[i].clear();
            tg[i].clear();
        }
        e.clear();
        for(i=0; i<m; i++)
        {
            cin>>k>>l;
            g[k].pb(l);
            tg[l].pb(k);
            e.pb(make_pair(k,l));
        }
        int nodes=scc(n);
        printf("Case %d: %d\n",t++,nodes);
    }
    return 0;
}
