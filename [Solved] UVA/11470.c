#include <stdio.h>
#include <math.h>

main()
{
    int i,j,k=1,n,t,sum;
    int a[11][11];
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
        if(n%2!=0)
        t=i/2;
        else
        t=i/2-1;
        printf("Case %d:",k);
        for(i=0;i<=t;i++)
        {
            sum=0;
            for(j=0+i;j<n-i;j++)
                sum+=a[i][j];
            for(j=0+i+1;j<n-i;j++)
            {
                sum+=a[j][n-1-i];
                sum+=a[j][i];
            }
           for(j=0+i+1;j<n-i-1;j++)
                sum+=a[n-1-i][j];
            printf(" %d",sum);

        }
        printf("\n");
        k++;

    }
}
