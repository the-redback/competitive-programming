#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <int> v[201];
int N,flag;
void bfs(int n)
{
    int i;
    queue <int> q;
    q.push(n);
    int view[220]= {0};
    view[n]=1;
    while(q.size())
    {
        int n=q.front();
        for(i=0; i<v[n].size(); i++)
        {
            if(view[v[n][i]]==0)
            {
                q.push(v[n][i]);
                view[v[n][i]]=view[n]+1;
            }
            else if(view[v[n][i]]%2==view[n]%2)
            {
                flag=1;
                return;
            }
        }
        q.pop();
    }
}

main()
{
    int i,j,k,l,n,e;
    while(scanf("%d",&N))
    {
        if(N==0)
            return 0;
        scanf("%d",&e);
        for(i=0; i<e; i++)
        {
            scanf("%d %d",&k,&l);
            v[k].push_back(l);
            v[l].push_back(k);
        }
        flag=0;
        bfs(0);
        if(flag==1)
            puts("NOT BICOLORABLE.");
        else
            puts("BICOLORABLE.");
        for(i=0;i<201;i++)
        {
            v[i].clear();
        }
    }
    return 0;
}
