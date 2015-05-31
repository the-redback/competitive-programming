#include <stdio.h>
#include <stdlib.h>
main()
{
    int a[3005],b[3005],max,i,j,k,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=0;
        }
        max=0;
        for(i=0;i<n-1;i++)
        {

            j=abs(a[i+1]-a[i]);
            b[j]++;
        }
        m=1;
        for(i=1;i<n;i++)
        {
            if(b[i]!=1)
            break;
        }
        if( i==n )
        {
            printf("Jolly\n");
        }
        else
        {
            printf("Not jolly\n");
        }
    }
    return 0;
}
