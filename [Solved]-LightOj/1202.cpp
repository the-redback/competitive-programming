#include <stdio.h>
#include <stdlib.h>

main()
{
    long r1,r2,c1,c2,a,b,s;
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld %ld %ld %ld",&r1,&c1,&r2,&c2);
        a=abs(r1-c1);
        b=abs(r2-c2);
        printf("Case %d: ",i);
        if(a%2==b%2)
        {
            if(abs(r1-r2)==abs(c1-c2))
                printf("1\n");

            else
                printf("2\n");
        }
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}
