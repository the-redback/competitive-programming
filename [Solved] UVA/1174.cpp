/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
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
#define NN 2010
int prnt[NN+7];
map<string,int>mp;
string s,ss;
char a[20];
char b[20];
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
    int i,j,k,l,n,r,c;
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&r);
        k=0;
        for(i=0;i<r;i++)
        {
            scanf("%s%s%d",&a,&b,&l);
            s.assign(a);
            ss.assign(b);
            if(mp.find(s)==mp.end())
                mp[s]=k++;
            if(mp.find(ss)==mp.end())
                mp[ss]=k++;
            data d;
            d.u=mp[s];
            d.v=mp[ss];
            d.w=l;
            e.push_back(d);
        }
        int ret=mst(n);
        if(t!=1)
            printf("\n");
        t++;
        printf("%d\n",ret);
        mp.clear();
        e.clear();
    }
    return 0;
}





