#include <stdio.h>

int fact(int n)
{
    int i,j,k,a[1001];
    a[0]=1;
    a[1]=1;
    for(i=2;i<=n;i++)
    {
        a[i]=i*a[i-1];

    }
    return a[n];
}

main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        if(a<=0)
        {
            if(a%2==0)
            {
                printf("Underflow!\n");
            }
            else if(a%2!=0)
            {
                printf("Overflow!\n");
            }
        }

        else if(a==13)
        {
            printf("6227020800\n");
        }
        else if(a>=8 && a<13)
        {
            printf("%d\n",fact(a));
        }
        else if(a<8 && a>0)
        {
            printf("Underflow!\n");
        }
        else if(a>13)
        {
            printf("Overflow!\n");
        }
    }
    return 0;
}
