/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        100100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

ll n;
ll level[NN];
bool vis[NN];
ll par[NN];
ll dist[NN];
ll P[NN][20],D[NN][20];
vector<ll>g[NN],cost[NN];

struct data
{
    ll u,v,w;
}edge[100010];

ll root[NN];
ll Rank[NN];

bool comp(data a,data b)
{
    return a.w<b.w;
}

ll Find(ll u)
{
    if(root[u]!=u)
        root[u]=Find(root[u]);
    return root[u];
}

void Union(ll u,ll v)
{
    if(Rank[u]>Rank[v])
        root[v]=u;
    else
    {
        root[u]=v;
        if(Rank[u]==Rank[v])
            Rank[v]++;
    }
    return;
}

void MST(ll m)
{
    sort(edge,edge+m,comp);

    ll i,j,k,l,r;

    for(i=0;i<=n;i++)
    {
        root[i]=i;
        Rank[i]=0;
    }

    for(i=0;i<m;i++)
    {
        ll u=Find(edge[i].u);
        ll v=Find(edge[i].v);
        if(u!=v)
        {
            Union(u,v);

            k=edge[i].u;
            l=edge[i].v;
            r=edge[i].w;

            g[k].pb(l);
            g[l].pb(k);
            cost[k].pb(r);
            cost[l].pb(r);
        }
    }
    return;
}

void dfs(ll u)
{
    vis[u]=1;
    ll i,v;
    for(i=0; i<g[u].size(); i++)
    {
        v=g[u][i];
        if(vis[v]==0)
        {
            level[v]=level[u]+1;
            par[v]=u;
            dist[v]=cost[u][i];
            dfs(v);
        }
    }
    return;
}

void lca_init(void)
{
    mem(vis,0);
    mem(par,-1);
    mem(P,-1);
    mem(D,0);
    mem(dist,0);

    level[1]=0;
    dfs(1);

    ll i,j,k;

    for(i=1; i<=n; i++)
    {
        P[i][0]=par[i];
        D[i][0]=dist[i];
    }

    for(j=1; 1<<j <=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(P[i][j-1]!=-1)
            {
                P[i][j]=P[P[i][j-1]][j-1];
                D[i][j]=max(D[i][j-1],D[P[i][j-1]][j-1]);
            }
        }
    }
    return;
}

ll lca_query(ll p,ll q)
{
    if(level[p]<level[q])
        swap(p,q);

    ll i,j,k,log;

    log=1;
    while(1<<log <=n)
        log++;
    log--;

    ll ans=0;

    for(i=log; i>=0; i--)
        if(level[p]- (1<<i) >=level[q])
        {
            ans=max(ans,D[p][i]);
            p=P[p][i];
        }

    if(p==q)
        return ans;

    for(i=log; i>=0; i--)
        if(P[p][i]!=-1 && P[p][i]!=P[q][i])
        {
            ans=max(ans,D[p][i]);
            ans=max(ans,D[q][i]);
            p=P[p][i],q=P[q][i];
        }

    ans=max(ans,D[p][0]);
    ans=max(ans,D[q][0]);

    return ans;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    cin>>tc;
    ll i,j,k,l,m;
    ll r,p,q;
    while(tc--)
    {
        cin>>n>>m;
        for(i=0;i<=n;i++)
        {
            g[i].clear();
            cost[i].clear();
        }

        for(i=0;i<m;i++)
            cin>>edge[i].u>>edge[i].v>>edge[i].w;

        MST(m);

        lca_init();
        cin>>r;
        printf("Case %d:\n",t++);
        while(r--)
        {
            cin>>p>>q;
            ll ans=lca_query(p,q);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
