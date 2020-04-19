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
char a[100][100];
int N,M;
void call(int i,int j)
{
    M=strlen(a[i]);
    if(i<0||j<0||i>=N||j>=M)
        return;
    if(a[i][j]!=' '&&a[i][j]!='*')
        return;
    a[i][j]='#';
    for(int k=0; k<8; k++)
    {
        call(i+dx[k],j+dy[k]);
    }
    return;
}

main()
{
    int n,m,i,j,k,tc,t=1;
    cin>>tc;
    getchar();
    while(tc--)
    {
        i=0;
        while(gets(a[i]))
        {
            if(a[i][0]=='_')
                break;
            i++;
        }
        N=i;
        for( i=0; i<N; i++)
        {
            M=strlen(a[i]);
            for(j=0; j<M; j++)
            {
                if(a[i][j]=='*')
                {
                    call(i,j);
                }
            }
        }
        for(i=0;i<=N;i++)
            puts(a[i]);
    }
    return 0;
}
