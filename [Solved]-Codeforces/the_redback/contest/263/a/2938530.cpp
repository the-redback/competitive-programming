#include <stdio.h>
main()
{
    int n,i,j,k,r,c;
    for (i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            scanf("%d",&k);
            if(k==1)
            {
                r=i,c=j;
            }

        }
    }
    if(r>=3)
    {
        n=r-3;
    }
    else
    {
        n=3-r;
    }
    if(c>=3)
    {
        n+=c-3;
    }
    else
    {
        n+=3-c;
    }
    printf("%d\n",n);
    return 0;
}
