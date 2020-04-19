#include <stdio.h>
main()
{
    int test,i,j,n,a,b;

    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&a,&b);
        j=a+b;
        printf("Case %d: %d\n",i+1,j);
    }
    return 0;
}
