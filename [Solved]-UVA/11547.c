#include <stdio.h>

main()
{
    int test,n,i;
    unsigned int k;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        n=(((((n*567)/9)+7492)*235)/47)-498;

        n=(n/10);
        n=(n%10);
        if(n<0)
        {
            n=n*(-1);
            printf("%d\n",n);
        }
        else
        {
        printf("%d\n",n);
        }
    }
    return 0;
}
