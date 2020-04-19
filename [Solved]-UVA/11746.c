#include <stdio.h>

main()
{
    int test,a[50],i,j,n,high,low;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        high=0;
        low=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(j=0;j<n-1;j++)
        {
            if(a[j+1]>a[j])
            {
                high++;
            }
            else if(a[j+1]<a[j])
            {
                low++;
            }

        }
        printf("Case %d: %d %d\n",i+1,high,low);
    }
    return 0;
}
