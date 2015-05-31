#include <stdio.h>

main()
{
    int i,j,n,xtra,sum;
    for(i=0;i<10;i++)
    {
    scanf("%d",&n);
        sum=0;
        if(n==0)
        {
            break;
        }
        xtra = n%3;
        while(n>=3)
        {
            xtra=n%3;
            sum+=n/3;
            n=n/3+xtra;

        }
        if(n==2)
        {
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
