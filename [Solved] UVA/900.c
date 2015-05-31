#include <stdio.h>

int fib(int n)
{
    if(n<=1)
    {
        return 1;
    }
    else
    return fib(n-1)+fib(n-2);
}

main()
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        n=fib(n);
        printf("%d\n",n);
    }
    return 0;
}
