#include <stdio.h>

int fib(int n)
{
    int x[n+1],i;
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

        n=fib(n);
        printf("%d\n",n);
    }
    return 0;
}

