#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int a[111];
int N,K;
int dp[111][50010];
bool dc[111][50010];

int call(int i,int rem )
{
    if(i==N)
        return rem;
    if(dc[i][rem])
        return dp[i][rem];
    int x=0,y=0;
    if(a[i]+rem<=K)
        x=call(i+1,a[i]+rem);
    y=call(i+1,rem);
    dc[i][rem]=1;
    return dp[i][rem]=max(x,y);
}


main()
{
    int i,sum,k,l,n,t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dc,0,sizeof(dc));
        sum=0;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        K=ceil(sum/2.0);
        k=call(0,0);
        K=sum-k;
        printf("%d\n",abs(k-K));
    }
}
