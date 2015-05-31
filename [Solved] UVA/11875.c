#include <stdio.h>

main()
{
    int test,i,j,k,n,a[11];
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        j=n/2;
        printf("Case %d: %d\n",i+1,a[j]);
    }
    return 0;
}
