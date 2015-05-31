#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
char a[1000][1000];
int N,M;
struct data
{
    int x;
    char c;
};

void call(int i,int j,char ch)
{
    if(i<0||j<0||i>=N||j>=M)
        return;
    if(a[i][j]!=ch)
        return;
    a[i][j]='.';
    for(int k=0;k<8;k++)
    {
        call(i+dx[k],j+dy[k],ch);
    }
    return;
}

bool comp(data m,data n)
{
    if(n.x==m.x)
        return m.c<n.c;
    else
        return m.x>n.x;

}

main()
{
    data d[100];
    int n,m,tc,t=1;
    cin>>tc;
    while(tc--)
    {
        scanf("%d%d",&n,&m);
        getchar();
        N=n;
        M=m;
        for(int i=0;i<n;i++)
            gets(a[i]);
        for(int i=0;i<35;i++)
            d[i].x=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]>='a' && a[i][j]<='z')
                {
                    int k=a[i][j]-'a';
                    d[k].x+=1;
                    d[k].c=a[i][j];
                    call(i,j,a[i][j]);
                }
            }
        }
        sort(d,d+35,comp);
        printf("World #%d\n",t++);
        for(int i=0;i<35;i++)
        {
            if(d[i].x!=0)
            {
                printf("%c: %d\n",d[i].c,d[i].x);
            }
            else
                break;
        }
    }
    return 0;
}
