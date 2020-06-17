#include <stdio.h>
#include <math.h>
main()
{
    int a,i,t;
    double sum,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&n);
        sum=((n+n)*(n+n))-(2*acos(0)*n*n);
        printf("Case %d: %.2lf\n",i,sum);
    }
    return 0;
}
