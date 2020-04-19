#include <stdio.h>

main()
{
    int a,i,b,c,n,sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a>1 && b>=1 && c>=1)
        {
            sum=(b+c)%a;
            if(sum==0)
            {
                sum=a;
            }
            printf("Case %d: %d\n",i+1,sum);
        }
    }
    return 0;
}
