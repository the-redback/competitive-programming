#include <stdio.h>
main()
{
    int test,i,sum,j,n,k,l;
    scanf("%d",&test);
    for(k=0;k<test;k++)
    {
        scanf("%d%d",&sum,&n);

        if(sum>=n && sum>=0 && n>=0)
        {
            for(i=0;i<sum;i++)
            {
                j=sum-i;
                if(j-i==n)
                {
                    printf("%d %d\n",j,i);
                    break;
                }
            }
            if(i==sum)
            {
             printf("impossible\n");
            }
        }
        else
        {
            printf("impossible\n");
        }
    }

    return 0;
}
