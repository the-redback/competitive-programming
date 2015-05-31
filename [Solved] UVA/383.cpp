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


