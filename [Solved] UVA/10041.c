#include <stdio.h>

main()
{
    int t,n,i,j,k,sum,a[30001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
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
                    k=a[j];
                    a[j]=a[j+1];
                    a[j+1]=k;
                }
            }
        }
        k=n/2;
        sum=0;
        for(i=0;i<n;i++)
        {
            if(a[k]>a[i])
            {
                sum+=a[k]-a[i];
            }
            else
            {
                sum+=a[i]-a[k];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
