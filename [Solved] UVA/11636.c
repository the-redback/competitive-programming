#include <stdio.h>

main()
{
    int n,i=0,j,sum,count;

    while(scanf("%d",&n)!=EOF)
    {
        if(n<0)
        {
            break;
        }
        else if(n>0 && n<10001)
        {
        i++;
        count=0;
        for(sum=1;sum<n;j++)
        {
            sum=sum+sum;
            count++;
        }
        printf("Case %d: %d\n",i,count);
        }

    }
    return 0;
}
