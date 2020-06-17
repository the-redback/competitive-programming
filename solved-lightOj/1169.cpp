///=======================================//
///    Author     : Maruf Tuhin           //
///    School     : CUET CSE 11           //
///    TopCoder   : the_redback           //
///    Codeforces : maruf.2hin            //
///    UVA        : Redback               //
///    http://www.fb.com/maruf.2hin       //
///=======================================//
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 22550
#define inf 9999999

int dp[3][1010];
int mid,N;
int a[3][1010];
int b[3][1010];
int go(int row,int col)
{
    if(col==N)
    {
        return 0;
    }
    int &t=dp[row][col];
    if(t!=-1)
        return t;
    int ret=inf;
    if(row==0 && col<N-1)
    {
        ret=go(1,col+1)+a[row][col]+b[row][col];
    }
    else if(row==1 && col<N-1)
    {
        ret=go(0,col+1)+a[row][col]+b[row][col];
    }
    ret=min(ret,go(row,col+1)+a[row][col]);
    t=ret;
    return t;

}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,k=0,l,i,j;
        scanf("%d",&N);
        for(i=0;i<2;i++)
            for(j=0;j<N;j++)
                scanf("%d",&a[i][j]);
        for(i=0;i<2;i++)
            for(j=0;j<N-1;j++)
                scanf("%d",&b[i][j]);
        memset(dp,-1,sizeof(dp));
        int sum=go(0,0);
        sum=min(sum,go(1,0));
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
