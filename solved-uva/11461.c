#include <stdio.h>
#include <math.h>

main()
{
    int a,b,i,count,c,d;

    while(scanf("%d%d",&a,&b)!=EOF)
    {
        count=0;
        c=0;
        if(a==0 && b==0)
        {
            break;
        }
        else
        {


        for(i=a;i<=b;i++)
        {
            c=sqrt(i);
            c=c*c;
            if(i==c)
            {
                count++;
            }
        }
        printf("%d\n",count);
        }
    }
    return 0;

}
