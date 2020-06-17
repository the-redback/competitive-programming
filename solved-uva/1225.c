#include <stdio.h>

main()
{
    int i,j,k,n,t;
    int a[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<10;i++)
        {
            a[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            j=i;
            while(j>9)
            {
                k=j%10;
                j=j/10;
                a[k]++;
            }
            a[j]++;
        }
        for(i=0;i<10;i++)
        {
            printf("%d",a[i]);
            if(i!=9)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
