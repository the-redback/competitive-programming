#include <stdio.h>

int gcd(int a, int b)
{
    int r,i,j,max,min;


    if(a>b)
    {
        max=a;
        min=b;
    }
    else
    {
        max=b;
        min=a;
    }

    if(min==0)
    {
        return max;
    }


    else
    {


    while(max%min!=0)
    {
        r=max%min;
        max=min;
        min=r;
    }

    return min;
    }


}

main()
{
    int i,j,k,n,g;

    for(k=0;k<100;k++)
    {
        scanf("%d",&n);
        g=0;
        if(n==0)
        {
            break;
        }
        else
        {
            for(i=1;i<n;i++)
            {
                for(j=i+1;j<=n;j++)
                {

                    g+=gcd(i,j);
                }
            }

        }
        printf("%d\n",g);

    }
    return 0;
}
