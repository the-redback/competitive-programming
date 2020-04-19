#include <stdio.h>

main()
{
    int sum,n,m,j,i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d %d",&n,&m);
        if(n>m)
        {
            j=n-m;
        }
        else
        {
            j=m-n;
        }
        sum+=(j*4)+n*4;
        sum+=19;

        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
