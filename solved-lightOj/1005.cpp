#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long fact[35];


main()
{
    int i,n,mx,mn,k,t,T;
    long long sum;
    fact[0]=1;
    for(i=1; i<=30; i++)
    {
        fact[i]=fact[i-1]*i;
    }
    sum=0;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        sum=0;
        scanf("%d %d",&n,&k);
        if(k>n)
        {
            printf("Case %d: 0\n",t);
        }
        else
        {
            mx=max(k,n-k);
            mn=min(k,n-k);
            sum=1;
            for(i=mx+1;i<=n;i++)
            {
                sum*=i;
            }
            if(sum!=0)
                sum=sum/fact[mn];
            for(i=n-k+1;i<=n;i++)
            {
                sum*=i;
            }
            printf("Case %d: %lld\n",t,sum);
        }
    }
    return 0;
}
