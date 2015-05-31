#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
int dp[25][1010];
bool dc[25][1010];
int a[25];
int N,sum;
bool call(int i,int rem)
{
    if(rem==sum)
        return 1;
    if(i==N)
        return 0;
    if(dc[i][rem])
        return dp[i][rem];
    bool x=0,y=0;
    if(rem+a[i]<=sum)
        x=call(i+1,rem+a[i]);
    y=call(i+1,rem);

    dc[i][rem]=1;
    dp[i][rem]=x|y;
    return dp[i][rem];
}

main()
{
    int i,k,n;
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        mem(dc,0);
        scanf("%d%d",&sum,&N);
        for(i=0;i<N;i++)
            scanf("%d",&a[i]);
        k=call(0,0);
        if(k==1)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
