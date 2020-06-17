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
#define inf 99999

int dp[1010][1010];
int dp2[1010][1010];
char a[1010],b[1010];
int  mid,ans,sum;
int N,K,S;
int LCS(int i,int j)
{
    if(i<0||j<0)
        return 0;
    int &t=dp2[i][j];
    if(t!=-1)
        return t;
    int ret=0;
    if(a[i]==b[j])
        ret=LCS(i-1,j-1)+1;
    else
    {
        ret=LCS(i,j-1);
        ret=max(ret,LCS(i-1,j));
    }
    t=ret;
    return t;
}

int go(int i,int j)
{
    if(i<0||j<0)
        return 0;
    int &t=dp[i][j];
    if(t!=-1)
        return t;
    int ret=0;
    if(a[i]==b[j])
    {
        if(LCS(i,j)==1)
            return 1;
        else
            ret=go(i-1,j-1);
    }
    else
    {
        int n=LCS(i-1,j);
        int m=LCS(i,j-1);
        if(n==m)
        {
            ret=(ret+go(i-1,j)%1000007)%1000007;
            ret=(ret+go(i,j-1)%1000007)%1000007;
            if(LCS(i,j)==LCS(i-1,j-1))
                ret=((ret-go(i-1,j-1))%1000007+1000007)%1000007;
        }
        else if(n>m)
            ret=go(i-1,j);
        else if(n<m)
            ret=go(i,j-1);
    }
    t=ret;
    return t;
}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,l,i,j;
        scanf("%s%s",&a,&b);
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        n=strlen(a);
        l=strlen(b);
        ans=go(n-1,l-1);
        if(ans==0)
            ans=1;
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
