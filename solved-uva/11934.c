#include <stdio.h>

main()
{
    int a,b,c,d,l,i,j,count,sum,n;
    while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&l)!=EOF)
    {
        if(a==0 && b==0 && c==0 && d==0 && l==0)
        {
            break;
        }
        count=0;
        for(i=0;i<=l;i++)
        {
            sum=a*i*i+b*i+c;
            n=sum/d;
            if(n*d == sum)
            {
                count++;
            }
        }

        printf("%d\n",count);
    }
    return 0;
}
