#include <stdio.h>

main()
{
    int i,j,test,a[1000],n,count,avg,sum;
    float xtra;
    scanf("%d",&test);
    for(i=0;i<test; i++)
    {
        sum=0;
        avg=0;
        count=0;
        xtra=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
            sum=sum+a[j];
        }
        avg=(sum/n);
        printf("%d\n",avg);
        for(j=0;j<n;j++)
        {
            if(a[j]>avg)
            {
                count++;
            }
        }
        xtra=float(count*100)/n;

        printf("%.3f%%\n",xtra);
    }
    return 0;
}
