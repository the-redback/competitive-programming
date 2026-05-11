/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
using namespace std;

#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))
#define NN 2500
int dist[NN+7];
vector<int>edge[NN+7];
queue<int>q;
int day[NN+7];

int bfs(int src)
{
    int i,j,k;
    mem(dist,-1);
    mem(day,0);
    q=queue<int>();
    q.push(src);
    dist[src]=0;
    int ret=-1;
    int cnt=0;
    while(!q.empty())
    {
        k=q.front();
        q.pop();
        cnt=0;
        for(i=0;i<edge[k].size();i++)
        {
            if(dist[edge[k][i]]==-1)
            {
                q.push(edge[k][i]);
                dist[edge[k][i]]=dist[k]+1;
                day[dist[k]+1]++;
                ret=1;
            }
        }
    }
    return ret;
}

main()
{
    int tc,t=1;
    int n,i,j,k,l,p,r,m;
    int sum=0;
    while(~scanf("%d",&tc))
    {
        for(i=0;i<tc;i++)
        {
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d",&l);
                edge[i].push_back(l);
            }
        }
        scanf("%d",&p);
        while(p--)
        {
            scanf("%d",&k);
            n=bfs(k);
            if(n==-1)
                puts("0");
            else
            {
                int bday=0;
                k=-1;
                for(i=1;i<=tc;i++)
                    if(day[i]>k)
                    {
                        bday=i;
                        k=day[i];
                    }
                printf("%d %d\n",k,bday);
            }
        }
        for(i=0;i<=tc;i++)
            edge[i].clear();
    }
    return 0;
}

