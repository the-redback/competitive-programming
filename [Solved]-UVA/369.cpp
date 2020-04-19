/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @Codeforces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
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
#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))


long long ncr(int n,int r)
{
    int k,l;
    k=max(r,n-r);
    l=min(r,n-r);
    long long sum=1;
    long long i;
    int j=1;
    for(i=k+1;i<=n;i++)
    {
        sum=(long long)sum*i;
        if(j<=l && sum%j==0)
        {
            sum/=j;
            j++;
        }
    }
    return sum;
}

main()
{
    int n,k,l,r;
    int tc,t=1;
    //scanf("%d",&tc);
    while(~scanf("%d%d",&n,&r))
    {
        if(n==0 && r==0)
            return 0;
        long long sum=ncr(n,r);
        printf("%d things taken %d at a time is %lld exactly.\n",n,r,sum);
    }
    return 0;
}

