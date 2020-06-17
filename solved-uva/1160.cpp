/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : Redback
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

#define inf 10000000
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 100010
int prnt[NN+7];
struct data
{
    int u,v;
};
vector<data>e;

int root(int n)
{
    if(prnt[n]==n)
        return n;
    return root(prnt[n]);
}

int mst(int n)
{
    int i,j,k,node,dist;
    for(i=0; i<=n; i++)
        prnt[i]=i;
    node=dist=0;
    for(i=0; i<e.size() && node<n-1; i++)
    {
        int u=root(e[i].v);
        int v=root(e[i].u);
        if(u!=v)
            prnt[u]=v;
        else
            node++;
    }
    return node;
}

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,u,v,w;
    int tc,t=1,x=-1;
    data nn;
    //scanf("%d",&tc);
    while(~scanf("%d",&u))
    {
        while(u!=-1)
        {
            scanf("%d",&v);
            x=max(x,u);
            x=max(x,v);
            nn.u=u;
            nn.v=v;
            e.push_back(nn);
            scanf("%d",&u);
        }
        int ret=mst(x);
        printf("%d\n",ret);
        e.clear();
    }
    return 0;
}






