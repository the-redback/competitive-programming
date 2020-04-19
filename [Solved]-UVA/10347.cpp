#include <stdio.h>
#include <math.h>

main()
{
    double a,b,c,sum;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3)
    {
        sum=(a+b+c)/2;
        sum=(sum*(sum-a)*(sum-b)*(sum-c));
        if(sum<=0)
        {
            sum=-1;
            printf("%.3lf\n",sum);
        }
        else
        {
            sum=sqrt(sum);
            sum=(4*sum)/3;
            printf("%.3lf\n",sum);
        }
    }
    return 0;
}
