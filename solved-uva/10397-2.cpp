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
#include <iomanip>
using namespace std;

#define inf 10000000
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 800

struct edge
{
    int u,v;
    double w;
};
struct node
{
    double x,y;
};
struct point
{
    int x,y;
};
node a[NN+7];
int pr[NN+7];
vector<edge>e;
vector<point>V;
bool compoint(point n,point m)
{
    if(n.x==m.x)
        return n.y<m.y;
    return n.x<m.x;
}
bool comp(edge n,edge m)
{
    return n.w<m.w;
}

int root(int n)
{
    if(pr[n]==n)
        return n;
    return root(pr[n]);
}
double mst(int n)
{
    int i,j,k;
    for(i=0; i<=n; i++)
        pr[i]=i;
    sort(e.begin(),e.end(),comp);
    int count=0;
    double sum=0;
    for(i=0; i<e.size() && count<n-1; i++)
    {
        int u=root(e[i].u);
        int v=root(e[i].v);
        if(u!=v)
        {
            pr[u]=v;
            count++;
            sum+=e[i].w;
        }
    }
    return sum;
}

main()
{
    //freopen("C:\\Users\\Maruf Tuhin\\Desktop\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,u,v,w;
    edge ed;
    node nd;
    point pn;
    int tc,t=1,m;
    double x;
    //scanf("%d",&tc);
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            cin>>a[i].x>>a[i].y;
        cin>>r;
        while(r--)
        {
            cin>>u>>v;
            pn.x=min(u,v);
            pn.y=max(u,v);
            V.push_back(pn);
        }
        sort(V.begin(),V.end(),compoint);
        r=0;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
            {
                if(r<V.size() && V[r].x==i && V[r].y==j)
                    x=0,r++;
                else
                    x=sqrt(((a[i].x-a[j].x)*(a[i].x-a[j].x))+((a[i].y-a[j].y)*(a[i].y-a[j].y)));
                ed.u=i;
                ed.v=j;
                ed.w=x;
                e.push_back(ed);
            }
        double sum=mst(n);
        cout<<fixed<<setprecision(2)<<sum<<"\n";
        e.clear();
        V.clear();
    }
    return 0;
}






