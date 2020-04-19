#include <stdio.h>
#include <math.h>

main()
{
    long long n,a,b,c;
    int i,j,t,col,row;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        a=sqrt(n);
        b=a*a;
        if(b==n)
        {
            if(a%2==0)
            {
                row=1;
                col=a;
            }
            else
            {
                row=a;
                col=1;
            }
        }
        else
        {
            if(a%2==0)
            {
                c=n-b;
                if(n==(b+a+1))
                {
                    a++;
                    row=a;
                    col=a;
                }
                else if(n>(b+a))
                {
                    a++;
                    b=b+a;
                    row=a;
                    col=a-(n-b);
                }
                else
                {
                    a++;
                    b=b+1;
                    col=a;
                    row=n-b+1;
                }
            }
            else
            {
                if(n==(b+a+1))
                {
                    a++;
                    col=a;
                    row=a;
                }
                else if(n>(b+a))
                {
                    a++;
                    b=b+a;
                    col=a;
                    row=a-(n-b);
                }
                else
                {
                    a++;
                    b=b+1;
                    row=a;
                    col=(n-b)+1;
                }
            }
        }
        printf("Case %d: %d %d\n",i,col,row);
    }
    return 0;
}
