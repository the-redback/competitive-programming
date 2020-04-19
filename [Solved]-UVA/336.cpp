#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
vector <int> v[50];
vector <int>taken;
void bfs(int src,int rem)
{
    queue <int>q;
    int i,j,n;
    q.push(src);
    taken[src]=1;
    while(q.size())
    {
        n=q.front();
        if(taken[n]==rem+1)
            return;
        for(i=0; i<v[n].size(); i++)
        {
            if(taken[v[n][i]]==-1)
            {
                taken[v[n][i]]=taken[n]+1;
                q.push(v[n][i]);
            }
        }
        q.pop();
    }
}
main()
{
    int i,j=0,k,l,e,n,count;
    vector<int> view(50);
    map<int,int>mp;
    while(scanf("%d",&n))
    {
        e=0;
        mp.clear();
        if(n==0)
            return 0;
        for(i=0; i<view.size(); i++)
            view[i]=0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&k,&l);
            if(mp.find(k)==mp.end())
            {
                mp[k]=e++;
            }
            if(mp.find(l)==mp.end())
            {
                mp[l]=e++;
            }
            v[mp[k]].push_back(mp[l]);
            v[mp[l]].push_back(mp[k]);
            view[mp[k]]=-1;
            view[mp[l]]=-1;
        }
        while(1)
        {
            scanf("%d %d",&k,&l);
            if(k==0 && l==0)
                break;
            taken=view;
            bfs(mp[k],l);
            sort(taken.begin(),taken.end());
            count=0;
            for(i=0; i<taken.size(); i++)
            {
                if(taken[i]==-1)
                    count++;
                else
                    break;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++j,count,k,l);
        }
        for(i=0;i<50;i++)
            v[i].clear();
    }
    return 0;
}
