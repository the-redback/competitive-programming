#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
char a[100][100];
int visit[20][20];
int N,xx,yy;
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};


int bfs(int p,int q,char ch)
{
    int i,j,k;
    queue<int>x;
    queue<int>y;
    x.push(p);
    y.push(q);
    memset(visit,-1,sizeof(visit));
    visit[p][q]=0;
    while(x.size())
    {
        p=x.front();
        q=y.front();
        x.pop();
        y.pop();
        for(i=0;i<4;i++)
        {
            k=dx[i]+p;
            j=dy[i]+q;
            if(k>=0 && j>=0 && k<N && j<N && visit[k][j]==-1 && a[k][j]!='#')
            {
                if(a[k][j]==ch)
                {
                    xx=k;
                    yy=j;
                    visit[k][j]=visit[p][q]+1;
                    a[k][j]='.';
                    return visit[k][j];
                }
                else if(a[k][j]<'A' || a[k][j]>'Z')
                {
                    x.push(k);
                    y.push(j);
                    visit[k][j]=visit[p][q]+1;
                }
            }
        }
    }
    return -1;
}
main()
{
    int i,j,k,n;
    int sum,flag;
    int tc,t;
    char c;
    cin>>tc;
    for(t=1; t<=tc; t++)
    {
        scanf("%d",&N);
        for(i=0; i<N; i++)
            scanf("%s",&a[i]);
        c='A';
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                if(a[i][j]=='A')
                {
                    xx=i;
                    yy=j;
                }
                else if(a[i][j]>='A'&&a[i][j]<='Z')
                    c=max(c,a[i][j]);
            }
        }
        char ch='A';
        sum=0;
        flag=0;
        a[xx][yy]='.';
        for(ch='B';ch<=c;ch++)
        {
            k=bfs(xx,yy,ch);
            if(k==-1)
            {
                flag=1;
                break;
            }
            sum+=k;
        }
        if(flag)
            printf("Case %d: Impossible\n",t);
        else
            printf("Case %d: %d\n",t,sum);
    }
    return 0;
}
