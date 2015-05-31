#include <stdio.h>

main()
{
    int n,sum,k, a[100],i,j,m;
    m=1;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        if(n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        j=sum/n;
        k=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>j)
            {
                k+=a[i]-j;

            }
        }
        printf("Set #%d\n",m);
        printf("The minimum number of moves is %d.\n\n",k);
        m++;

    }
}
