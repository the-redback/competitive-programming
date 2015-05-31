#include <stdio.h>

main()
{
    int i,j,k,sum,test,m;
    long n,l;
    scanf("%d",&test);
    for(k=0;k<test;k++)
    {
        scanf("%ld",&l);
        if(l>9)
        {
            sum=l;
        }
        else
        {
            sum=l*l;
        }
        m=0;
        while(sum>9)
        {
            n=sum;
            sum=0;
            while(n>0)
            {
                m=n%10;
                n=n/10;
                sum=sum+m*m;
                //printf("%d ",sum);
            }
        }
                if(sum==1)
                {
                    printf("Case #%d: %ld is a Happy number.\n",k+1,l);
                }
                else
                {

                    printf("Case #%d: %ld is an Unhappy number.\n",k+1,l);
                }
    }

    return 0;
}
