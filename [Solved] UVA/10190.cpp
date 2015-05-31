#include <stdio.h>
#include <math.h>

main()
{
    long long n,m;
    int i,k;
    while(scanf("%lld %lld",&n,&m)==2)
    {
        k=ceil(log10(n)/log10(m));
        i=0;

        if(pow(m,k)==n)
        {
            while(n>1)
            {
                if(i!=0)
                {
                    printf(" ");
                }
                printf("%lld",n);
                n=n/m;
                i=1;
            }
            if(i==1)
            {
                printf(" %lld\n",n);
            }
        }
        if(i==0)
        {
            printf("Boring!\n");
        }
    }
    return 0;
}
