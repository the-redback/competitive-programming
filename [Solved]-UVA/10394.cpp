#include <stdio.h>

int const max=18410011;
int const min=100001;
int a[max];
long long b[min];

main()
{
    int i,j,n;
    for(i=3;i<=max;i++)
    {
        a[i]=1;
    }
    for(i=2;i<=max;i+=2)
        a[i]=0;
    for(i=3;i*i<=max;i+=2)
    {
        if(a[i]==1)
        for(j=i*i;j<=max;j+=i)
        a[j]=0;
    }
    for(i=3;i<18410000;i+=2)
    {
        if(a[i]==1 && a[i+2]!=1)
        a[i]=0;
    }
    j=1;
    for(i=3;i<18410000;i+=2)
    {
        if(a[i]==1)
        {
            b[j]=i;
            j++;
        }
    }
    while(scanf("%d",&n)==1)
    {
        printf("(%lld, %lld)\n",b[n],b[n]+2);
    }
    return 0;

}
