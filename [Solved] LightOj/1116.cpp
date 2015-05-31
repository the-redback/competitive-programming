#include <stdio.h>
#include <math.h>
main()
{
    long long n,m,a,b;
    int i,it,t,j;
    scanf("%d",&t);
    for(it=1;it<=t;it++)
    {
        j=0;
        scanf("%lld",&a);
        b=sqrt(a)+2;
        for(i=1;i<40;i++)
        {
            m=pow(2,i);
            n=a/m;
            if(n%2==1)
            {
                if(n*m==a)
                {
                    printf("Case %d: %lld %lld\n",it,n,m);
                    j++;
                    break;
                }
            }
        }
        if(j==0)
        {
            printf("Case %d: Impossible\n",it);
        }
    }
    return 0;
}
