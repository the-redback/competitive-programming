#include <stdio.h>

main()
{
    int n,p,sum,t,i,k,pi,a[3656];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&p);
        for(i=1;i<=n;i++)
        {
            a[i]=0;
        }
        while(p--)
        {
            scanf("%d",&pi);
            i=1;
            k=pi*i;
            while(k<=n)
            {
                if(k%7!=6 && k%7!=0)
                {
                    a[k]=1;
                }
                i++;
                k=pi*i;
            }
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
