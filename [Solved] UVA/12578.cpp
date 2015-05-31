#include <stdio.h>
#include <math.h>
main()
{
    double area,a,b,n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&n);
        a=n/5;
        a=acos(-1)*a*a;
        area=(n/10)*6;
        area=n*area;
        b=area-a;
        printf("%.2lf %.2lf\n",a,b);
    }
    return 0;
}
