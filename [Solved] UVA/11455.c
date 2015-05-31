#include <stdio.h>

int sort( long long *a,long long *b,long long *c,long long *d )
{
    int i,j,m[4],temp;
    m[0]=*a,m[1]=*b,m[2]=*c,m[3]=*d;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3-i;j++)
        {
            if(m[j]>m[j+1])
            {
                temp=m[j];
                m[j]=m[j+1];
                m[j+1]=temp;
            }
        }
    }
    *a=m[0];
    *b=m[1];
    *c=m[2];
    *d=m[3];
}

main()
{
    int t,i;
    long long a,b,c,d;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        sort(&a,&b,&c,&d);
        if(d>=(a+b+c))
        {
            printf("banana\n");
        }
        else
        {
            if(a==d)
            {
                printf("square\n");
            }
            else if(a==b && c==d && a!=d)
            {
                printf("rectangle\n");
            }
            else
            {
                printf("quadrangle\n");
            }
        }
    }
    return 0;
}
