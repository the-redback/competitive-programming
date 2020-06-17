/**
 *    @author     : Maruf Tuhin
 *    @College    : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX 111
#define inf 9999999

int dp[111][MAX][MAX];
int I,J,K,L,N;
int a[111];
int go(int pos,int left,int right)
{
    if(pos>N)
    {
            return 0;
    }
    int &t=dp[pos][left][right];
    if(t!=-1)
        return t;
    int ret=0;
    if(a[pos]>=a[left] && a[pos]<=a[right])
    {
        ret=go(pos+1,pos,right)+1;
        ret=max(ret,go(pos+1,left,pos)+1);
    }
    ret=max(ret,go(pos+1,left,right));
    t=ret;
    return t;
}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    a[105]=inf;
    a[0]=0;
    while(tc--)
    {
        int n,k,l,i;
        scanf("%d",&N);
        for(i=1;i<=N;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,-1,sizeof(dp));
        int sum=go(1,0,105);
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
