#include <stdio.h>

main()
{
    int a[13],b[12];
    int i,j=0,sum,n;
    while(scanf("%d",&n)!=EOF)
    {
        j++;
        if(n<0)
        {
            break;
        }
        else
        {
            a[0]=n;
        }
        sum=0;
        for(i=1;i<13;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<12;i++)
        {
            scanf("%d",&b[i]);
        }
        printf("Case %d:\n",j);
        for(i=0;i<12;i++)
        {
            a[i]=a[i]+sum;
            if(a[i]>=b[i])
            {
                printf("No problem! :D\n");
                sum=a[i]-b[i];
            }
            else if(a[i]<b[i])
            {
                printf("No problem. :(\n");
                sum=a[i];
            }
        }
    }
}
