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
#define NN 1010

vector<int>e[NN];
vector<int>te[NN];
map<string,int>mp;
int color[NN];
vector<int>arr;

void dfs1(int u)
{
    color[u]=1;
    for(int i=0; i<e[u].size(); i++)
    {
        int v=e[u][i];
        if(!color[v])
            dfs1(v);
    }
    arr.pb(u);
    return;
}

void dfs2(int u,int flag)
{
    color[u]=flag;
    for(int i=0; i<te[u].size(); i++)
    {
        int v=te[u][i];
        if(!color[v])
            dfs2(v,flag);
    }
    return;
}

int scc(int n)
{
    int i;
    mem(color,0);
    for(i=1; i<=n; i++)
    {
        if(!color[i])
            dfs1(i);
    }
    mem(color,0);
    int cnt=0;
    int r=0;
    reverse(all(arr));
    for(i=0; i<arr.size(); i++)
    {
        if(!color[arr[i]])
        {
            dfs2(arr[i],++r);
            cnt++;
        }
    }
    return cnt;
}
string s,ss;
char a[100];

main()
{
    //ios_base::sync_with_stdio(false);
    int t=0,tc;
    int n,m,i,j,l,k;
    //cin>>tc;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            return 0;
        getchar();
        int r=1;
        for(i=0; i<n; i++)
        {
            gets(a);
            s.assign(a);
            mp[s]=r++;
        }
        for(i=0; i<m; i++)
        {
            gets(a);
            s.assign(a);
            gets(a);
            ss.assign(a);
            e[mp[s]].pb(mp[ss]);
            te[mp[ss]].pb(mp[s]);
        }

        int cnt=scc(n);
        printf("%d\n",cnt);
        for(i=0; i<=n; i++)
            e[i].clear(),te[i].clear();
        arr.clear();
        mp.clear();
    }
    return 0;
}
