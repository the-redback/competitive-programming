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

#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))

int dist[333];
int par[333];
vector<int>edge[333];
map<string, int>mp;
queue<int>q;
char a[55555];

int bfs(int src,int dest)
{
    int i,j,k;
    mem(dist,-1);
    q=queue<int>();
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {
        k=q.front();
        q.pop();
        for(i=0;i<edge[k].size();i++)
        {
            if(dist[edge[k][i]]==-1)
            {
                q.push(edge[k][i]);
                dist[edge[k][i]]=k;
                if(edge[k][i]==dest)
                    return k;
            }
        }
    }
    return -1;
}

void go(int n)
{
    if(n<1)
        return;
    go(dist[n]);
    printf("%d ",n);
    return;
}

main()
{
    int tc,t=1;
    int n,i,j,k,l,p,r,m;
    int sum=0;
    while(~scanf("%d",&tc))
    {
        m=tc;
        while(tc--)
        {
            scanf("%s",&a);
            l=strlen(a);
            for(i=0;i<=l;i++)
            {
                if(a[i]=='-')
                {
                    k=sum;
                    sum=0;
                }
                else if(a[i]==',' || a[i]==0)
                {
                    edge[k].push_back(sum);
                    sum=0;
                }
                else
                    sum=sum*10+a[i]-'0';
            }
        }
        scanf("%d",&p);
        puts("-----");
        while(p--)
        {
            scanf("%d%d",&k,&l);
            n=bfs(k,l);
            if(n==-1)
                puts("connection impossible");
            else
            {
                go(dist[l]);
                printf("%d\n",l);
            }
        }
        for(i=0;i<=m;i++)
            edge[i].clear();
    }
    return 0;
}

