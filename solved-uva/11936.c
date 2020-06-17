#include <stdio.h>

main()
{
    int a,b,c,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a>=b+c || b>=a+c|| c>=a+b)
        {
            printf("Wrong!!\n");
        }
        else
        {
            printf("OK\n");
        }
    }
    return 0;
}
