#include <stdio.h>

main()
{
    int n,i,j;

    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        j=0;
        j=n%9;
        if(j==0)
        {
            j=9;
        }
        printf("%d\n",j);

    }

    return 0;
}
