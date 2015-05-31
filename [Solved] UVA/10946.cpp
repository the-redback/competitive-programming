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

int call(int i,int j,char ch)
{
    if(i<0||j<0||i>=N||j>=M)
        return 0;
    if(a[i][j]!=ch)
        return 0;
    a[i][j]='.';
    int sum=1;
    for(int k=0;k<8;k++)
    {
        sum+=call(i+dx[k],j+dy[k],ch);
    }
    return sum;
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
    data dd;
    vector<data>v;
    int n,m,tc,t=1;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0 )
            return 0;
        getchar();
        N=n;
        M=m;
        v.clear();
        for(int i=0;i<n;i++)
            gets(a[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]>='A' && a[i][j]<='Z')
                {
                    int k=a[i][j]-'A';
                    dd.c=a[i][j];
                    dd.x=call(i,j,a[i][j]);
                    v.push_back(dd);
                }
            }
        }
        sort(v.begin(),v.end(),comp);
        printf("Problem %d:\n",t++);
        for(int i=0;i<v.size();i++)
            printf("%c %d\n",v[i].c,v[i].x);
    }
    return 0;
}
