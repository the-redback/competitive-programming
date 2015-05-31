#include <stdio.h>

int sum(int a[1000],int *c,int b[1000], int *d,int k[1000],int *p)
{
    int i,j;
    for(i=0,j=0;i<*c;i++,j++)
    {
        if(j<*d)
        {
            if(a[i]==1)
            {
                if(b[j]==0)
                {
                    k[i]=1;
                }
                else
                {
                    k[i]=0;
                }
            }
            else
            k[i]=b[j];
        }
        else
        k[i]=a[i];
    }
    *p=i;
}

main()
{
    long long n,m,total;
    int a[1000],b[1000],i,j,k[1000],l,c,d;
    while(scanf("%lld%lld",&n,&m)!=EOF)
   {
        for(i=0;n!=0;i++)
        {
            a[i]=n%2;
            n=n/2;
        }
        c=i;
        for(i=0;m!=0;i++)
        {
            b[i]=m%2;
            m=m/2;
        }
        d=i;
        if(c>d)
        {
            sum(a,&c,b,&d,k,&j);
        }
        else
        {
            sum(b,&d,a,&c,k,&j);
        }
        total=0;
        for(i=j-1;i>=0;i--)
        {
            total=total*2+k[i];
        }
        printf("%lld\n",total);
    }
    return 0;
}
