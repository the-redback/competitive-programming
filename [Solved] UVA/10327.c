#include <stdio.h>

main()
{
    int a[1000],n,i,j,count,temp;

    while(scanf("%d",&n)!=EOF)
    {
        count=0;
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
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    count++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",count);
    }
    return 0;
}
