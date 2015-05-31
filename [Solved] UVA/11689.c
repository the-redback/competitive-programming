#include <stdio.h>

main()
{
    int a,b,c,d,sum,n,i,xtra;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        sum=0;
        d=a+b;
        xtra=0;
        while(d>=c)
        {
            xtra=d%c;
            sum=sum+(d/c);
            d=(d/c);
            d=d+xtra;
        }
        printf("%d\n",sum);
    }
    return 0;
}
