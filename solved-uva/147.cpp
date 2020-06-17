#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
int a[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
int N;
long long dp[15][30010];
bool dc[15][30010];

long long call(int i,int rem)
{
    if(i==N)
    {
        if(rem==0)
            return 1;
        else
            return 0;
    }
    if(rem==0)
        return 1;
    if(dc[i][rem])
        return dp[i][rem];

    long long x=0,y=0;
    if(rem-a[i]>=0)
        x=call(i,rem-a[i]);
    y=call(i+1,rem);

    dc[i][rem]=1;
    return dp[i][rem]=x+y;
}

main()
{
    double d;
    long long k;
    int n,m;
    N=11;
    mem(dc,0);
    while(scanf("%d.%d",&n,&m))
    {
        if(n==0 && m==0)
            return 0;
        k=n*100+m;
        k=call(0,k);
        printf("%3d.%02d%17lld\n",n,m,k);
    }
    return 0;
}
