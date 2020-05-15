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
#define eps 1e-9
#define inf 1000000000
#define NN 1000010

vector<int>e[NN+7],v;
int view[NN+7];
int f,fl;

void dfs(int u)
{
    int i,k,l;
    view[u]=0;
    for(i=0; i<e[u].size(); i++)
    {
        if(view[e[u][i]]==-1)
            dfs(e[u][i]);
    }
    view[u]=1;
    v.pb(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,k,l;
    int tc,t;
    int n,m;
    while(cin>>n>>m)
    {
        mem(view,-1);
        for(i=0; i<m; i++)
        {
            cin>>k>>l;
            e[l].pb(k);
        }
        fl=0;
        for(i=1; i<=n; i++)
        {
            f=i;
            if(view[i]==-1)
                dfs(i);
        }
        reverse(v.begin(),v.end());
        for(i=0; i<v.size(); i++)
        {
            if(i)
                printf(" ");
            printf("%d",v[i]);
        }
        puts("");
        v.clear();
        for(i=0; i<=n; i++)
            e[i].clear();

    }
    return 0;

}
