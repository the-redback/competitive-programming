#include <stdio.h>

long f91(long n)
{
    if(n<=100)
    {
        return f91(f91(n+11));
    }
    if(n>=101)
    {
        return n-10;
    }
}

main()
{
    long n,m;

    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        m=f91(n);
        printf("f91(%ld) = %ld\n",n,m);
    }
    return 0;
}
