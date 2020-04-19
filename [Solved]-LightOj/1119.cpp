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
#define inf 9999999
int dp[16385];
bool taken[16385];
int arr[20][20];
int N;

int go(int mask,int v)
{
    if(mask==(1<<N)-1)
    {
        return v;
    }
    int &t=dp[mask];
    bool &b=taken[mask];
    if(b)
        return t+v;
    int sum=inf;
    int i,k;
    for(i=0; i<N; i++)
    {
        if(!(mask&1<<i))
        {
            k=0;
            for(int j=0; j<N; j++)
                if(mask&1<<j)
                    k+=arr[i][j];
            sum=min(sum,go(mask|1<<i,v+k+arr[i][i]));
        }
    }
    b=1;
    t=sum-v;
    return sum;
}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        memset(taken,0,sizeof(taken));
        int sum=go(0,0);
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
