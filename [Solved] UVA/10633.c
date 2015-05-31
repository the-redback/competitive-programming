#include <stdio.h>

main()
{
    unsigned long long n,a,b;
    int i,j;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        if(n%9==0)
        {
            a=(n*10)/9;
            b=a-1;
            printf("%lld %lld\n",b,a);
        }
        else
        {
            a=(n*10)/9;
            printf("%lld\n",a);
        }

    }
    return 0;
}
