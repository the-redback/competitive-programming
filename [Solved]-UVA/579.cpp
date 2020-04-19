#include <cstdio>

main()
{
    double a,b,sum;
    while(scanf("%lf:%lf",&a,&b))
    {
        if(a==0 && b==0)
        {
            break;
        }
        b=b*5.5;
        a=a*30;
        if(a>b)
        {
            sum=a;
            a=b;
            b=sum;
        }
        sum=b-a;
        if(sum>180)
        {
            sum=360-sum;
        }
        printf("%.3lf\n",sum);
    }
    return 0;
}
