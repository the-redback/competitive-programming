#include <stdio.h>

main()
{
    int i,j,n,b,max,count,temp,lmt;
    while(scanf("%d%d",&b,&n)!=EOF)
    {
        lmt=-1;
        printf("%d %d ",b,n);
        max=0;
            if(b>n)
            {
                temp=b;
                b=n;
                n=temp;
            }
            for(i=b;i<=n;i++)
            {
                count=1;
                for(j=i;j>1; )
                {
                     if(j%2!=0)
                    {
                        j=(3*j)+1;
                    }
                    else if(j%2==0)
                    {
                        j=(j/2);
                    }
                    count++;
                }
                if(max<count)
                {
                    max=count;
                }
            }
            printf("%d\n",max);
        }
    return 0;
}
