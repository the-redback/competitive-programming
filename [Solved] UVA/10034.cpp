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
#define NN 111

struct edge
{
    int u,v;
    double w;
};
struct node
{
    double x,y;
};
node a[NN+7];
int pr[NN+7];
vector<edge>e;
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
    //ios_base::sync_with_stdio(false);
    int i,j,k,l,n,r,c,u,v,w;
    edge ed;
    node nd;
    int tc,t=1,m;
    double x;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
            {
                x=((a[i].x-a[j].x)*(a[i].x-a[j].x))+((a[i].y-a[j].y)*(a[i].y-a[j].y));
                x=sqrt((double)x);
                ed.u=i;
                ed.v=j;
                ed.w=x;
                e.push_back(ed);
            }
        double sum=mst(n);
        if(t!=1)
            puts("");
        t++;
        printf("%.2lf\n",sum);
        e.clear();
    }
    cin>>n;

    return 0;
}





