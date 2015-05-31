#include <stdio.h>

main()
{
    int i,j,a,b,k,n,test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        if(n>10)
        {
            a=n-10;
            printf("%d 10\n",a);
        }
        else
        {
            printf("0 %d\n",n);
        }
    }
    return 0;
}
