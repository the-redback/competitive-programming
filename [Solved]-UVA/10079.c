#include <stdio.h>

main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n<0)
        {
            break;
        }
        if(n%2==0)
        {
            printf("%lld\n",((n*n)/2)+n/2+1);
        }
        else
        {
            printf("%lld\n",((n*n)/2)+n/2+2);
        }

    }
    return 0;
}
