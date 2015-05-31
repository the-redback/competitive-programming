#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector <char>v;
char arr[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
int n,k=0,ct=0;
int visit[30]={0};
void check(void)
{
    if(ct==k)
        return;
    if(v.size()==n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%c",v[i]);
        }
        printf("\n");
        ct++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            v.push_back(arr[i]);
            check();
            v.pop_back();
            visit[i]=0;
        }
    }
}

main()
{
    int i=0,t;
    scanf("%d",&t);
    while(t--)
    {
        i++;
        ct=0;
        scanf("%d %d",&n,&k);
        printf("Case %d:\n",i);
        check();
    }
    return 0;
}
