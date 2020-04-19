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
char a[35][85];
bool b[35][85];
int N,M;
char C;
void call(int i,int j)
{
    int r,c;
    if(i<0||j<0||i>=N||j>=M)
        return;
    if(a[i][j]==C||b[i][j])
        return;
    b[i][j]=1;
    for(int k=0; k<4; k++)
    {
        r=i+dx[k];
        c=j+dy[k];
        if(r>=0 && c>=0 && r<N && c<M && a[r][c]==C)
            a[i][j]='#';
    }
    for(int k=0; k<4; k++)
    {
        call(i+dx[k],j+dy[k]);
    }
    return;
}

main()
{
  //  freopen("C:\\Users\\MARUF\\Desktop\\in.txt","r",stdin);
  //  freopen("C:\\Users\\MARUF\\Desktop\\out.txt","w",stdout);
    int n,m,i,j,k,tc,t=1;
    cin>>tc;
    getchar();
    while(tc--)
    {
        i=0;
        int l=0;
        memset(a,0,sizeof(a));
        while(gets(a[i]))
        {
            if(a[i][0]=='_')
                break;
            if(l<strlen(a[i]))
                l=strlen(a[i]);
            i++;
        }
        N=i;
        M=l+1;
        int flag=0,fl=0;
        int r,c;
        for( i=0; i<N; i++)
        {
            m=strlen(a[i]);
            for(j=0; j<m; j++)
            {
                if( flag==0 && a[i][j]!=' ' && a[i][j]!='*' && a[i][j]!='#')
                {
                    C=a[i][j];
                    flag=1;
                }
                else if(a[i][j]=='*')
                {
                    a[i][j]=' ';
                    fl=1;
                    r=i;
                    c=j;
                }
                if(flag==1 && fl==1)
                    break;
            }
            if(flag==1 && fl==1)
                break;
        }
        memset(b,0,sizeof(b));
        call(r,c);
        for(i=0; i<N; i++)
        {
            flag=0;
            for(j=M-1; j>=0; j--)
            {
                if(flag==0 && a[i][j]!=0 &&a[i][j]!=' ')
                    flag=1;
                else if(flag==1 &&a[i][j]==0)
                    a[i][j]=' ';
                else if(flag==0 && a[i][j]==' ')
                    a[i][j]=0;
            }
        }
        for(i=0; i<=N; i++)
            puts(a[i]);
    }
    return 0;
}
