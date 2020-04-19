#include <stdio.h>

main()
{
    long low,max,count,bi,bcount,i,j;
    while(scanf("%ld%ld",&low,&max))
    {
        if(low==0 && max==0)
        {
            break;
        }
        if(low>max)
        {
            bi=low;
            low=max;
            max=bi;
        }
        bi=0;
        bcount=0;
        for(j=low;j<=max;j++)
        {
            i=j;
            count=0;
            do
            {
                if(i%2==0)
                {
                    i=i/2;
                }
                else
                {
                    i=(3*i)+1;
                }
                count++;
            }while(i!=1);
            if(count>bcount)
            {
                bcount=count;
                bi=j;
            }
            printf("%ld\n",count);
        }
        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",low,max,bi,bcount);
    }
    return 0;
}
