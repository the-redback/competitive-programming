#include <stdio.h>

main()
{
    int a,b,n,t,i,j,k;
    scanf("%d",&t);
    k=0;
    while(t--)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        for(i=0;i<b;i++)
        {
            if(k!=0)
            {
                printf("\n");
            }
            for(j=1;j<=a;j++)
            {
                for(k=1;k<=j;k++)
                {
                    printf("%d",j);
                }
                printf("\n");
            }
            for(j=a-1;j>0;j--)
            {
                for(k=1;k<=j;k++)
                {
                    printf("%d",j);
                }
                printf("\n");
            }
        }

    }
    return 0;
}
