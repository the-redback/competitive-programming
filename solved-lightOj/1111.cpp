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
#define NN 1011

vector<int>e[NN],arr;
bool viw[NN];
int dis[NN];
queue<int>q;

int dfs(int u)
{
    viw[u]=1;
    dis[u]++;
    for(int i=0;i<e[u].size();i++)
        if(viw[e[u][i]]==0)
            dfs(e[u][i]);
}


main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    cin>>tc;
    int i,j,k,l,m,n,man;
    while(tc--)
    {
        cin>>man>>n>>m;
        arr.clear();
        for(i=0;i<man;i++)
            cin>>k,arr.pb(k);
        for(i=0;i<=n;i++)
            e[i].clear();
        for(i=0;i<m;i++)
        {
            cin>>k>>l;
            e[k].pb(l);
        }
        mem(dis,0);
        int sum=0;
        for(i=0;i<man;i++)
        {
            mem(viw,0);
            dfs(arr[i]);
        }
        for(i=0;i<=n;i++)
            if(dis[i]==man)
                sum++;
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
