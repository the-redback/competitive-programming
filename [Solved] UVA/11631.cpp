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
#define NN 200000
int prnt[NN+7];
struct data
{
    int u,v,w;
};
vector<data>e;
bool comp(data n,data m)
{
    return n.w<m.w;
}

int root(int n)
{
    if(prnt[n]==n)
        return n;
    return root(prnt[n]);
}

int mst(int n)
{
    sort(e.begin(),e.end(),comp);
    int i,j,k,node,dist;
    for(i=0;i<=n;i++)
        prnt[i]=i;
    node=dist=0;
    for(i=0;i<e.size() && node<n-1;i++)
    {
        int u=root(e[i].v);
        int v=root(e[i].u);
        if(u!=v)
        {
            prnt[u]=v;
            node++;
            dist+=e[i].w;
        }
    }
    return dist;
}

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,u,v;
    int tc,t=1,sum=0;
    //scanf("%d",&tc);
    while(~scanf("%d%d",&n,&r))
    {
        if(n==0 && r==0)
            return 0;
        k=0;
        sum=0;
        for(i=0;i<r;i++)
        {
            scanf("%d%d%d",&u,&v,&l);
            data d;
            d.u=u;
            d.v=v;
            d.w=l;
            sum+=l;
            e.push_back(d);
        }
        int ret=mst(n);
        ret=sum-ret;
        printf("%d\n",ret);
        e.clear();
    }
    return 0;
}





