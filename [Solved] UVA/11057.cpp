#include <stdio.h>
#include  <algorithm>

main()
{
    int a[10001];
    int i,j,n,t,m,path,max,min;
    while(scanf("%d",&t)==1)
    {
        for(i=0;i<t;i++)
        scanf("%d",&a[i]);

        scanf("%d",&m);
        std::sort(a,a+t);
        min=i=0;
        max=j=t-1;
        path=a[j]-a[i];
        while(1)
        {
            while(a[i]+a[j]>m)
            {
                j--;
            }
            while(a[i]+a[j]<m)
            {
                i++;
            }
            if(a[i]+a[j]==m && (a[j]-a[i]<=path) && i!=j)
            {
                max=j;
                min=i;
                path=a[j]-a[i];
                i++;
            }
            if(j<=i)
            break;
        }
        if(max<min)
        {
            i=max;
            max=min;
            min=i;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",a[min],a[max]);
    }
}
