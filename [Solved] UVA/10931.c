#include <stdio.h>

main()
{
    int m,i,j,k,count;
    long n;
    int a[500];
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        count=0;
        j=0;
        while(n>0)
        {
            a[j]=n%2;
            if(a[j]==1)
            {
                count++;
            }
            n=n/2;
            j++;
        }
        printf("The parity of ");
        for(i=j-1;i>=0;i--)
        {
            printf("%d",a[i]);
        }
        printf(" is %d (mod 2).\n",count);
    }
    return 0;

}
