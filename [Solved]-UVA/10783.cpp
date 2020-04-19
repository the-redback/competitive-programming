#include <stdio.h>

main()
{
    int i,n,a,b,j,count;

    scanf("%d",&n);

    for (i=0; i<n ; i++)
    {
        count=0;
        scanf("%d%d",&a,&b);

        for(j=a;j<=b;j++)
        {
            if(j%2 != 0)
            {
                count=count+j;
            }
        }
        printf("Case %d: %d\n",i+1,count);
    }
    return 0;
}
