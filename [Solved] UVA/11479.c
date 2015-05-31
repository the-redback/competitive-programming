#include <stdio.h>

main()
{
    int i,n;
    long a,b,c;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%ld%ld%ld",&a,&b,&c);

        if(c>=a+b || b>=a+c || a>=b+c)
        {
            printf("Case %d: Invalid\n",i+1);
        }
        else if(a==b && b==c)
        {
            printf("Case %d: Equilateral\n",i+1);
        }
        else if(a==b || b==c || c==a )
        {
              printf("Case %d: Isosceles\n",i+1);
        }
        else if(a!=b && b!=c && c!=a)
        {
               printf("Case %d: Scalene\n",i+1);
        }

    }
    return 0;
}
