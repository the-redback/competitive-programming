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
#define NN 1000010

vector<int>e[NN+7],v;
int view[NN+7];
int f,fl;

void dfs(int u)
{
    int i,k,l;
    view[u]=0;
    for(i=0;i<e[u].size();i++)
    {
        if(view[e[u][i]]==-1)
            dfs(e[u][i]);
        else if(view[e[u][i]]==0)
        {
            fl=1;
            return;
        }
    }
    view[u]=1;
    v.pb(u);
}

int main()
{
    int i,j,k,l;
    int tc,t;
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            return 0;
        mem(view,-1);
        for(i=0;i<m;i++)
            scanf("%d%d",&k,&l),e[k].pb(l);
        fl=0;
        for(i=1;i<=n;i++)
        {
            f=i;
            if(view[i]==-1)
                dfs(i);
        }
        if(fl)
            printf("IMPOSSIBLE\n");
        else
        {
            reverse(v.begin(),v.end());
            for(i=0;i<v.size();i++)
                printf("%d\n",v[i]);
        }
        v.clear();
        for(i=0;i<=n;i++)
            e[i].clear();

    }
    return 0;

}
