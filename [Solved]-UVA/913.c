#include <stdio.h>

main()
{
    long long n,m;
    unsigned long long sum,total;
    while(scanf("%lld",&n)!=EOF)
    {
        m=n/2;
        sum=m+((m+1)*n);
        total=sum+(sum-2)+(sum-4);
        printf("%lld\n",total);
    }
    return 0;
}
