#include <stdio.h>
#include <math.h>
main()
{
    int t,n,sum,i,j,k,a[41];
    scanf("%d",&t);
    while(t--)
    {
        i=0;
        while(scanf("%d",&a[i]))
        {
            if(a[i]==0)
            {
                break;
            }
            i++;

        }
        i++;
        n=i;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(a[j]<a[j+1])
                {
                    k=a[j];
                    a[j]=a[j+1];
                    a[j+1]=k;
                }
            }
        }
        sum=0;
        k=0;
        for(i=1,j=0;j<n;j++)
        {
            k+=(2*pow(a[j],i));
            if(k<=5000000)
            {
                sum=k;
            }
            else
            break;
            i++;
        }
        if(j==n)
        {
            printf("%d\n",sum);
        }
        else
        {
            printf("Too expensive\n");
        }
    }
    return 0;
}
