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
char a[200][200];
int N,M;
int call(int i,int j)
{
    if(i<0||j<0||i>=N||j>=N)
        return 0;
    if(a[i][j]=='.')
        return 0;
    a[i][j]='.';
    for(int k=0;k<4;k++)
    {
        call(i+dx[k],j+dy[k]);
    }
    return 0;
}

main()
{
    int n,m,tc,t=1;
    cin>>tc;
    while(tc--)
    {
        scanf("%d",&n);
        getchar();
        N=n;
        for(int i=0;i<n;i++)
            gets(a[i]);
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='x')
                {
                    call(i,j);
                    count++;
                }
            }
        }
        printf("Case %d: %d\n",t++,count);
    }
    return 0;
}
