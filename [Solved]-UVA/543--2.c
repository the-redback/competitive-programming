#include <stdio.h>
#include <math.h>
int prim[1000000];
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

    for(i=3;i<1000000;i=i+2)
    {
        k=prime(i);
        if(k==1)
        {
            prim[i]=1;
        }
        else
        prim[i]=0;
    }
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        j=0;
        k=n/2;
        for(i=3;i<=k;i=i+2)
        {
            a=i;
            b=n-i;
            if(prim[a]==1 && prim[b]==1)
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
