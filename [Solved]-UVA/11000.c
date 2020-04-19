#include <stdio.h>

long long int fib( int n)
{
    long long x[n+1],i;
    x[0]=1;
    x[1]=1;
    for(i=2;i<=n;i++)
    {
        x[i]=x[i-1]+x[i-2];
    }
    return x[n];
}

main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)
        {
            break;
        }
        printf("%lld %lld\n",fib(n+1)-1,fib(n+2)-1);
    }
    return 0;
}
