#include <stdio.h>

main()
{
    int a,b,c,xtra,sum;

    while(scanf("%d%d",&a,&b)!=EOF)
    {
        sum=a;
        xtra=0;
        while(a>=b)
        {
            xtra=a%b;
            sum+=a/b;
            a=a/b;
            a=a+xtra;
        }
        printf("%d\n",sum);
    }
    return 0;
}
