#include <stdio.h>

main()
{
    long m,n,a,b;

    int i,j,l,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld %ld",&m,&n);
        a=m/(n*2);
        a=a*(n*n);
        printf("Case %d: %ld\n",i,a);
    }
    return 0;
}
