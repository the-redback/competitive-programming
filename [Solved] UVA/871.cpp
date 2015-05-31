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
int dx[]= {-1,0,0,1,-1,-1,1,1};
int dy[]= {0,-1,1,0,-1,1,-1,1};
char a[50][50];
int N,M;
int call(int i,int j)
{
    int sum=0;
    if(i<0||j<0||i>=N||j>=M)
        return 0;
    if(a[i][j]=='0')
        return 0;
    sum=1;
    a[i][j]='0';
    for(int k=0; k<8; k++)
    {

        sum+=call(i+dx[k],j+dy[k]);
    }
    return sum;
}

main()
{
    int n,m,i,j,k,tc,t=1;
    cin>>tc;
    getchar();
    getchar();
    while(tc--)
    {
        N=n;
        M=m;
        i=0;
        while(gets(a[i]))
        {
            if(strlen(a[i])==0)
                break;
            i++;
        }
        N=i;
        M=strlen(a[0]);
        int mx=0;
        for( i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                if(a[i][j]=='1')
                {
                    k=call(i,j);
                    if(k>mx)
                        mx=k;
                }
            }
        }
        if(t!=1)
            puts("");
        t++;
        printf("%d\n",mx);
    }
    return 0;
}
