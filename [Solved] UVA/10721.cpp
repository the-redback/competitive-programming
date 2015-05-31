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

long long dp[60][60];
int N,K,V;
long long go(int pos,int value)
{
    if(pos==N)
    {
        if(value==V)
            return 1;
        else
            return 0;
    }
    long long &t=dp[pos][value];
    if(t!=-1)
        return t;
    long long ret=0;
    int i;
    for(i=1; i<=K; i++)
    {
        if(value+i<=V)
            ret+=go(pos+1,value+i);
    }
    t=ret;
    return ret;
}

main()
{
    while(~scanf("%d%d%d",&V,&N,&K))
    {
        memset(dp,-1,sizeof(dp));
        long long ret=go(0,0);
        printf("%lld\n",ret);
    }
    return 0;
}
