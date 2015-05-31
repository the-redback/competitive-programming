#include <stdio.h>

main()
{
    int t;
    long long last,i,n,j,sum;
    scanf("%d",&t);
    while(t--)
    {
        j=0;
        scanf("%lld",&n);
        if(n<=0)
        sum=0;
        else if(n==2)
        sum=3;
        else if(n==3)
        sum=5;
        else
        {
            sum=n;
            last=n;
            for(i=2;i*i<=n;i++)
            {
                j=n/i;
                sum+=j;
                sum+=(last-j)*(i-1);
                last=j;
            }
            if(j==i)
            {
                sum+=(i-1);
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
