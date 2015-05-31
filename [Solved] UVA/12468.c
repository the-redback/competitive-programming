#include <stdio.h>

main()
{
    int n,m,sum,temp;
    while(scanf("%d%d",&n,&m))
    {
        if(n<0 && m<0)
        {
            break;
        }
        if(n>m)
        {
            temp=n;
            n=m;
            m=temp;
        }
        sum=m-n;
        if(sum>50)
        {
            sum=100-sum;
        }
        printf("%d\n",sum);
    }
    return 0;
}
