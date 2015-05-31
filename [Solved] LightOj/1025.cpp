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
#define MAX 50001
#define inf 999999

long long dp[70][70];
int I,J,K,L,N;
char a[70];
long long go(int i,int j)
{
    if(i>j)
    {
        return 0;
    }
    long long &t=dp[i][j];
    if(t!=-1)
        return t;
    long long ret=0;
    ret=go(i+1,j);
    ret+=go(i,j-1);
    ret-=go(i+1,j-1);
    if(a[i]==a[j])
        ret+=go(i+1,j-1)+1;
    t=ret;
    return t;
}

main()
{
    int t=1,tc;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        memset(dp,-1,sizeof(dp));
        int n,k,l,i;
        gets(a);
        l=strlen(a);
        long long sum=go(0,l-1);
        printf("Case %d: %lld\n",t++,sum);
    }
    return 0;
}
