#include <stdio.h>
#include <math.h>
int i,j,l;

int check(int n)
{
    l=sqrt(n);
        for(i=1;i<=l;i++)
        {
            for(j=1;j<=l;j++)
            {
                if(j*j*j-i*i*i == n )
                {
                    return 1;
                }
            }
        }
        return 0;
}

main()
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        if(check (n) == 1)
        {
            printf("%d %d\n",j,i);
        }
        else if(check(n) == 0)
        {
            printf("No solution\n");
        }
    }
    return 0;
}
