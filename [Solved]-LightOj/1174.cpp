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
#define NN 111

vector<int>arr;
vector<int>e[NN];
int viw1[NN],viw2[NN];
queue<int>q;

int bfs1(int src)
{
    mem(viw1,-1);
    viw1[src]=0;
    q=queue<int>();
    q.push(src);
    int i,k,l;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(i=0;i<e[u].size();i++)
        {
            if(viw1[e[u][i]]==-1)
            {
                viw1[e[u][i]]=viw1[u]+1;
                q.push(e[u][i]);
            }
        }
    }
}

int bfs2(int src)
{
    mem(viw2,-1);
    viw2[src]=0;
    q=queue<int>();
    q.push(src);
    int i,k,l;
    int ans=0;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        ans=max(ans,viw1[u]+viw2[u]);
        for(i=0;i<e[u].size();i++)
        {
            if(viw2[e[u][i]]==-1)
            {
                viw2[e[u][i]]=viw2[u]+1;
                q.push(e[u][i]);
            }
        }
    }
    return ans;
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

        for(i=0;i<=n;i++)
            e[i].clear();
        for(i=0;i<m;i++)
        {
            cin>>k>>l;
            e[k].pb(l);
            e[l].pb(k);
        }
        int src,dest;
        cin>>src>>dest;
        bfs1(src);
        int ans=bfs2(dest);
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
