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
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
char a[200][200];
int N,M;
int call(int i,int j)
{
    int sum=0;
    if(i<0||j<0||i>=N||j>=M)
        return 0;
    if(a[i][j]=='@' || a[i][j]=='#')
        return 0;
    if(a[i][j]=='G')
        sum=1;
    a[i][j]='@';
    for(int k=0; k<4; k++)
    {
        if(i+dx[k]>=0 && i+dx[k]<N && j+dy[k]>=0 && j+dy[k]<M && a[i+dx[k]][j+dy[k]]=='T')
        {
            return sum;
        }
    }
    for(int k=0; k<4; k++)
    {

        sum+=call(i+dx[k],j+dy[k]);
    }
    return sum;
}

main()
{
    int n,m,i,j,k,tc,t=1;
    while(scanf("%d%d",&m,&n)==2)
    {
        getchar();
        N=n;
        M=m;
        for(int i=0; i<n; i++)
            gets(a[i]);
        int count=0;
        int flag=0;
        for( i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(a[i][j]=='P')
                {
                    flag=1;
                    for(k=0; k<4; k++)
                        if(i+dx[k]>=0 && i+dx[k]<N && j+dy[k]>=0 && j+dy[k]<M && a[i+dx[k]][j+dy[k]]=='T')
                        {
                            k=0;
                            break;
                        }
                    k=call(i,j);
                    break;
                }
            }
            if(flag==1)
                break;
        }
        printf("%d\n",k);
    }
    return 0;
}
