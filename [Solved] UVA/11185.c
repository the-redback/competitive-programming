#include <stdio.h>



main()
{
    int carry,i,j,k;
    long long n;
    int b[100];

    while(scanf("%lld",&n)!=EOF)
    {
        j=0;
        if(n<0)
        {
            break;
        }
        while(n!=0)
        {
            b[j]=n%3;
            n=n/3;
            j++;
        }
        if(j>0)
        {
            for(i=j-1;i>=0;i--)
            {
                printf("%d",b[i]);
            }
            printf("\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
