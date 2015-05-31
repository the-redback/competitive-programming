#include <stdio.h>

main()
{
    int t,n,i,a;
    long long sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&a);
            if(a>0)
            {
                sum+=a;
            }
        }
        printf("Case %d: %lld\n",i,sum);
    }
    return 0;
}
