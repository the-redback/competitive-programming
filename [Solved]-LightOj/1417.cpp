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
#define NN 50050

int dp[NN];
bool color[NN];
vector<int>arr;          //topological sorted node
vector<int>e[NN];        //Graph Before SCC
vector<int>te[NN];       //Transpose Graph Before SCC
vector<int>ne[NN];       //New Graph After SCC
vector<pair<int,int> >v; //Edges Before SCC
int id[NN];              //Id of Nodes After SCC
int amount[NN];          //Amount of original node in a SCC node


int dfs_1st(int u)
{
    color[u]=true;
    for(int i=0;i<e[u].size();i++)
    {
        if(!color[e[u][i]])
            dfs_1st(e[u][i]);
    }
    arr.pb(u);
}

int dfs_2nd(int u,int k)
{
    color[u]=true;
    id[u]=k;

    for(int i=0;i<te[u].size();i++)
    {
        if(!color[te[u][i]])
            dfs_2nd(te[u][i],k);
    }
}

int dfs(int u)
{
    if(dp[u]!=-1)
        return dp[u];

    dp[u]=0;
    int sum=0;

    for(int i=0;i<ne[u].size();i++)
    {
        sum=max(sum,dfs(ne[u][i]));
    }
    dp[u]=sum+amount[u];
    return dp[u];
}


int scc(int n)
{
    arr.clear();
    mem(color,0);
    int i,j,k,l;

    for(i=1;i<=n;i++)
        if(color[i]==0)
            dfs_1st(i);

    reverse(all(arr));

    mem(id,-1);
    mem(color,0);
    mem(amount,0);
    k=0;

    for(i=0;i<arr.size();i++)
    {
        if(!color[arr[i]])
        {
            dfs_2nd(arr[i],k+1);
            amount[id[arr[i]]]=1;
            k++;
        }
        else
            amount[id[arr[i]]]++;
    }

    int node=k;

    for(i=0;i<v.size();i++)
    {
        k=v[i].first;
        l=v[i].second;

        if(id[k]!=id[l])
            ne[id[k]].pb(id[l]);
    }
    int sum=0;
    int ans=0;
    mem(dp,-1);
    for(i=1;i<=n;i++)
    {
        int temp=dfs(id[i]);
        if(sum<temp)
            sum=temp,ans=i;
    }

    return ans;  //Number of actual node.
}


main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    int i,j,k,l,m,n,man;

    cin>>tc;    //Test Case
    while(tc--)
    {
        cin>>n; //n=node, m=edge

        for(i=0;i<=n;i++)
        {
            e[i].clear();
            te[i].clear();
            ne[i].clear();
        }
        v.clear();

        for(i=0;i<n;i++)
        {
            cin>>k>>l;
            e[k].pb(l);
            te[l].pb(k);
            v.pb(make_pair(k,l));
        }

        int sum=scc(n);
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
