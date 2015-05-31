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
int dx[]= {-1,-1,-1,0,0,1,1,1};
int dy[]= {-1,0,1,-1,1,-1,0,1};

main()
{
    char a[100][100],b[100][100];
    int n,m,tc,t=1;
    cin>>tc;
    while(tc--)
    {
        scanf("%d",&n);
        getchar();
        for(int i=0; i<n; i++)
            gets(a[i]);
        for(int i=0; i<n; i++)
            gets(b[i]);
        int flag=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(b[i][j]=='x'&& a[i][j]!='*')
                {
                    int count=0;
                    for(int k=0; k<8; k++)
                    {
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(x>=0 && y>=0 && x<n && y<n && a[x][y]=='*')
                            count++;
                    }
                    b[i][j]=count+'0';
                }
                else if(b[i][j]=='x' && a[i][j]=='*')
                    flag=1;
            }
        }
        if(flag==1)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(a[i][j]=='*')
                        b[i][j]='*';
        }
        if(t!=1)
            puts("");
        t++;
        for(int i=0; i<n; i++)
        {
            puts(b[i]);
        }
    }
    return 0;
}
