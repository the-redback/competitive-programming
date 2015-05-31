#include <stdio.h>
#include <math.h>
int prime(int n)
{
    int i,j;
    j=sqrt(n);
    for(i=2;i<=j;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

main()
{
    int n,a,b,k,ai,bi,i,j;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        k=n/2;
        j=0;
        for(i=3;i<=k;i=i+2)
        {
            a=i;
            ai=prime(a);
            b=n-i;
            bi=prime(b);
            if(ai==1 && bi==1)
            {
                printf("%d = %d + %d\n",n,a,b);
                j=1;
                break;
            }
        }
        if(j==0)
        {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
    return 0;
}
