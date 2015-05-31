#include <stdio.h>
int check(int n)
{
    int i,j,count=1;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            j=n/i;
            if(i==j)
            count+=i;

            else
            count+=i+j;
        }
    }
    return count;
}

main()
{
    int n,i,j;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            printf("END OF OUTPUT\n");
            return 0;
        }
        printf("%5d  ",n);
        i=check(n);
        if(i==n && n!=1)
        {
            printf("PERFECT\n");
        }
        else if(i>n)
        {
            printf("ABUNDANT\n");
        }
        else
        {
            printf("DEFICIENT\n");
        }
    }
    return 0;
}
