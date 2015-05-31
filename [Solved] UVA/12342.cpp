#include <cstdio>
#include <stdlib.h>
#include <math.h>
using namespace std;
main()
{
    int i,t;
    long sum,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
       scanf("%ld",&n);
       n=n-180000;
       if(n>0)
        {
            if(n<300000)
                sum+=ceil((double)n*.10);
            else
                sum+=30000;
            n=n-300000;
            if(n>0)
            {
                if(n<400000)
                    sum+=ceil((double)n*.15);
                else
                    sum+=60000;
                n=n-400000;
                if(n>0)
                {
                    if(n<300000)
                        sum+=ceil((double)n*.20);
                    else
                        sum+=60000;
                    n=n-300000;
                    if(n>0)
                    {
                        sum+=ceil((double)n*.25);
                    }
                }
            }
        }
        if(sum>0 && sum<2000)
            sum=2000;
        printf("Case %d: %ld\n",i,sum);
    }
    return 0;
}
