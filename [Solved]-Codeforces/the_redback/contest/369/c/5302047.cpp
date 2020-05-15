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
int cnt=0;
vector<int>edge[100010];
vector<int>cost[100010];
bool taken[100010]={0};
vector<int>ans(100010,0);
int dfs(int x,int prev,int flag)
{
    int i,j,k,l;
    for(int i=0;i<edge[x].size();i++)
    {
        int u=edge[x][i];
        if(taken[u]==0)
        {
            taken[u]=1;
            if(cost[x][i]==2)
            {
                if(ans[prev]==1)
                {
                    ans[prev]=0;
                    ans[u]=1;
                }
                else
                {
                    cnt++;
                    ans[u]=1;
                }
                dfs(u,u,2);
            }
            else
            {
                dfs(u,prev,flag);
            }

        }
    }
}

main()
{
    int n;
    int i,j,k,l,m,t,x,y;
    while(~scanf("%d",&n))
    {
        for(i=0; i<n-1; i++)
        {
            scanf("%d%d%d",&x,&y,&t);
            edge[x].push_back(y);
            edge[y].push_back(x);
            cost[x].push_back(t);
            cost[y].push_back(t);
        }
        taken[1]=1;
        cnt=0;
        dfs(1,0,1);
        printf("%d\n",cnt);
        int fl=0;
        for(i=1;i<=n;i++)
        {
            if(ans[i]==1)
            {
                if(fl!=0)
                    printf(" ");
                printf("%d",i);
                fl=1;
            }
        }
        printf("\n");
    }
    return 0;
}
