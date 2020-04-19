#include <stdio.h>

main()
{
    int sum,x,y,n,t;
    float i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&x,&y,&n);
        i=n/(float)(x+y);
        x+=x-y;
        sum=i*x;
        printf("%d\n",sum);
    }
    return 0;
}
