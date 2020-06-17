#include <stdio.h>

main()
{
    int i,a,b,c;

    while (scanf("%d%d%d",&a,&b,&c)!= EOF)
    {
        if(c>a && c>b)
        {
            if(c*c==a*a+b*b)
            {
                printf("right\n");
            }
            else
            {
                printf("wrong\n");
            }


        }
        else if(b>a)
        {
            if (b*b==a*a+c*c)
            {
                printf("right\n");
            }
            else
            {
                printf("wrong\n");
            }
        }
        else if(a>c)
        {
            if(a*a == b*b + c*c)
            {
                printf("right\n");
            }
            else
            {
                printf("wrong\n");
            }
        }
        if(a==0 && b==0 && c==0)
        {
            break;
        }

    }

    return 0;
}
