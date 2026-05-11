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

int dist[20];
vector<int>edge[50];
map<string, int>mp;
queue<int>q;
string s;

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
                dist[edge[k][i]]=dist[k]+1;
                if(edge[k][i]==dest)
                {
                    return dist[k]+1;
                }
            }
        }
    }
    return -1;
}
char a[10];
char c[10];
main()
{
    int tc,t=1;
    int n,i,j,k,l,p,r,m;
    puts("SHIPPING ROUTES OUTPUT\n");
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&n,&r,&p);
        i=1;
        m=n;
        while(n--)
        {
            scanf("%s",&a);
            s.assign(a);
            mp[s]=i;
            i++;
        }
        while(r--)
        {
            scanf("%s%s",&a,&c);
            s.assign(a);
            k=mp[s];
            s.assign(c);
            l=mp[s];
            edge[k].push_back(l);
            edge[l].push_back(k);
        }
        printf("DATA SET  %d\n\n",t++);
        while(p--)
        {
            scanf("%d%s%s",&r,&a,&c);
            s.assign(a);
            k=mp[s];
            s.assign(c);
            l=mp[s];
            n=bfs(k,l);
            if(n==-1)
                puts("NO SHIPMENT POSSIBLE");
            else
                printf("$%d\n",r*n*100);
        }
        puts("");
        for(i=0;i<=m;i++)
            edge[i].clear();
        mp.clear();
    }
    puts("END OF OUTPUT");
    return 0;
}


