#include <stdio.h>
#include <math.h>
main()
{
    long n,a,b,c;
    double d;
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld %ld",&a,&b);
        n=b-a+1;
        d=n;
        c=ceil(d/3);
        c=n-c;
       if(b-a==0)
        {
            if( a%3==0 || a%3!=0 && (a+1)%3==0)
            c=1;
            else
            c=0;

        }
        else if(b-a==1)
        {
            if(a%3!=0 && (a+1)%3==0)
            c=2;
            else
            c=1;
        }
        else if(a%3!=0 && (a+1)%3==0 && b%3!=0 && (b+1)%3==0 )
        c++;
        else if(a%3==0 && b%3==0)
        c++;
        else if(a%3!=0 && (a+1)%3==0 && b%3==0)
        c++;

        printf("Case %d: %ld\n",i,c);
    }
    return 0;
}
