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
int dp[70000];
bool dc[70000];
int a[20][20];
int n;

int call(int pos,int r,int value)
{
    if(r==n)
    {
        return value;
    }
    int &t=dp[pos];
    bool &b=dc[pos];
    if(b)
        return t+value;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(!(pos&1<<i))
        {
            int k=call(pos|1<<i,r+1,value+a[r][i]);
            sum=max(sum,k);
        }
    }
    t=sum-value;
    b=1;
    return sum;
}


main()
{
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        memset(dc,0,sizeof(dc));
        int sum=call(0,0,0);
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
