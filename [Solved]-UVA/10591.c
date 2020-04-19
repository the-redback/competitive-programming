#include <stdio.h>

main()
{
    int i,j,k,sum,test,m;
    long n,l;
    scanf("%d",&test);
    for(k=0;k<test;k++)
    {
        scanf("%ld",&l);
        n=l;
        sum=0;
        m=0;
        A:sum=0;
        while(n>0)
        {
            m=n%10;
            n=n/10;
            sum=sum+m*m;
        }
        if(sum<10)
        {
            if(sum==1)
            {
                printf("Case #%d: %ld is a Happy number.\n",k+1,l);
            }
            else
            {

            printf("Case #%d: %ld is an Unhappy number.\n",k+1,l);
            }
        }
        else
        {
            n=sum;
            goto A;
        }
    }
    return 0;
}
