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
#define NN 1000

queue<int>q;
vector<int>e[NN+7];
vector<int>pr;
int vis[NN+7];
bool p[NN+7];
void sieve(int n)
{
    int i,j;
    p[1]=1;
    pr.push_back(2);
    for(i=4;i<=n;i+=2)
        p[i]=1;
    for(i=3;i<=n;i+=2)
    {
        if(p[i]==0)
        {
            pr.push_back(i);
            for(j=i*i;j<=n;j+=2*i)
                p[j]=1;
        }
    }
}

int factor(int n)
{
    int k,i,r=n;
    for(i=0;i<pr.size() && pr[i]*pr[i]<=n;i++)
    {
        k=pr[i];
        if(n%k==0)
            e[r].pb(k);
        while(n%k==0)
            n/=k;
        if(n==1)
            break;
    }
    if(n>1 && n!=r)
        e[r].pb(n);
}

int go(int n)
{
    int i,j;
    sieve(n);
    for(i=1;i<=n;i++)
        factor(i);
}

int bfs(int src,int dist)
{
    mem(vis,-1);
    vis[src]=0;
    q=queue<int>();
    q.push(src);
    while(q.size())
    {
        int u=q.front();
        if(u==dist)
            return vis[u];
        q.pop();
        for(int i=0;i<e[u].size();i++)
        {
            int v=u+e[u][i];
            if( v <=1000 && vis[v]==-1)
            {
                vis[v]=vis[u]+1;
                q.push(v);
            }
        }
    }
    return -1;
}


main()
{
    go(1000);
    int tc,t=1;
    int i,j,k,l,m,n,u,v,w,res;
    //scanf("%d",&tc);
    while(~scanf("%d%d",&u,&v))
    {
        if(u==0 && v==0)
            return 0;
        res=bfs(u,v);
        printf("Case %d: %d\n",t++,res);
    }
    return 0;
}












