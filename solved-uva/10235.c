#include <stdio.h>


int prime(int n)
{
    int i,j,k;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

main()
{
    int n,i,j,in;
    while(scanf("%d",&n)!=EOF)
    {
        if(prime(n)==1)
        {
            in=0;
            j=n;
            while(j>0)
            {
                i=j%10;
                j=j/10;
                in=(in*10)+i;
            }
            if(n!=in)
            {
                if(prime(in)==1)
                {
                    printf("%d is emirp.\n",n);
                }
                else
                {
                    printf("%d is prime.\n",n);
                }
            }
            else
                {
                    printf("%d is prime.\n",n);
                }
        }
        else
        {
            printf("%d is not prime.\n",n);
        }
    }
    return 0;
}
