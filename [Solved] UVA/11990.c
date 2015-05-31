#include <stdio.h>

main()
{
    int t,n,k,l,p,q,a[31],i,j,sum,count;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d %d %d",&n,&p,&q);
        sum=0;count=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            k=sum+a[i];
            l=count+1;
            if(k<=q && l<=p)
            {
                sum+=a[i];
                count++;
            }
        }
        for(i=0;i<n;i++)
        {

        }
        printf("Case %d: %d\n",j,count);
    }
    return 0;
}
