#include <stdio.h>
#include <string.h>

main()
{
    int n,m,p,i,j,l;
    scanf("%d %d %d",&p,&n,&m);
        for(i=0;i<=9;i++)
        {
            if((p*10+i)%n==0)
            {
                p=p*10+i;
                break;
            }
        }
        if(i==10)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d",p);
            m--;
            for(i=0;i<m;i++)
            {
                printf("0");
            }
            printf("\n");
        }
    return 0;
}
