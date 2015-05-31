#include <stdio.h>
#include <math.h>

main()
{
    float n,a,b,c,p,q;
    int i=0;
    while(scanf("%f%f%f%f",&n,&a,&b,&c)!=EOF)
    {
        i++;
        if(n==0 || a==0 || b==0 || c==0)
        {
            break;
        }
        else if(n==1)
        {
            q=(b-a)/c;
            p=(a*c)+(q*c*c)/2;
            printf("Case %d: %.3f %.3f\n",i,p,q);
        }
        else if(n==2)
        {
            q=(b-a)/c;
            p=a*q+(c*q*q)/2;
            printf("Case %d: %.3f %.3f\n",i,p,q);
        }
        else if(n==3)
        {
            p=sqrt(a*a+2*b*c);
            q=(p-a)/b;
            printf("Case %d: %.3f %.3f\n",i,p,q);
        }
        else if(n==4)
        {
            p=sqrt(a*a-2*b*c);
            q=(a-p)/b;
            printf("Case %d: %.3f %.3f\n",i,p,q);
        }
    }
    return 0;
}
