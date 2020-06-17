#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
vector<int>v[100010];
vector<int>v1;
int a[100010];
int check(int n)
{
    int o=0,t=0,th=0;
    for(int i=0; i<v[n].size(); i++)
    {
        if(a[v[n][i]]==1)
            o++;
        else if(a[v[n][i]]==2)
            t++;
        else if(a[v[n][i]]==3)
            th++;
    }
    if(o==0)
        return 1;
    else if(t==0)
        return 2;
    else if(th==0)
        return 3;
}

int main ()
{
    int i,j,k,l,m,n,h;
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&j,&k,&l);
            v[j].push_back(k);
            v[j].push_back(l);
            v[k].push_back(j);
            v[k].push_back(l);
            v[l].push_back(j);
            v[l].push_back(k);
            v1.push_back(j);
            v1.push_back(k);
            v1.push_back(l);
        }
        for(i=0; i<v1.size(); i++)
        {
            if(a[v1[i]]==0)
            {
                l=check(v1[i]);
                a[v1[i]]=l;
            }
        }
        for(i=1; i<=n; i++)
        {
            if(i!=1)
                printf(" ");
            printf("%d",a[i]);
        }
        puts("");
        i=0;
        while(v[i].size())
        {
            v[i].clear();
            i++;
        }
        v1.clear();
    }
    return 0;
}
