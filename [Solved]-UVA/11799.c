#include <stdio.h>

main()
{
    int sum,i=1,n,t,p;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&p);
            if(p>sum)
            {
                sum=p;
            }
        }
        printf("Case %d: %d\n",i,sum);
        i++;
    }
    return 0;
}
