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

#define inf 1000000000
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 100
struct edge
{
    int u,v,w,flag;
};
vector<edge>e;
int pr[NN+7];
int Flag;
bool comp(edge n,edge m)
{
    return n.w<m.w;
}

int root(int n)
{
    if(n==pr[n])
        return n;
    return root(pr[n]);
}

int mst(int n)
{
    int i,j,k;
    for(i=0; i<=n; i++)
        pr[i]=i;
    int count=0,cost=0;
    for(i=0; i<e.size() && count<n-1; i++)
    {
        int u=root(e[i].u);
        int v=root(e[i].v);
        if(u!=v && e[i].flag)
        {
            pr[u]=v;
            count++;
            cost+=e[i].w;
            if(!Flag)
                e[i].flag=2;
            else
                e[i].flag=max(e[i].flag,1);
        }
    }
    Flag=1;
    if(count!=n-1)
        return inf;
    return cost;
}

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,u,v,w;
    int tc,t=1,m;
    edge ed;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&r);
        e.clear();
        while(r--)
        {
            scanf("%d%d%d",&ed.u,&ed.v,&ed.w);
            ed.flag=1;
            e.push_back(ed);
        }
        Flag=0;
        sort(e.begin(),e.end(),comp);
        int sum=mst(n);
        if(sum==inf)
        {
            printf("Case #%d : No way\n",t++);
            continue;
        }
        r=inf;
        for(i=0; i<e.size(); i++)
        {
            if(e[i].flag==2)
            {
                e[i].flag=0;
                r=min(r,mst(n));
                e[i].flag=2;
            }
        }
        if(r==inf)
            printf("Case #%d : No second way\n",t++);
        else
            printf("Case #%d : %d\n",t++,r);
    }
    return 0;
}






