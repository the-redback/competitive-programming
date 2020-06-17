#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int a[20][20];
bool visit[15];
vector<int>v;
int N,R,flag;
void call(int r)
{
    int i,j,k;
    if(v.size()==N+1)
    {
        flag=1;
        printf("(");
        for(i=0; i<v.size(); i++)
        {
            if(i!=0)
                printf(",");
            printf("%d",v[i]+1);
        }
        printf(")\n");
        return;
    }
    for(i=0; i<R; i++)
    {
        if(a[r][i]==1 && visit[i]==0)
        {
            v.push_back(i);
            visit[i]=1;
            call(i);
            visit[i]=0;
            v.pop_back();
        }
    }
    return;
}

main()
{
    int tc,n,i,j,k;
    int t=0;
    while(scanf("%d",&tc)==1)
    {
        if(tc==-9999)
        {
            scanf("%d%d",&R,&N);
        }
        else
        {
            R=tc;
            scanf("%d",&N);
        }
        for(i=0; i<R; i++)
            for(j=0; j<R; j++)
                scanf("%d",&a[i][j]);
        memset(visit,0,sizeof(visit));
        if(t!=0)
            puts("");
        t++;
        v.clear();
        v.push_back(0);
        visit[0]=1;
        flag=0;
        call(0);
        if(flag==0)
            printf("no walk of length %d\n",N);
    }
    return 0;
}
