#include <stdio.h>
#include <math.h>
#include <stdlib.h>
main()
{
    double s,a,b,c,r;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        if(a==0 && b==0 && c==0)
        {
            r=0.000;
        }
        else
        {
            s=(a+b+c)/2.0;
            r=sqrt(s*(s-a)*(s-b)*(s-c));
            r=r/s;
        }
        printf("The radius of the round table is: %.3lf\n",r);

    }
    return 0;
}
