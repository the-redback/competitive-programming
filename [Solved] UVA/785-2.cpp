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
char a[50][90];
bool b[50][90];
int N;
char C;
void call(int i,int j,char ch)
{
     int M=strlen(a[i]);
    if(i<0||j<0||i>=N||j>=M)
        return;
    if(a[i][j]==C || b[i][j]==1)
        return;
    a[i][j]=ch;
    b[i][j]=1;
    for(int k=0; k<4; k++)
    {
        call(i+dx[k],j+dy[k],ch);
    }
    return;
}

main()
{
    //freopen("C:\\Users\\MARUF\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\MARUF\\Desktop\\out.txt","w",stdout);
    int n,m,i,j,k,tc,t=1;
    while(gets(a[0]))
    {
        i=1;
        while(gets(a[i]))
        {
            if(a[i][0]=='_')
                break;
            i++;
        }
        N=i;
        int flag=0;
        memset(b,0,sizeof(b));
        for( i=0; i<N; i++)
        {
            m=strlen(a[i]);
            for(j=0; j<m; j++)
            {
                if(a[i][j]!=' ' && a[i][j]!='_' && flag==0)
                {
                    C=a[i][j];
                    flag=1;
                }
                else if(a[i][j]!=C && a[i][j]!=' ' &&flag==1)
                {
                    call(i,j,a[i][j]);
                }
            }
        }
        for(i=0;i<=N;i++)
            puts(a[i]);
    }
    return 0;
}
