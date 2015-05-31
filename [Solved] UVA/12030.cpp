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
long long dp[40000][5];
bool dc[40000][5];
int a[20][20];
int ret,n;
long long call(int pos,int r,int flag)
{
    if(r==n)
    {
        if(flag)
            return 1;
        else
            return 0;
    }
    long long &t=dp[pos][flag];
    if(dc[pos][flag])
        return t;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        if(!(pos & 1<<i))
        {
            if(flag==1 && a[r][i]==1)
                sum+=call(pos|1<<i,r+1,1);
            else if(flag==2 || a[r][i]==2)
                sum+=call(pos|1<<i,r+1,2);
            else
                sum+=call(pos|1<<i,r+1,0);
        }
    }
    t=sum;
    dc[pos][flag]=1;
    return t;
}

main()
{
    int tc,t,i,j,k,l;
    long long sum;
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        memset(dc,0,sizeof(dc));
        ret=0;
        sum=call(0,0,1);
        printf("Case %d: %lld\n",t,sum);
    }
    return 0;
}
