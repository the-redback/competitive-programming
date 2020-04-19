#include <stdio.h>
#include <algorithm>

main()
{
    int a[18];
    long long b[40],sum;
    int i,j,last,k=0,n;
    while(scanf("%d",&n)==1)
    {
        k++;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);

        j=0;
        sum=1;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                sum=1;
            }
            else
            {
                sum*=a[i];
                if(sum>0)
                {
                    b[j]=sum;
                    j++;
                }

            }
        }
        sum=1;
        for(i=n-1;i>=0;i--)
        {
            if(a[i]==0)
            {
                sum=1;
            }
            else
            {
                sum*=a[i];
                if(sum>0)
                {
                    b[j]=sum;
                    j++;
                }

            }
        }
        sum=1;
        if(j==0)
        {
            printf("Case #%d: The maximum product is 0.\n\n",k);
        }
        else
        {
            std::sort(b,b+j);
            j--;
            printf("Case #%d: The maximum product is %lld.\n\n",k,b[j]);
        }
    }
    return 0;
}
