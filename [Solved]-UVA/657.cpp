#include <bits/stdc++.h>
using namespace std;
char a[200][200];
int N,M;
int dirx[]={-1,0,0,1};
int diry[]={0,-1,1,0};

vector<int>v;

void vanish(int i,int j)
{
    if(i<0 || j<0 || i>=N|| j>=M)
        return;
    if(a[i][j]!='X')
        return;
    a[i][j]='@';
    for(int k=0;k<4;k++)
    {
        vanish(i+dirx[k],j+diry[k]);
    }
    return;
}

int call(int i,int j)
{
    if(i<0 || j<0 || i>=N|| j>=M)
        return 0;
    int sum=0;
    if(a[i][j]=='.')
        return 0;
    if(a[i][j]=='X')
    {
        vanish(i,j);
        sum=1;
    }
    a[i][j]='.';
    for(int k=0;k<4;k++)
    {
        sum+=call(i+dirx[k],j+diry[k]);
    }
    return sum;
}

main()
{
    int total=1;
    while(scanf("%d %d",&M,&N)==2)
    {
        v.clear();
        if(M==0 && N==0)
            return 0;
        getchar();
        for(int k=0;k<N;k++)
        {
            scanf("%s",&a[k]);
        }
        printf("Throw %d\n",total++);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(a[i][j]!='.')
                {
                    int sum=0;
                    sum=call(i,j);
                    v.push_back(sum);
                }
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(i!=0)
                printf(" ");
            printf("%d",v[i]);
        }
        puts("");
        puts("");
    }
    return 0;
}
