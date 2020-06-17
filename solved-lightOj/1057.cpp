#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
int dp[33000][20];
int dc[33000][20];
int aa[20];
int bb[20];
int N,X,Y;;
int go(int mask,int r,int v,int x,int y)
{
    if(mask==(1<<N)-1)
    {
        v+=max(abs(X-x),abs(Y-y));
        return v;
    }
    int &t=dp[mask][r];
    int &b=dc[mask][r];
    if(b)
        return t+v;
    int i,j=9999999;
    for(i=0; i<N; i++)
    {
        if(!(mask & 1<<i))
        {
            j=min(j,go(mask|1<<i,i+1,v+max(abs(aa[i]-x),abs(bb[i]-y)),aa[i],bb[i]));
        }
    }
    t=j-v;
    b=1;
    return j;
}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,m;
        N=0;
        int i,j,k=0,l;
        scanf("%d%d",&n,&m);
        getchar();
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                char ch=getchar();
                if(ch=='x')
                    X=i,Y=j;
                else if(ch=='g')
                    aa[k]=i,bb[k]=j,k++;
            }
            getchar();
        }
        N=k;
        memset(dc,0,sizeof(dc));
        printf("Case %d: %d\n",t++,go(0,0,0,X,Y));
    }
}
