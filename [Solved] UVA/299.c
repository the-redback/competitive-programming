#include <stdio.h>

main()
{
    int a[51],count,l,test,i,j,m;
    int n;
    scanf("%d",&test);
    for(l=0;l<test;l++)
    {
        count=0;
        scanf("%d",&n);
        if(n>=0 && n<=50)
        {


            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
            for(i=0;i<n-1;i++)
            {
                for(j=0;j<n-1-i;j++)
                {
                    if(a[j]>a[j+1])
                    {
                        m=a[j];
                        a[j]=a[j+1];
                        a[j+1]=m;
                        count++;
                    }
                }

            }
            printf("Optimal train swapping takes %d swaps.\n",count);
        }

    }
    return 0;
}
