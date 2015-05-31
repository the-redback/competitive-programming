#include <stdio.h>

main()
{
    int a,b,c,d,xtra,sum,count;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a==0 && b==0)
        {
            break;
        }
        count=0;
        xtra=0;
        while(a>0 || b>0)
        {
            sum=0;
            c=a%10;
            d=b%10;
            a=a/10;
            b=b/10;
            sum=c+d+xtra;
            if(sum>9)
            {
                xtra=sum/10;
                count++;
            }
            else
            xtra=0;
        }
        if(count==0)
        printf("No carry operation.\n");

        else if(count==1)
        printf("%d carry operation.\n",count);

        else if(count>1)
        printf("%d carry operations.\n",count);
    }
    return 0;
}
