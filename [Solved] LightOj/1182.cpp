#include <stdio.h>
main()
{
    int i,t,count;
    long n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        count=0;
        scanf("%ld",&n);
        printf("Case %d: ",i);
        while(n>0)
        {
            if(n%2==1)
            {
                count++;
            }
            n=n/2;
        }
        if(count%2==0)
        {
            printf("even\n");
        }
        else
        {
            printf("odd\n");
        }
    }
    return 0;
}
