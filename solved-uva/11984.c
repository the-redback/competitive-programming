#include <stdio.h>

main()
{
    float far,cel;
    int a,b,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        if(0<=a && b<=100)
        {
        far=((9*a)/5.0)+32;
        far=far+b;
        cel=((far-32)*5.0)/9.0;
        printf("Case %d: %.2f\n",i+1,cel);
        }
    }
    return 0;
}
