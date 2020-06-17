#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector<int>v[3];
int N,M,flag,cnt;
void call(int n, int i,int j,int k)
{
    if(cnt==flag)
        return;
    if(n==0)
        return;
    call(n-1,i,k,j);
    if(cnt==flag)
        return;
    cnt++;
    int sm=v[i][v[i].size()-1];
    v[k].push_back(sm);
    v[i].pop_back();
    for(int r=0;r<3;r++)
    {
        if(r==0)
            printf("A=>");
        else if(r==1)
            printf("B=>");
        else if(r==2)
            printf("C=>");
        for(int c=0;c<v[r].size();c++)
        {
            if(c==0)
                printf("  ");
            printf(" %d",v[r][c]);
        }
        puts("");
    }
    puts("");
    if(cnt==flag)
        return;
    call(n-1,j,i,k);
}

main()
{
    int n,m,i,t=1;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0 && m==0)
            return 0;
        printf("Problem #%d\n\n",t);
        t++;
        v[0].clear();
        v[1].clear();
        v[2].clear();
        for(i=n;i>0;i--)
            v[0].push_back(i);
        cnt=0;
        flag=m;
        printf("A=>  ");
        for(i=0;i<v[0].size();i++)
        {
            printf(" %d",v[0][i]);
        }
        puts("");
        printf("B=>\n");
        printf("C=>\n");
        puts("");
        call(n,0,1,2);
    }
}
