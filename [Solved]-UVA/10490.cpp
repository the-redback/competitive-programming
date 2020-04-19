#include <stdio.h>
#include <math.h>

int prime(long long n)
{
    long long i;
    if(i==1)
    return 0;
    if(n==2)
    return 1;
    if(n%2==0)
    return 0;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}

main()
{
    long long p;
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
        return 0;

        p=pow(2,n)-1;
        if(prime(p)==1)
        {
            p*=pow(2,n-1);
            printf("Perfect: %lld!\n",p);
        }
        else
        {
            if(prime(n)==1)
            {
                printf("Given number is prime. But, NO perfect number is available.\n");
            }
            else
            {
                printf("Given number is NOT prime! NO perfect number is available.\n");
            }
        }
    }
    return 0;


}
