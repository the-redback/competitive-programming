#include <stdio.h>

main()
{
    int a,i,j,k,n,t=1;
    while(scanf("%d",&n))
    {
        if(n==0)
        return 0;
        j=0;
        k=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(a==0)
            {
                j++;
            }
            else
            {
                k++;
            }
        }
        a=k-j;
        printf("Case %d: %d\n",t,a);
        t++;
    }
    return 0;
}
