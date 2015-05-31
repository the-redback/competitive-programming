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
int a[100][100];

main()
{
    queue<int>q;
    char ch[10];
    int tc;
    int t=1,i,j,k,l,m,n;
    cin>>tc;
    getchar();
    getchar();
    while(tc--)
    {
        memset(a,0,sizeof(a));
        gets(ch);
        l=ch[0]-'A';
        for(i=0;i<=l;i++)
            a[i][i]=1;
        while(gets(ch))
        {
            if(strlen(ch)==0)
                break;
            n=ch[0]-'A';
            m=ch[1]-'A';
            a[n][m]=1;
            a[m][n]=1;
        }
        int count=0;
        for(j=0;j<=l;j++)
        {
            q.push(j);
            int flag=0;
            while(!q.empty())
            {
                int p=q.front();
                q.pop();
                for(i=0;i<=l;i++)
                    if(a[p][i]==1)
                    {
                        q.push(i);
                        a[p][i]=0;
                        a[i][p]=0;
                        flag=1;
                    }
            }
            if(flag==1)
                count++;
        }
        if(t!=1)
            puts("");
        t++;
        printf("%d\n",count);
    }
    return 0;
}
