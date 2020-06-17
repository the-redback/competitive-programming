/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @Codeforces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define MAX 1010
#define inf 99999

long long call(int n,int k,int l)
{
    long long sum=1;
    long long i;
    int j=1;
    for(i=k+1;i<=n;i++)
    {
        sum*=i;
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
    int tc,n;
    long long sum;
    int k,l;
    scanf("%d",&tc);
    while(tc--)
    {
        int i,j;
        scanf("%d%d",&n,&k);
        l=(n-1)-(k-1);
        if(n==k)
            sum=1;
        else if(l>(k-1))
            sum=call(n-1,l,k-1);
        else
            sum=call(n-1,k-1,l);
        printf("%lld\n",sum);
    }
    return 0;
}
